# Ejemplos de Python — F12 Programación

Colección de scripts y notebooks para el curso de Programación 1 (F12). Los ejemplos están
organizados por tema y van de lo más básico hasta aplicaciones con APIs científicas,
análisis exploratorio de datos y pipelines de machine learning.

---

## Estructura

```
ejemplos/python/
│
├── introduccion_python.py              # Fundamentos del lenguaje
├── fisica_basica.py                    # Módulo: funciones de física clásica
├── fisica_poo.py                       # Módulo: física con POO y herencia
├── algoritmos.py                       # Módulo: búsqueda y ordenamiento (generadores)
├── busqueda_visual.py                  # Visualizador interactivo con pygame
│
├── IntroduccionPython.ipynb            # Notebook: introducción a Python
├── HojaTrabajo_IntroduccionPython.ipynb  # Hoja de trabajo: ejercicios de introducción
├── Modulos.ipynb                       # Notebook: uso de módulos
├── Ordenamiento.ipynb                  # Notebook: algoritmos de ordenamiento
├── BigONotation.ipynb                  # Notebook: análisis de Big-O
├── BigONotation_logs.ipynb             # Notebook: Big-O con escala logarítmica
├── BusquedaDos.ipynb                   # Notebook: búsqueda 2 en 2
├── Numpy.ipynb                         # Notebook: NumPy completo
├── Aplicaciones_Numpy.ipynb            # Notebook: aplicaciones avanzadas de NumPy
├── Pandas.ipynb                        # Notebook: introducción a Pandas
├── Pandas_Merge.ipynb                  # Notebook: merge y joins en Pandas
├── MatplotlibSeaborn.ipynb             # Notebook: visualización de datos
├── XML_JSON_APIs.ipynb                 # Notebook: XML, JSON y APIs de NASA
├── XML_JSON_APIs_ISS_Interactivo.ipynb # Notebook: posición ISS interactiva
│
├── ejemplosPracticos/                  # ★ Guías autoguiadas para estudiantes
│   ├── 01_NumPy_Ejemplos.ipynb         #   NumPy: vectores, matrices, estadísticas
│   ├── 02_Pandas_Ejemplos.ipynb        #   Pandas: DataFrames, groupby, merge
│   ├── 03_Matplotlib_Ejemplos.ipynb    #   Matplotlib/Seaborn: 9 tipos de gráficas
│   └── 04_EDA_Ejemplos.ipynb          #   EDA completo con dataset de estudiantes
│
├── EDA/                                # Pipeline real de temperatura global
│   ├── 01_EDA_TemperaturaGlobal.ipynb  #   EDA con datos de Berkeley Earth
│   ├── 02_Preparacion_Modelo.ipynb     #   Feature engineering para ML
│   ├── temperature_processor.py        #   Pipeline OOP: Loader→Preprocessor→Scaler
│   └── data/                           #   Global Temperatures.csv (Berkeley Earth)
│
└── analisis_datos/                     # Proyecto completo con Poetry
    ├── pyproject.toml                  #   Dependencias (Poetry)
    ├── data/
    │   ├── stars.csv
    │   └── cneos_fireball_data.csv
    └── notebooks/
        └── analisis_estrellas.ipynb
```

---

## Requisitos generales

```bash
# Activar el ambiente conda del curso
conda activate f12-progra1

# Iniciar JupyterLab
jupyter lab
```

Si necesitas crear el ambiente desde cero:

```bash
conda create -n f12-progra1 python=3.11
conda activate f12-progra1
conda install numpy pandas matplotlib seaborn jupyter jupyterlab requests
```

Para el visualizador de algoritmos (`busqueda_visual.py`) se requiere `pygame`:

```bash
conda install -c conda-forge pygame
```

---

## Guía por tema

### 1. Introducción a Python — `introduccion_python.py`

Punto de entrada para quienes llegan por primera vez a Python.

