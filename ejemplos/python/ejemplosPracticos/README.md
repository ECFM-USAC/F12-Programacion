# Ejemplos Prácticos — NumPy · Pandas · Matplotlib · EDA

Serie de cuatro notebooks diseñados como guías autoguiadas para estudiantes con conocimientos básicos
de programación. Cada notebook combina explicación conceptual, ejemplos de código progresivos,
uso de ciclos `for` y condicionales aplicados a visualización y análisis, y ejercicios resueltos.

---

## Requisitos

### Ambiente conda (recomendado)

```bash
conda activate f12-progra1
```

### Verificar que las librerías estén instaladas

```bash
python -c "import numpy, pandas, matplotlib, seaborn; print('Todo OK')"
```

### Instalar desde cero (si no tienes el ambiente)

```bash
conda create -n f12-progra1 python=3.11
conda activate f12-progra1
conda install numpy pandas matplotlib seaborn jupyter jupyterlab
```

---

## Cómo ejecutar los notebooks

### Opción 1 — JupyterLab (recomendada)

```bash
conda activate f12-progra1
jupyter lab
```

Abre el navegador en `http://localhost:8888`. Navega a esta carpeta y abre el notebook que quieras.

### Opción 2 — Jupyter Notebook clásico

```bash
conda activate f12-progra1
jupyter notebook
```

### Opción 3 — VS Code

1. Abre la carpeta en VS Code
2. Instala la extensión **Jupyter** (Microsoft)
3. Selecciona el kernel `f12-progra1` en la esquina superior derecha del notebook
4. Ejecuta celdas con `Shift + Enter`

### Ejecutar todas las celdas de un notebook desde la terminal

```bash
conda activate f12-progra1
jupyter nbconvert --to notebook --execute 01_NumPy_Ejemplos.ipynb --output 01_NumPy_Ejemplos_ejecutado.ipynb
```

---

## Contenido de los notebooks

### `01_NumPy_Ejemplos.ipynb` — NumPy

**¿Para qué sirve NumPy?**
Permite trabajar con vectores, matrices y operaciones matemáticas de forma eficiente.
Es la base de Pandas, Matplotlib y casi toda la ciencia de datos en Python.

| Sección | Contenido |
|---|---|
| 1. ¿Por qué NumPy? | Comparación de velocidad: lista Python vs. array NumPy (con `time`) |
| 2. Crear arrays | `np.array`, `np.zeros`, `np.ones`, `np.arange`, `np.linspace` |
| 3. Propiedades | `.shape`, `.dtype`, `.ndim`, `.size` |
| 4. Indexación y slicing | Acceso 1D/2D, índices negativos, sub-matrices |
| 5. Operaciones vectorizadas | Suma, producto, potencia elemento a elemento (con equivalente en `for`) |
| 6. Indexación booleana | Filtrar con condiciones, `np.where` |
| 7. Broadcasting | Operaciones entre arrays de formas distintas |
| 8. Estadísticas | `mean`, `std`, `min`, `max`, `sum`, `cumsum` por eje |
| 9. Álgebra lineal | Producto matricial `@`, `np.linalg.solve`, determinante, norma |
| 10. Números aleatorios | `rng.integers`, `rng.normal`, `rng.choice`, simulación de dados |

**Ejercicios incluidos:**

- **Ejercicio 1 — Análisis de precipitaciones:** dado un array de precipitaciones mensuales para
  4 estaciones, calcular estadísticos por estación, normalizar datos y generar un reporte con un
  ciclo `for` que usa condicionales para clasificar cada estación como seca, normal o lluviosa.

- **Ejercicio 2 — Simulación de calificaciones:** simular notas de 30 estudiantes en 4 exámenes,
  asignar letra (A/B/C/D/F) con `if/elif`, calcular ranking y determinar el examen más difícil.

---

### `02_Pandas_Ejemplos.ipynb` — Pandas

