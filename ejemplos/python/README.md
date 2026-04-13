# Ejemplos de Python — F12 Programación

Colección de scripts y notebooks para el curso de Programación 1 (F12). Los ejemplos están organizados por tema y van de lo más básico hasta aplicaciones con APIs científicas y librerías de análisis de datos.

---

## Estructura

```
ejemplos/python/
├── introduccion_python.py          # Fundamentos del lenguaje
├── fisica_basica.py                # Módulo: funciones de física clásica
├── fisica_poo.py                   # Módulo: física con POO y herencia
├── algoritmos.py                   # Módulo: búsqueda y ordenamiento (generadores)
├── busqueda_visual.py              # Visualizador interactivo con pygame
│
├── IntroduccionPython.ipynb        # Notebook: introducción a Python
├── HojaTrabajo_IntroduccionPython.ipynb  # Hoja de trabajo: ejercicios de introducción
├── Modulos.ipynb                   # Notebook: uso de módulos
├── Ordenamiento.ipynb              # Notebook: algoritmos de ordenamiento
├── BigONotation.ipynb              # Notebook: análisis de Big-O
├── BigONotation_logs.ipynb         # Notebook: Big-O con escala logarítmica
├── BusquedaDos.ipynb               # Notebook: búsqueda 2 en 2
├── Numpy.ipynb                     # Notebook: NumPy completo
├── Pandas.ipynb                    # Notebook: introducción a Pandas
├── MatplotlibSeaborn.ipynb         # Notebook: visualización de datos
├── XML_JSON_APIs.ipynb             # Notebook: XML, JSON y APIs de NASA
│
└── analisis_datos/                 # Proyecto completo de análisis de datos
    ├── pyproject.toml              # Dependencias (Poetry)
    ├── data/
    │   ├── stars.csv
    │   └── cneos_fireball_data.csv
    └── notebooks/
        └── analisis_estrellas.ipynb
```

---

## Guía por tema

### 1. Introducción a Python — `introduccion_python.py`

Punto de entrada ideal para quienes llegan por primera vez a Python.

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

**Cómo ejecutar:**
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

Generadores que producen el estado visual paso a paso de cada algoritmo. Usado por el visualizador y los notebooks.

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

Requiere entorno `f12-progra1` con `pygame`. Controles: `ESPACIO/→` avanzar, `A` auto-reproducción, `1-7` cambiar algoritmo, `R` nueva lista, `Q` salir.

```bash
conda run -n f12-progra1 python3 busqueda_visual.py
conda run -n f12-progra1 python3 busqueda_visual.py --size 20 --min 1 --max 50
```

---

### 4. NumPy — `Numpy.ipynb`

Notebook completo de NumPy organizado en niveles:

| Nivel | Temas |
|---|---|
| 1 — Básico | Arrays vs listas, constructores (`zeros`, `ones`, `arange`, `linspace`), arrays 2D |
| 2 — Indexación | Slicing, indexación booleana, operaciones aritméticas, broadcasting, ufuncs |
| 3 — Estadística | `mean`, `std`, `var`, `cumsum`, `reshape`, multiplicación matricial |
| 3b — Extras | Valores especiales (`nan`, `inf`), `np.where`, copiar arrays, concatenar |
| 4 — Aplicado | Cálculo de notas ponderadas con matrices |

Al final incluye 5 ejercicios de práctica.

---

### 5. XML, JSON y APIs científicas — `XML_JSON_APIs.ipynb`

Notebook que cubre formatos de datos e integración con APIs de la NASA.

| Sección | Contenido |
|---|---|
| XML | Estructura, parsing con `ElementTree`, ejemplo con datos de física |
| JSON | Tipos, `json.loads`/`json.dumps`, comparación con XML |
| Códigos HTTP | Tabla de códigos 2xx/4xx/5xx y 4 patrones de manejo de errores |
| APIs y endpoints | Qué es una API, anatomía de una URL, librería `requests` |
| Variables de entorno | Cómo guardar credenciales de forma segura en Linux/macOS/Windows |
| Ejemplo 1 — ISS | Posición en tiempo real (sin API key) |
| Ejemplo 2 — APOD | Imagen astronómica del día con reintentos y visualización |
| Ejemplo 3 — NEO | Asteroides cercanos a la Tierra, exploración con ciclos |
| Ejemplo 4 — EONET | Eventos naturales activos (incendios, tormentas, volcanes) + 3 ejercicios |

---

### 6. Notebooks de Jupyter

| Notebook | Descripción |
|---|---|
| `IntroduccionPython.ipynb` | Introducción interactiva al lenguaje |
| `HojaTrabajo_IntroduccionPython.ipynb` | Ejercicios prácticos de los 10 temas fundamentales |
| `Modulos.ipynb` | Crear e importar módulos propios |
| `Ordenamiento.ipynb` | Visualización y comparación de algoritmos |
| `BigONotation.ipynb` | Análisis de complejidad con gráficas |
| `BigONotation_logs.ipynb` | Big-O en escala logarítmica |
| `BusquedaDos.ipynb` | Búsqueda 2 en 2 paso a paso |
| `Numpy.ipynb` | NumPy completo con ejercicios |
| `Pandas.ipynb` | DataFrames, filtrado, agrupación y estadísticas |
| `MatplotlibSeaborn.ipynb` | Gráficas con Matplotlib y Seaborn |
| `XML_JSON_APIs.ipynb` | XML, JSON, códigos HTTP y APIs de NASA |

---

### 7. Proyecto de análisis de datos — `analisis_datos/`

Proyecto completo con **Poetry** para manejo de dependencias.

**Dependencias:** `numpy`, `pandas`, `matplotlib`, `seaborn`, `jupyter`

**Datasets incluidos:**
- `stars.csv` — catálogo de estrellas
- `cneos_fireball_data.csv` — bólidos registrados por la NASA (CNEOS)

```bash
cd analisis_datos
poetry install
poetry run jupyter lab
```

---

## Requisitos generales

```bash
# Con conda (recomendado)
conda activate f12-progra1
jupyter notebook

# Con pip
pip install requests numpy pandas matplotlib seaborn jupyter pygame
```

Para el visualizador de algoritmos se requiere `pygame`.  
Para `XML_JSON_APIs.ipynb` se requiere `requests`.