| Sección | Temas cubiertos |
|---|---|
| Variables y tipos | `int`, `float`, `str`, `bool`, `None`, tipado dinámico |
| Operaciones | Aritméticas, módulo, potencia, `math` |
| Strings | `strip`, `upper`, `split`, `join`, f-strings |
| Listas | `append`, `insert`, `remove`, `pop`, `sorted` |
| Diccionarios | Acceso, `.get()`, `.items()`, iteración |
| Condicionales | `if / elif / else`, operador ternario |
| Ciclos | `for`, `while`, `range`, `enumerate`, list comprehension |
| Funciones | Argumentos por defecto, retorno múltiple, recursión |
| Errores | `try / except / finally`, `raise` |

```bash
python introduccion_python.py
```

El notebook `IntroduccionPython.ipynb` es la versión interactiva del mismo contenido.
La `HojaTrabajo_IntroduccionPython.ipynb` contiene ejercicios para practicar cada sección.

---

### 2. Módulos de física

#### `fisica_basica.py` — Funciones utilitarias

Módulo importable con constantes y funciones de física clásica:

- **Constantes:** `G` (gravedad), `C` (velocidad de la luz), `PI`
- **Cinemática:** `posicion`, `velocidad`, `tiempo_caida`
- **Energía:** `energia_cinetica`, `energia_potencial`, `energia_total`
- **Fuerzas:** `segunda_ley_newton`, `peso`
- **Circular:** `area_circulo`, `velocidad_angular`, `fuerza_centripeta`

```python
from fisica_basica import tiempo_caida, energia_cinetica
print(tiempo_caida(20))          # caída libre desde 20 m
print(energia_cinetica(5, 10))   # masa=5 kg, vel=10 m/s
```

#### `fisica_poo.py` — Programación Orientada a Objetos

Modela objetos físicos con herencia:

```
CuerpoFisico          ← clase base (nombre, masa, posición, velocidad)
├── Particula         ← agrega carga eléctrica
└── ObjetoRigido      ← agrega densidad y volumen (abstracto)
    ├── Esfera        ← V = (4/3)πr³
    └── Cubo          ← V = lado³
```

Conceptos demostrados: `__init__`, `super()`, herencia, polimorfismo, `__str__`, `NotImplementedError`.

---

### 3. Algoritmos de búsqueda y ordenamiento

#### `algoritmos.py`

Generadores que producen el estado visual paso a paso de cada algoritmo.

| Algoritmo | Complejidad | Función |
|---|---|---|
| Búsqueda lineal | O(n) | `busqueda_lineal` |
| Búsqueda 2 en 2 | O(n) | `busqueda_2en2` |
| Búsqueda binaria | O(log n) | `busqueda_binaria` |
| Burbuja | O(n²) | `ordenamiento_burbuja` |
| Selección | O(n²) | `ordenamiento_seleccion` |
| Quicksort | O(n log n) | `ordenamiento_quicksort` |
| Merge sort | O(n log n) | `ordenamiento_mergesort` |

#### `busqueda_visual.py` — Visualizador interactivo

Requiere `pygame`. Controles: `ESPACIO/→` avanzar, `A` auto-reproducción,
`1-7` cambiar algoritmo, `R` nueva lista, `Q` salir.

```bash
conda run -n f12-progra1 python3 busqueda_visual.py
conda run -n f12-progra1 python3 busqueda_visual.py --size 20 --min 1 --max 50
```

---

### 4. NumPy

#### `Numpy.ipynb` — Notebook completo

| Nivel | Temas |
|---|---|
| 1 — Básico | Arrays vs listas, constructores (`zeros`, `ones`, `arange`, `linspace`), arrays 2D |
| 2 — Indexación | Slicing, indexación booleana, broadcasting, ufuncs |
| 3 — Estadística | `mean`, `std`, `cumsum`, `reshape`, multiplicación matricial |
| 3b — Extras | Valores especiales, `np.where`, copiar, concatenar |
| 4 — Aplicado | Cálculo de notas ponderadas con matrices |

Incluye 5 ejercicios de práctica al final.

#### `Aplicaciones_Numpy.ipynb` — Aplicaciones avanzadas

Álgebra lineal, simulaciones y casos de uso científicos.

---

### 5. Pandas

#### `Pandas.ipynb` — Introducción

