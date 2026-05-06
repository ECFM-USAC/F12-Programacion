"""
temperature_processor.py
Pipeline de carga, limpieza y preparación de datos de temperatura global
para su uso en modelos de machine learning.
"""

import pandas as pd
import numpy as np
from pathlib import Path


# Temperatura absoluta mensual de referencia (°C), período 1951-1980
TEMP_ABS_REF = {
    1: 12.31, 2: 12.52, 3: 13.15, 4: 14.07,
    5: 15.01, 6: 15.68, 7: 15.91, 8: 15.72,
    9: 15.17, 10: 14.30, 11: 13.33, 12: 12.59
}
MEDIA_GLOBAL_REF = 14.148  # °C


class TemperatureLoader:
    """Carga y valida el archivo CSV de temperatura global de Berkeley Earth."""

    EXPECTED_COLS = 12  # número de columnas esperadas

    COLUMN_MAP = {
        'Year':                 'year',
        'Month':                'month',
        'Month Anomaly':        'anomaly_monthly',
        'Month Unc.':           'unc_monthly',
        'Annual Anomaly':       'anomaly_annual',
        'Annual Unc.':          'unc_annual',
        'Five-year Anomaly':    'anomaly_5yr',
        'Five-year Unc.':       'unc_5yr',
        'Ten-year Anomaly':     'anomaly_10yr',
        'Ten-year Unc.':        'unc_10yr',
        'Twenty-year Anomaly':  'anomaly_20yr',
        'Twenty-year Unc.':     'unc_20yr',
        # variante alternativa en el segundo archivo
        'Monthly Anomaly':      'anomaly_monthly',
        'Monthly Unc.':         'unc_monthly',
        'Annual Unc':           'unc_annual',
        'Five-Year Anomaly':    'anomaly_5yr',
        'Five-Year Unc.':       'unc_5yr',
        'Ten-Year Anomaly':     'anomaly_10yr',
        'Ten-Year Unc.':        'unc_10yr',
        'Twenty-Year Anomaly':  'anomaly_20yr',
        'Twenty-year Unc.':     'unc_20yr',
    }

    def __init__(self, filepath: str | Path):
        self.filepath = Path(filepath)
        self._df_raw: pd.DataFrame | None = None

    def load(self) -> pd.DataFrame:
        """Carga el CSV, normaliza nombres de columnas y convierte str→float."""
        if not self.filepath.exists():
            raise FileNotFoundError(f'No se encontró el archivo: {self.filepath}')

        self._df_raw = pd.read_csv(self.filepath)
        self._df_raw.columns = self._df_raw.columns.str.strip()

        self._validate()
        self._df_raw = self._df_raw.rename(columns=self.COLUMN_MAP)

        # El CSV almacena NaN con espacios (ej. '      NaN') → pandas los lee como str.
        # str.strip() + to_numeric(..., errors='coerce') los convierte a float/np.nan.
        str_cols = self._df_raw.select_dtypes(include='object').columns
        for col in str_cols:
            self._df_raw[col] = pd.to_numeric(self._df_raw[col].str.strip(), errors='coerce')

        return self._df_raw.copy()

    def _validate(self) -> None:
        """Verifica que el archivo tiene la estructura esperada."""
        if self._df_raw.shape[1] != self.EXPECTED_COLS:
            raise ValueError(
                f'Se esperaban {self.EXPECTED_COLS} columnas, '
                f'se encontraron {self._df_raw.shape[1]}.'
            )
        required = {'Year', 'Month'}
        missing = required - set(self._df_raw.columns)
        if missing:
            raise ValueError(f'Columnas requeridas no encontradas: {missing}')

    @property
    def raw(self) -> pd.DataFrame:
        if self._df_raw is None:
            raise RuntimeError('Llama a load() primero.')
        return self._df_raw


