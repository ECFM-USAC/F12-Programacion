# Busqueda Lineal en C++

La **busqueda lineal** (o busqueda secuencial) recorre una lista elemento por elemento
hasta encontrar el objetivo o agotar la lista. Es el algoritmo de busqueda mas simple
y funciona en cualquier lista, ordenada o no.

---

## Pseudocodigo

```
FUNCION busqueda_lineal(lista, objetivo):
    PARA i DESDE 0 HASTA longitud(lista) - 1:
        SI lista[i] == objetivo:
            RETORNAR i        // encontrado: devolver el indice
    RETORNAR -1               // no encontrado
```

**Complejidad:**
| Caso        | Tiempo | Descripcion                                |
|-------------|--------|--------------------------------------------|
| Mejor caso  | O(1)   | El objetivo es el primer elemento          |
| Caso promedio | O(n/2) ≈ O(n) | El objetivo esta en el medio      |
| Peor caso   | O(n)   | El objetivo es el ultimo o no esta en la lista |

---

## Implementacion en C++

```cpp
#include <iostream>
#include <vector>

// Retorna el indice (base 0) del objetivo, o -1 si no se encuentra.
int busqueda_lineal(const std::vector<int>& lista, int objetivo) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i] == objetivo) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> lista(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }

    int objetivo;
    std::cin >> objetivo;

    std::cout << busqueda_lineal(lista, objetivo) << std::endl;
    return 0;
}
```

Archivo completo: [`busqueda_lineal.cpp`](busqueda_lineal.cpp)

### Compilar y ejecutar

```bash
g++ -o busqueda_lineal busqueda_lineal.cpp
./busqueda_lineal
```

Ejemplo interactivo:
```
5
10 30 50 20 40
20
3
```
*(busca el 20 en la lista, lo encuentra en el indice 3)*

---

## Pruebas con el Autograder

Los casos de prueba estan en `autograder/tests/busqueda_lineal/`.

### Formato de entrada/salida

```
<N>
<a1> <a2> ... <aN>
<objetivo>
```
Salida: indice donde se encontro (base 0), o `-1` si no existe.

### Ejecutar todos los tests

```bash
# Desde la raiz del repositorio
./autograder/autograder.sh busqueda_lineal ejemplos/cpp/busqueda_lineal/busqueda_lineal.cpp
```

### Casos de prueba incluidos

| Caso   | N      | Descripcion                               | Resultado esperado |
|--------|--------|-------------------------------------------|--------------------|
| caso1  | 5      | Objetivo en el centro de la lista         | 3                  |
| caso2  | 6      | Objetivo no existe en la lista            | -1                 |
| caso3  | 4      | Objetivo es el primer elemento (mejor caso) | 0                |
| caso4  | 4      | Objetivo es el ultimo elemento (peor caso) | 3                 |
| caso5  | 10 000 | Lista grande — objetivo encontrado (indice 7823) | 7823        |
| caso6  | 10 000 | Lista grande — objetivo no existe (peor caso O(n)) | -1        |

Los casos 5 y 6 muestran el comportamiento O(n) en listas grandes.
El tiempo de ejecucion aparece junto a cada resultado en el autograder.

### Salida esperada del autograder

```
  [PASS] caso1  (X ms)
  [PASS] caso2  (X ms)
  [PASS] caso3  (X ms)
  [PASS] caso4  (X ms)
  [PASS] caso5  (X ms)   <- lista de 10 000 elementos
  [PASS] caso6  (X ms)   <- peor caso: recorre toda la lista

 Resultado: 6 / 6 casos pasados
```

---

## Diferencia con Busqueda Binaria

| Caracteristica        | Lineal          | Binaria         |
|-----------------------|-----------------|-----------------|
| Lista ordenada?       | No necesaria    | Obligatorio     |
| Complejidad peor caso | O(n)            | O(log n)        |
| Simple de implementar | Si              | Un poco mas     |
| Util para listas de   | Cualquier tamano | Listas grandes |