DataFrames, selección con `.loc`/`.iloc`, filtrado booleano, `groupby`, estadísticas descriptivas.

#### `Pandas_Merge.ipynb` — Merge y Joins

Tipos de join (`inner`, `left`, `right`, `outer`), `pd.merge`, `pd.concat`, índices.

---

### 6. Visualización — `MatplotlibSeaborn.ipynb`

Notebook de referencia para gráficas con Matplotlib y Seaborn:
líneas, scatter, barras, histogramas, boxplots, heatmaps, subplots y personalización.

---

### 7. XML, JSON y APIs científicas — `XML_JSON_APIs.ipynb`

| Sección | Contenido |
|---|---|
| XML | Estructura, parsing con `ElementTree` |
| JSON | Tipos, `json.loads`/`json.dumps` |
| Códigos HTTP | Tabla de códigos 2xx/4xx/5xx |
| APIs | Anatomía de una URL, librería `requests` |
| Variables de entorno | Guardar credenciales de forma segura |
| ISS | Posición en tiempo real (sin API key) |
| APOD | Imagen astronómica del día con reintentos |
| NEO | Asteroides cercanos a la Tierra |
| EONET | Eventos naturales activos + 3 ejercicios |

`XML_JSON_APIs_ISS_Interactivo.ipynb` muestra la posición de la ISS en un mapa interactivo con `folium`.

---

### 8. Ejemplos Prácticos — `ejemplosPracticos/` ★

Cuatro notebooks autoguiados para consolidar NumPy, Pandas, Matplotlib y EDA.
Diseñados para estudiantes con conocimientos básicos de programación.
Cada uno incluye explicación del concepto, casos de uso, ejemplos con ciclos y
condicionales, y 2 ejercicios resueltos.

| Notebook | Descripción |
|---|---|
| `01_NumPy_Ejemplos.ipynb` | Arrays, vectorización, broadcasting, estadísticas, álgebra lineal |
| `02_Pandas_Ejemplos.ipynb` | DataFrames, filtrado, groupby, merge, limpieza de datos |
| `03_Matplotlib_Ejemplos.ipynb` | 9 tipos de gráficas, dashboards con `for`, colores condicionales |
| `04_EDA_Ejemplos.ipynb` | Flujo completo de EDA: nulos, outliers, correlación, features |

Ver [`ejemplosPracticos/README.md`](ejemplosPracticos/README.md) para instrucciones detalladas.

---

### 9. EDA de Temperatura Global — `EDA/`

Pipeline completo con datos reales de temperatura global de Berkeley Earth (1850–presente).

| Archivo | Descripción |
|---|---|
| `01_EDA_TemperaturaGlobal.ipynb` | EDA completo: carga, limpieza, visualización, análisis temporal |
| `02_Preparacion_Modelo.ipynb` | Feature engineering para ML: lags, rolling means, codificación cíclica |
| `temperature_processor.py` | Pipeline OOP reutilizable con 5 clases |

#### Clases del pipeline OOP

```
TemperatureLoader       ← carga y valida el CSV, normaliza nombres de columnas
TemperaturePreprocessor ← construye índice de fecha, añade temperatura absoluta y décadas
TemperatureFeatureEngineer ← codificación cíclica del mes, lags, medias móviles, tendencia
TemperatureScaler       ← estandarización manual (media=0, std=1) con fit/transform
TemperaturePipeline     ← orquesta el flujo completo y divide en train/test temporal
```

```bash
# Ejecutar el pipeline desde consola
conda run -n f12-progra1 python3 EDA/temperature_processor.py
```

**Nota:** el archivo `data/Global Temperatures.csv` es el dataset de Berkeley Earth
(High-Resolution Global Surface Temperature). Debe estar en `EDA/data/` para que los
notebooks funcionen.

---

### 10. Proyecto de análisis de datos — `analisis_datos/`

Proyecto completo con **Poetry** para manejo de dependencias.

**Datasets incluidos:**
- `stars.csv` — catálogo de estrellas
- `cneos_fireball_data.csv` — bólidos registrados por la NASA (CNEOS)

```bash
cd analisis_datos
poetry install
poetry run jupyter lab
```
