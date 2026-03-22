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

### 07 — Funciones
**Archivo:** `07_funciones.cpp`

Muestra como definir y llamar funciones con parametros y valor de retorno.
Incluye prototipos (declaraciones previas), funciones `void` y funciones que retornan valores.

| Concepto       | Ejemplo                              |
|----------------|--------------------------------------|
| Prototipo      | `double area(double base, double h);` |
| Funcion void   | no retorna valor, solo ejecuta       |
| return         | devuelve el resultado al llamador    |

```bash
g++ -o funciones 07_funciones.cpp
./funciones
```

---

### 08 — Vectores (`std::vector`)
**Archivo:** `08_vectores.cpp`

Lista dinamica que puede crecer o reducirse en tiempo de ejecucion.
A diferencia de los arreglos, no necesitas saber el tamano de antemano.

| Operacion         | Metodo          |
|-------------------|-----------------|
| Agregar al final  | `push_back(x)`  |
| Eliminar el ultimo| `pop_back()`    |
| Tamano actual     | `size()`        |
| Primer/ultimo     | `front()`, `back()` |

```bash
g++ -std=c++17 -o vectores 08_vectores.cpp
./vectores
```

---

### 09 — Cadenas de texto (`std::string`)
**Archivo:** `09_strings.cpp`

Operaciones fundamentales sobre cadenas: longitud, concatenacion, busqueda de subcadenas,
extraccion con `substr` y conversion de mayusculas/minusculas.

```bash
g++ -std=c++17 -o strings 09_strings.cpp
./strings
```

---

### 10 — Matrices (arreglos 2D)
**Archivo:** `10_matrices.cpp`

Declara una matriz con `int m[FILAS][COLUMNAS]`, la recorre con dos ciclos `for`
anidados y calcula la suma de cada fila y la traza de la diagonal principal.

```bash
g++ -o matrices 10_matrices.cpp
./matrices
```

---

### 11 — Clases Basico
**Archivo:** `11_clases_basico.cpp`

Introduce el concepto de clase: como agrupar datos (atributos) y comportamiento (metodos) en una sola unidad, y como crear objetos independientes a partir de una misma plantilla.

| Concepto      | Descripcion                                      |
|---------------|--------------------------------------------------|
| `class`       | Define la plantilla del objeto                   |
| `public:`     | Sección accesible desde fuera de la clase        |
| Atributo      | Variable que pertenece al objeto (`ancho`, `alto`) |
| Metodo        | Funcion que pertenece a la clase (`area()`)      |
| Objeto        | Instancia concreta creada con `NombreClase var;` |

```bash
g++ -o clases_basico 11_clases_basico.cpp
./clases_basico
```

---

### 12 — Constructores y Destructores
**Archivo:** `12_constructores.cpp`

Muestra como inicializar objetos automaticamente al crearlos usando constructores (por defecto y con parametros), y el destructor que se ejecuta al final del ciclo de vida del objeto.

| Concepto               | Descripcion                                           |
|------------------------|-------------------------------------------------------|
| Constructor por defecto | Se llama cuando no se pasan argumentos               |
| Constructor con params  | Inicializa el objeto con valores especificos          |
| Lista de inicializacion | `Clase(params) : atrib(val) {}` — forma mas eficiente |
| Destructor `~Clase()`   | Se ejecuta automaticamente al salir del scope         |

```bash
g++ -o constructores 12_constructores.cpp
./constructores
```

---

### 13 — Encapsulacion
**Archivo:** `13_encapsulacion.cpp`

Demuestra como proteger los datos internos de una clase usando `private`, exponiendo solo lo necesario mediante getters, setters y metodos con validacion.

| Concepto   | Descripcion                                                   |
|------------|---------------------------------------------------------------|
| `private:` | Atributos solo accesibles dentro de la clase                  |
| `public:`  | Metodos que forman la interfaz del objeto                     |
| getter     | Metodo que devuelve el valor de un atributo (`getSaldo()`)    |
| setter     | Metodo que modifica un atributo con validacion                |

```bash
g++ -o encapsulacion 13_encapsulacion.cpp
./encapsulacion
```

---

### 14 — Herencia
**Archivo:** `14_herencia.cpp`