**¿Para qué sirve Pandas?**
Pandas maneja datos tabulares (como una hoja de cálculo pero con código). Es el puente
entre los datos crudos y el análisis o modelado.

| Sección | Contenido |
|---|---|
| 1. ¿Por qué Pandas? | Comparación: lista de diccionarios vs. DataFrame |
| 2. Crear DataFrames | Desde diccionario, lista de diccionarios, CSV, NumPy array |
| 3. Inspección | `head`, `tail`, `info`, `describe`, `shape`, `dtypes` |
| 4. Selección | `df[col]`, `df[lista]`, `.loc`, `.iloc`, `.at` |
| 5. Filtrado | Máscaras booleanas, `&`, `|`, `~`, equivalente con ciclo `for` |
| 6. Agregar y modificar | Nueva columna, `apply`, `map`, operaciones vectorizadas |
| 7. Manejo de nulos | `isnull`, `dropna`, `fillna` con media/mediana/moda |
| 8. GroupBy | Split → Apply → Combine, `agg`, iteración sobre grupos con `for` |
| 9. Merge / Join | `inner`, `left`, `right`, `outer`, `pd.concat` |
| 10. Ordenamiento | `sort_values`, `rank` |
| 11. `pd.cut` / `pd.qcut` | Crear categorías a partir de variables numéricas |
| 12. Series de tiempo | `pd.to_datetime`, `resample`, `rolling` |

**Ejercicios incluidos:**

- **Ejercicio 1 — Análisis de notas:** cargar un DataFrame de estudiantes, calcular promedio
  ponderado, asignar estado académico con `pd.cut`, encontrar el mejor y peor estudiante,
  y hacer un resumen por carrera con `groupby`.

- **Ejercicio 2 — Limpieza de datos:** recibir un DataFrame con duplicados, valores fuera de
  rango y NaN, aplicar limpieza paso a paso con ciclos `for` y condicionales, e imputar nulos.

---

### `03_Matplotlib_Ejemplos.ipynb` — Matplotlib y Seaborn

**¿Para qué sirve Matplotlib?**
Crea cualquier tipo de gráfica con control total sobre cada detalle visual.
Seaborn simplifica gráficas estadísticas complejas y se integra directamente con DataFrames.

| Sección | Tipo de gráfica | ¿Cuándo usarla? |
|---|---|---|
| 1. Líneas | `ax.plot` | Series de tiempo, funciones matemáticas, tendencias |
| 2. Scatter | `ax.scatter` | Relación entre dos variables numéricas, correlación |
| 3. Barras | `ax.bar` / `ax.barh` | Comparar valores entre categorías |
| 4. Histograma | `ax.hist` / `sns.histplot` | Distribución de una variable continua |
| 5. Boxplot | `ax.boxplot` / `sns.violinplot` | Distribución + outliers por grupo |
| 6. Heatmap | `sns.heatmap` | Matrices, tablas de correlación, pivotes |
| 7. Subplots | `plt.subplots` + `GridSpec` | Paneles múltiples, dashboards |
| 8. Personalización | Anotaciones, estilos, `spines` | Presentaciones y publicaciones |
| 9. Seaborn estadístico | `sns.barplot`, `pairplot` | EDA rápido con DataFrames |

**Conceptos de programación destacados:**

- Ciclo `for` para graficar múltiples series sin repetir código
- Ciclo `for` para generar cuadrículas de subplots automáticamente
- Condicionales para asignar colores según umbral (aprobado/reprobado, por categoría)
- Construcción de barras agrupadas iterando sobre un diccionario

**Ejercicios incluidos:**

- **Ejercicio 1 — Dashboard de temperaturas:** panel de 4 gráficas (`GridSpec`) que combina
  líneas por ciudad (ciclo `for`), histogramas superpuestos, boxplot comparativo y barras
  con color condicional (rojo/azul según umbral de temperatura).