class TemperaturePreprocessor:
    """Limpia el DataFrame y construye la columna de fecha."""

    def __init__(self, temp_abs_ref: dict = TEMP_ABS_REF):
        self.temp_abs_ref = temp_abs_ref

    def fit_transform(self, df: pd.DataFrame) -> pd.DataFrame:
        """Aplica toda la limpieza y devuelve el DataFrame procesado."""
        df = df.copy()
        df = self._build_date_index(df)
        df = self._add_absolute_temperature(df)
        df = self._add_decade(df)
        return df

    def _build_date_index(self, df: pd.DataFrame) -> pd.DataFrame:
        """Crea columna 'date' y la usa como índice."""
        df['date'] = pd.to_datetime(df[['year', 'month']].assign(day=1))
        return df.set_index('date').sort_index()

    def _add_absolute_temperature(self, df: pd.DataFrame) -> pd.DataFrame:
        """Suma la anomalía mensual a la temperatura de referencia del mes."""
        df['temp_abs'] = df['month'].map(self.temp_abs_ref) + df['anomaly_monthly']
        return df

    def _add_decade(self, df: pd.DataFrame) -> pd.DataFrame:
        df['decade'] = (df['year'] // 10) * 10
        return df

    def get_null_summary(self, df: pd.DataFrame) -> pd.DataFrame:
        """Retorna un resumen de valores nulos por columna."""
        nulos = df.isnull().sum()
        pct = (nulos / len(df) * 100).round(2)
        return pd.DataFrame({'nulos': nulos, 'porcentaje': pct})


class TemperatureFeatureEngineer:
    """
    Construye features para modelos de machine learning sobre series de tiempo.

    Features generadas:
    - Codificación cíclica del mes (sin/cos)
    - Features de lag (valores pasados de la anomalía)
    - Medias móviles calculadas sobre anomaly_monthly
    - Tendencia lineal normalizada
    """

    def __init__(self, lag_steps: list[int] = None, rolling_windows: list[int] = None):
        self.lag_steps = lag_steps or [1, 2, 3, 6, 12]
        self.rolling_windows = rolling_windows or [12, 60, 120]

    def fit_transform(self, df: pd.DataFrame) -> pd.DataFrame:
        df = df.copy()
        df = self._encode_month_cyclic(df)
        df = self._add_lag_features(df)
        df = self._add_rolling_features(df)
        df = self._add_linear_trend(df)
        return df

    def _encode_month_cyclic(self, df: pd.DataFrame) -> pd.DataFrame:
        """
        Codifica el mes como par (sin, cos) para preservar su naturaleza cíclica.
        Mes 1 y mes 12 son contiguos en el calendario, y esta codificación lo refleja.
        """
        df['month_sin'] = np.sin(2 * np.pi * df['month'] / 12)
        df['month_cos'] = np.cos(2 * np.pi * df['month'] / 12)
        return df

    def _add_lag_features(self, df: pd.DataFrame) -> pd.DataFrame:
        """Crea columnas de valores rezagados (lag) de la anomalía mensual."""
        for lag in self.lag_steps:
            df[f'anomaly_lag_{lag}'] = df['anomaly_monthly'].shift(lag)
        return df

    def _add_rolling_features(self, df: pd.DataFrame) -> pd.DataFrame:
        """Calcula medias móviles sobre la anomalía mensual."""
        for w in self.rolling_windows:
            df[f'rolling_mean_{w}m'] = (
                df['anomaly_monthly'].rolling(window=w, min_periods=w//2).mean()
            )
        return df

    def _add_linear_trend(self, df: pd.DataFrame) -> pd.DataFrame:
        """
        Agrega un feature de tendencia temporal normalizado al rango [0, 1].
        Útil para modelos que no capturan tendencia por sí mismos.
        """
        t = np.arange(len(df), dtype=float)
        df['trend'] = t / t.max()
        return df

    @property
    def feature_columns(self) -> list[str]:
        """Lista de columnas generadas por este transformador."""
        cols = ['month_sin', 'month_cos', 'trend']
        cols += [f'anomaly_lag_{l}' for l in self.lag_steps]
        cols += [f'rolling_mean_{w}m' for w in self.rolling_windows]
        return cols


class TemperatureScaler:
    """
    Estandariza columnas numéricas a media 0 y desviación estándar 1.
    Implementación manual para mostrar el concepto sin dependencias externas.
    """

    def __init__(self):
        self._means: dict[str, float] = {}
        self._stds: dict[str, float] = {}
        self._fitted = False

    def fit(self, df: pd.DataFrame, columns: list[str]) -> 'TemperatureScaler':
        for col in columns:
            self._means[col] = df[col].mean()
            self._stds[col] = df[col].std()
        self._fitted = True
        return self

    def transform(self, df: pd.DataFrame) -> pd.DataFrame:
        if not self._fitted:
            raise RuntimeError('Llama a fit() antes de transform().')
        df = df.copy()
        for col, mean in self._means.items():
            std = self._stds[col]
            df[col] = (df[col] - mean) / (std if std > 0 else 1.0)
        return df

    def fit_transform(self, df: pd.DataFrame, columns: list[str]) -> pd.DataFrame:
        return self.fit(df, columns).transform(df)

    def inverse_transform_column(self, col: str, values: np.ndarray) -> np.ndarray:
        """Recupera los valores originales (desnormalización)."""
        return values * self._stds[col] + self._means[col]

    @property
    def params(self) -> pd.DataFrame:
        return pd.DataFrame({'mean': self._means, 'std': self._stds})


class TemperaturePipeline:
    """
    Orquesta el flujo completo:
      1. Carga → TemperatureLoader
      2. Preprocesamiento → TemperaturePreprocessor
      3. Feature engineering → TemperatureFeatureEngineer
      4. Escalado → TemperatureScaler
      5. División temporal train/test
    """

    TARGET_COL = 'anomaly_monthly'

    def __init__(
        self,
        filepath: str | Path,
        test_year_start: int = 2000,
        lag_steps: list[int] = None,
        rolling_windows: list[int] = None,
    ):
        self.filepath = filepath
        self.test_year_start = test_year_start

        self.loader = TemperatureLoader(filepath)
        self.preprocessor = TemperaturePreprocessor()
        self.feature_engineer = TemperatureFeatureEngineer(lag_steps, rolling_windows)
        self.scaler = TemperatureScaler()

        self._df_processed: pd.DataFrame | None = None
        self._df_features: pd.DataFrame | None = None

    def run(self) -> dict[str, pd.DataFrame]:
        """
        Ejecuta el pipeline completo.

        Returns
        -------
        dict con claves: 'X_train', 'X_test', 'y_train', 'y_test', 'df_full'
        """
        raw = self.loader.load()
        processed = self.preprocessor.fit_transform(raw)
        with_features = self.feature_engineer.fit_transform(processed)

        # Eliminar filas con NaN en las features o en el target
        feature_cols = self.feature_engineer.feature_columns
        cols_needed = feature_cols + [self.TARGET_COL]
        df_clean = with_features.dropna(subset=cols_needed)

        self._df_processed = processed
        self._df_features = df_clean

        # División temporal respetando el orden cronológico
        train_mask = df_clean['year'] < self.test_year_start
        test_mask = df_clean['year'] >= self.test_year_start

        X_train = df_clean.loc[train_mask, feature_cols]
        X_test = df_clean.loc[test_mask, feature_cols]
        y_train = df_clean.loc[train_mask, self.TARGET_COL]
        y_test = df_clean.loc[test_mask, self.TARGET_COL]

        # Escalar features usando solo estadísticas del entrenamiento
        X_train_scaled = self.scaler.fit_transform(X_train, feature_cols)
        X_test_scaled = self.scaler.transform(X_test)

        print(self._summary(X_train_scaled, X_test_scaled, y_train, y_test))

        return {
            'X_train': X_train_scaled,
            'X_test': X_test_scaled,
            'y_train': y_train,
            'y_test': y_test,
            'df_full': df_clean,
        }

    def _summary(self, X_train, X_test, y_train, y_test) -> str:
        lines = [
            '=== TemperaturePipeline — Resumen ===',
            f'  Archivo     : {self.filepath}',
            f'  Corte train : año < {self.test_year_start}',
            f'  Train       : {len(X_train):>5} muestras  '
            f'  ({y_train.index.min().year}–{y_train.index.max().year})',
            f'  Test        : {len(X_test):>5} muestras  '
            f'  ({y_test.index.min().year}–{y_test.index.max().year})',
            f'  Features    : {len(X_train.columns)} columnas',
            f'  Target      : {self.TARGET_COL}',
        ]
        return '\n'.join(lines)

    @property
    def processed(self) -> pd.DataFrame:
        if self._df_processed is None:
            raise RuntimeError('Llama a run() primero.')
        return self._df_processed

    @property
    def features(self) -> pd.DataFrame:
        if self._df_features is None:
            raise RuntimeError('Llama a run() primero.')
        return self._df_features


# ---------------------------------------------------------------------------
# Uso rápido desde consola
# ---------------------------------------------------------------------------
if __name__ == '__main__':
    DATA_PATH = Path(__file__).parent / 'data' / 'Global Temperatures.csv'

    pipeline = TemperaturePipeline(DATA_PATH, test_year_start=2000)
    splits = pipeline.run()

    print('\nPrimeras filas de X_train:')
    print(splits['X_train'].head())
    print('\nEstadísticos de y_train:')
    print(splits['y_train'].describe())
