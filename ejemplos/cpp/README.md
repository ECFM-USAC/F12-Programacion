# Ejemplos de C++ — Programacion 1, ECFM

Ejemplos basicos de C++ organizados por tema. Cada archivo puede compilarse y ejecutarse de forma independiente.

## Requisitos

- `g++` con soporte para C++17
- Compilar: `g++ -std=c++17 -o <nombre> <archivo>.cpp`

---

## Ejemplos

### 01 — Hola Mundo
**Archivo:** `01_hola_mundo.cpp`

El programa mas sencillo posible. Muestra como incluir una biblioteca, definir `main()` e imprimir texto en pantalla con `std::cout`.

```bash
g++ -o hola_mundo 01_hola_mundo.cpp
./hola_mundo
```

---

### 02 — Imprimir Valores
**Archivo:** `02_imprimir_valores.cpp`

Declara variables de los tipos fundamentales (`int`, `double`, `char`, `bool`, `string`) y las imprime. Tambien muestra las operaciones aritmeticas basicas: suma, resta, multiplicacion, division entera y modulo.

| Tipo       | Ejemplo            | Uso tipico                  |
|------------|--------------------|-----------------------------|
| `int`      | `42`               | Contadores, indices         |
| `double`   | `3.14`             | Calculos con decimales      |
| `char`     | `'A'`              | Un solo caracter            |
| `bool`     | `true` / `false`   | Condiciones logicas         |
| `string`   | `"texto"`          | Cadenas de caracteres       |

```bash
g++ -o imprimir_valores 02_imprimir_valores.cpp
./imprimir_valores
```

---

### 03 — Leer Valores
**Archivo:** `03_leer_valores.cpp`

Lee datos del teclado usando `std::cin` (para valores simples) y `std::getline` (para lineas con espacios). Incluye el uso de `std::cin.ignore()` para limpiar el buffer antes de leer una linea completa.

```bash
g++ -o leer_valores 03_leer_valores.cpp
./leer_valores
```

**Diferencia clave:**
- `std::cin >> variable` — lee hasta el primer espacio o salto de linea
- `std::getline(std::cin, variable)` — lee la linea completa incluyendo espacios

---

### 04 — Condicionales
**Archivo:** `04_condicionales.cpp`

Muestra las tres formas de tomar decisiones en C++:

| Construccion       | Cuando usarla                                        |
|--------------------|------------------------------------------------------|
| `if / else if / else` | Rangos o condiciones complejas                    |
| `? :` (ternario)   | Asignacion simple basada en una condicion            |
| `switch`           | Comparar una variable contra valores exactos         |

```bash
g++ -o condicionales 04_condicionales.cpp
./condicionales
```

---

### 05 — Ciclos
**Archivo:** `05_ciclos.cpp`

Muestra los tres ciclos de C++ y las palabras clave `break` y `continue`:

| Ciclo       | Cuando usarlo                                              |
|-------------|------------------------------------------------------------|
| `for`       | Numero de repeticiones conocido de antemano                |
| `while`     | Repite mientras una condicion sea verdadera (puede no ejecutarse) |
| `do-while`  | Como `while` pero garantiza al menos una ejecucion         |

- **`break`** — termina el ciclo inmediatamente
- **`continue`** — salta a la siguiente iteracion

```bash
g++ -o ciclos 05_ciclos.cpp
./ciclos
```

---

### 06 — Leer una Lista
**Archivo:** `06_leer_lista.cpp`

Lee `N` numeros del usuario en un arreglo (`double lista[N]`) y calcula el maximo, minimo, suma y promedio recorriendo el arreglo con un ciclo `for`.

```bash
g++ -o leer_lista 06_leer_lista.cpp
./leer_lista
```

**Conceptos cubiertos:**
- Declarar arreglos con tamano constante (`const int TAMANO`)
- Acceder a elementos por indice (`lista[i]`)
- Recorrer un arreglo completo
- Acumular resultados dentro de un ciclo

---

## Orden sugerido de estudio

```
01_hola_mundo
02_imprimir_valores
03_leer_valores
04_condicionales
05_ciclos
06_leer_lista
```

Cada ejemplo construye sobre los anteriores: los condicionales y ciclos asumen que ya sabes declarar variables y leer datos del teclado.