- **Ejercicio 2 — Reporte visual de notas:** perfil de notas de 5 estudiantes con gráfica de
  líneas por estudiante (ciclo `for` con anotación de cada punto) y barras con 3 niveles
  de color (verde/amarillo/rojo), más identificar al mejor estudiante en texto.

---

### `04_EDA_Ejemplos.ipynb` — Análisis Exploratorio de Datos (EDA)

**¿Qué es el EDA?**
Proceso sistemático para conocer un dataset antes de construir modelos o tomar decisiones.
El notebook muestra el flujo completo de un EDA real con un dataset de 300 estudiantes.

| Sección | Contenido |
|---|---|
| 1. Generación del dataset | `np.random`, introducción intencional de nulos, duplicados y correlaciones |
| 2. Primera inspección | `shape`, `info`, `describe`, `head` — preguntas básicas del EDA |
| 3. Calidad de datos | Nulos (cuántos, dónde, qué hacer), duplicados, verificación de rangos |
| 4. Análisis univariado | Frecuencias de categóricas, histogramas + KDE de numéricas, tabla de estadísticos |
| 5. Outliers | Método IQR, boxplot con puntos atípicos marcados |
| 6. Análisis bivariado | Correlación de Pearson, heatmap, scatter por materia, boxplot por carrera |
| 7. Análisis multivariado | Pairplot coloreado por carrera, heatmap de tabla pivote |
| 8. Ingeniería de features | `pd.cut`, `pd.qcut`, promedio general, eficiencia, indicador binario |
| 9. Imputación | Mediana por grupo (`transform`), moda global |
| 10. Resumen final | Reporte automático de hallazgos generado con ciclos `for` |

**Conceptos de programación destacados:**

- Ciclo `for` para verificar rangos válidos de múltiples columnas con reporte ✓/✗
- Ciclo `for` para calcular y construir tabla de estadísticos columna por columna
- Ciclo `for` para detectar outliers IQR en todas las variables numéricas
- Condicionales para asignar nivel de gravedad a los nulos (naranja/rojo)
- Condicionales para interpretar la correlación (fuerte/moderada/débil)

**Ejercicios incluidos:**

- **Ejercicio 1 — EDA de ventas:** dataset de 5 productos × 12 meses con valores nulos;
  detección de nulos con ciclo `for`, imputación por mediana, gráfica de líneas multi-producto,
  barras con 3 niveles de color (verde/amarillo/rojo por total anual), mejor mes por producto.

- **Ejercicio 2 — EDA comparativo:** tres grupos de presión arterial (Control, Tratamiento A/B);
  estadísticos por grupo, histogramas superpuestos, boxplot comparativo, barras con color
  condicional por nivel de riesgo clínico, detección de outliers y conclusión automática.

---

## Dependencias

| Librería | Versión mínima | Uso |
|---|---|---|
| `numpy` | ≥ 1.24 | Arrays, álgebra lineal, números aleatorios |
| `pandas` | ≥ 2.0 | DataFrames, lectura/escritura de datos |
| `matplotlib` | ≥ 3.7 | Gráficas base (líneas, barras, histogramas, scatter) |
| `seaborn` | ≥ 0.13 | Gráficas estadísticas (histplot kde, violinplot, heatmap) |
| `jupyter` / `jupyterlab` | cualquiera | Entorno de ejecución de notebooks |

---

## Notas para el estudiante

- Ejecuta las celdas **en orden** de arriba hacia abajo. Muchas celdas dependen de variables
  definidas en celdas anteriores.
- Si una celda da error, revisa que hayas ejecutado todas las celdas anteriores.
- Los ejercicios tienen dos celdas: una para tu intento y otra con la solución completa.
  **Intenta resolverlo antes de ver la solución.**
- Los comentarios con `# ===` en el código marcan las partes más importantes conceptualmente.
- Para reiniciar un notebook desde cero: **Kernel → Restart & Run All**.
