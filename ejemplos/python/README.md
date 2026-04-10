# Ejemplos de Python — F12 Programación

Colección de scripts y notebooks para el curso de Programación 1 (F12). Los ejemplos están organizados por tema y van de lo más básico hasta aplicaciones con librerías científicas.

---

## Estructura

```
ejemplos/python/
├── introduccion_python.py      # Fundamentos del lenguaje
├── fisica_basica.py            # Módulo: funciones de física
├── fisica_poo.py               # Módulo: física con POO y herencia
├── algoritmos.py               # Módulo: búsqueda y ordenamiento (generadores)
├── busqueda_visual.py          # Visualizador interactivo con pygame
│
├── IntroduccionPython.ipynb    # Notebook: introducción a Python
├── Modulos.ipynb               # Notebook: uso de módulos
├── Ordenamiento.ipynb          # Notebook: algoritmos de ordenamiento
├── BigONotation.ipynb          # Notebook: análisis de Big-O
├── BigONotation_logs.ipynb     # Notebook: Big-O con escala logarítmica
├── BusquedaDos.ipynb           # Notebook: búsqueda 2 en 2
├── Numpy.ipynb                 # Notebook: introducción a NumPy
├── Pandas.ipynb                # Notebook: introducción a Pandas
├── MatplotlibSeaborn.ipynb     # Notebook: visualización de datos
│
└── analisis_datos/             # Proyecto completo de análisis de datos
    ├── pyproject.toml          # Dependencias (Poetry)
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

### 3. Notebooks de Jupyter

Abrir con `jupyter notebook` o `jupyter lab` desde el directorio `ejemplos/python/`.

| Notebook | Descripción |
|---|---|
| `IntroduccionPython.ipynb` | Versión interactiva de `introduccion_python.py` |
| `Modulos.ipynb` | Cómo crear e importar módulos propios (`fisica_basica`) |
| `Ordenamiento.ipynb` | Visualización y comparación de algoritmos de ordenamiento |
| `BigONotation.ipynb` | Análisis de complejidad con gráficas |
| `BigONotation_logs.ipynb` | Big-O con escala logarítmica |
| `BusquedaDos.ipynb` | Demostración detallada de búsqueda 2 en 2 |
| `Numpy.ipynb` | Arrays, operaciones vectorizadas, álgebra lineal |
| `Pandas.ipynb` | DataFrames, filtrado, agrupación y estadísticas |
| `MatplotlibSeaborn.ipynb` | Gráficas con Matplotlib y Seaborn |

---

### 4. Proyecto de análisis de datos — `analisis_datos/`

Proyecto completo que usa **Poetry** para manejo de dependencias.

**Dependencias:** `numpy`, `pandas`, `matplotlib`, `seaborn`, `jupyter`

**Datasets incluidos:**
- `stars.csv` — datos de estrellas
- `cneos_fireball_data.csv` — datos de bólidos registrados por la NASA (CNEOS)

**Configurar entorno:**
```bash
cd analisis_datos
poetry install
poetry run jupyter lab
```

**Notebook:** `notebooks/analisis_estrellas.ipynb`

---

## Requisitos generales

Para los scripts y notebooks fuera de `analisis_datos/`:

```bash
# Con conda
conda activate f12-progra1
jupyter notebook

# Con pip
pip install pygame numpy pandas matplotlib seaborn jupyter
```

Para el visualizador de algoritmos se requiere específicamente `pygame`.
