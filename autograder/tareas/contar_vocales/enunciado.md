# Tarea 3 — Ejercicio 3: Contador de Vocales

Lee una línea de texto e imprime cuántas vocales contiene.
Vocales: `a e i o u` (mayúsculas y minúsculas, sin acentos).

## Entrada

Una línea de texto (puede contener espacios y números).

## Salida

El número de vocales (entero).

## Ejemplos

```
Entrada: Hola Mundo       Salida: 4
Entrada: ECFM             Salida: 1
Entrada: rhythm           Salida: 0
Entrada: aeiou            Salida: 5
Entrada: Programacion 1   Salida: 5
```

## Pista

```cpp
#include <cctype>   // tolower
std::string linea;
std::getline(std::cin, linea);
for (char c : linea) {
    char m = tolower(c);
    if (m=='a'||m=='e'||m=='i'||m=='o'||m=='u') conteo++;
}
```

## Prueba

```bash
./autograder/autograder.sh contar_vocales contar_vocales.cpp
```