Muestra como una clase hija hereda atributos y metodos de una clase padre, puede agregar nuevos miembros propios, y como funciona la herencia en cadena.

| Concepto      | Descripcion                                               |
|---------------|-----------------------------------------------------------|
| `class B : public A` | B hereda todo lo publico/protegido de A          |
| `protected:`  | Accesible desde la clase y sus hijas, no desde afuera    |
| Constructor encadenado | `B(params) : A(params) {}` — llama al padre    |
| Sobrescribir metodo | La hija redefine un metodo del padre              |

```bash
g++ -o herencia 14_herencia.cpp
./herencia
```

---

### 15 — Polimorfismo
**Archivo:** `15_polimorfismo.cpp`

Demuestra polimorfismo con metodos virtuales: una misma llamada se comporta diferente segun el tipo real del objeto en tiempo de ejecucion.

| Concepto            | Descripcion                                              |
|---------------------|----------------------------------------------------------|
| `virtual`           | Permite que las clases hijas reemplacen el metodo        |
| `virtual ... = 0`   | Metodo virtual puro — la hija esta obligada a definirlo  |
| Clase abstracta     | Tiene al menos un metodo virtual puro; no se instancia   |
| `virtual ~Clase()`  | Destructor virtual: necesario al usar punteros a la base |

```bash
g++ -o polimorfismo 15_polimorfismo.cpp
./polimorfismo
```

---

## Algoritmos de busqueda

### Busqueda Lineal
**Carpeta:** `busqueda_lineal/`

Implementacion completa con pseudocodigo, codigo C++ y casos de prueba para el autograder.
Ver [`busqueda_lineal/README.md`](busqueda_lineal/README.md) para detalles.

---

### 16 — Vector vs Lista (`std::vector` vs `std::list`)
**Archivo:** `16_vector_vs_lista.cpp`

Compara las dos estructuras de datos dinamicas mas comunes de la STL lado a lado, mostrando donde cada una tiene ventaja.

| Operacion                  | `vector`         | `list`           |
|----------------------------|------------------|------------------|
| Acceso por indice `[i]`    | O(1)             | No disponible    |
| `push_back` / `pop_back`   | O(1) amortizado  | O(1)             |
| `push_front` / `pop_front` | O(n)             | O(1)             |
| Insertar/eliminar en medio | O(n)             | O(1) con iterador|
| Memoria                    | Contigua (cache) | Nodos enlazados  |

**Regla practica:** usa `vector` por defecto; usa `list` solo si necesitas muchas inserciones/eliminaciones en el medio o `push_front` frecuente.

```bash
g++ -std=c++17 -o vector_vs_lista 16_vector_vs_lista.cpp
./vector_vs_lista
```

---

## POO — Ejemplo integrador

### Estudiante y Curso
**Carpeta:** `poo/`  **Archivo:** `poo/estudiante_curso.cpp`

Ejemplo integrador que combina encapsulacion, constructores y vectores para modelar estudiantes inscritos en cursos.

**Clases:**
- `Curso` — codigo, nombre y creditos de un curso (`m11`, `m12`, `f11`, `f12`)
- `Inscripcion` — vincula un `Curso` con la nota obtenida por el estudiante
- `Estudiante` — almacena nombre, carnet y una lista de inscripciones; calcula el promedio

**Cursos modelados:**

| Codigo | Nombre             | Creditos |
|--------|--------------------|----------|
| `m11`  | Algebra Superior   | 12       |
| `m12`  | Calculo            | 6        |
| `f11`  | Topicos de Fisica  | 6        |
| `f12`  | Programacion 1     | 6        |

**Nota minima para aprobar:** 61

```bash
g++ -std=c++17 -o estudiante_curso poo/estudiante_curso.cpp
./estudiante_curso
```

---

## Orden sugerido de estudio

```
01_hola_mundo
02_imprimir_valores
03_leer_valores
04_condicionales
05_ciclos
06_leer_lista
07_funciones
08_vectores
09_strings
10_matrices
11_clases_basico
12_constructores
13_encapsulacion
14_herencia
15_polimorfismo
16_vector_vs_lista
busqueda_lineal/
poo/
```

Cada ejemplo construye sobre los anteriores: los condicionales y ciclos asumen que ya sabes declarar variables y leer datos del teclado.
