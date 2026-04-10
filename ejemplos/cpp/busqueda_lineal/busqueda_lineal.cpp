// busqueda_lineal.cpp
// Implementacion de busqueda lineal (secuencial) sobre una lista de enteros.
//
// Entrada (stdin):
//   Linea 1: N  (cantidad de elementos)
//   Linea 2: N enteros separados por espacio
//   Linea 3: objetivo  (valor a buscar)
//
// Salida (stdout):
//   Indice (base 0) donde se encontro el objetivo, o -1 si no existe.
//
// Compilar: g++ -o busqueda_lineal busqueda_lineal.cpp
// Ejecutar: ./busqueda_lineal

#include <iostream>
#include <vector>

// ── Funcion de busqueda lineal ────────────────────────────────────────────────
// Recorre la lista elemento por elemento y retorna el primer indice
// donde se encuentra el objetivo. Retorna -1 si no esta en la lista.
int busqueda_lineal(const std::vector<int>& lista, int objetivo) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i] == objetivo) {
            return i;   // encontrado: retorna el indice inmediatamente
        }
    }
    return -1;          // no encontrado
}

int main() {
    // Leer la lista
    int n;
    std::cin >> n;

    std::vector<int> lista(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }

    // Leer el objetivo
    int objetivo;
    std::cin >> objetivo;

    // Buscar e imprimir resultado
    int resultado = busqueda_lineal(lista, objetivo);
    std::cout << resultado << std::endl;

    return 0;
}
