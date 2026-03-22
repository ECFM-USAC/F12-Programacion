// 06_leer_lista.cpp
// Lee una lista (arreglo) de numeros ingresados por el usuario
// y calcula el maximo, minimo y promedio.
//
// Compilar: g++ -o leer_lista 06_leer_lista.cpp
// Ejecutar: ./leer_lista

#include <iostream>

int main() {
    // ── Declarar el arreglo ───────────────────────────────────────────────────
    const int TAMANO = 5;    // constante: no cambia durante el programa
    double lista[TAMANO];

    // ── Leer los elementos ────────────────────────────────────────────────────
    std::cout << "Ingresa " << TAMANO << " numeros:" << std::endl;
    for (int i = 0; i < TAMANO; i++) {
        std::cout << "  Numero [" << i + 1 << "]: ";
        std::cin >> lista[i];
    }

    // ── Calcular maximo, minimo y suma ────────────────────────────────────────
    double maximo = lista[0];
    double minimo = lista[0];
    double suma   = 0.0;

    for (int i = 0; i < TAMANO; i++) {
        if (lista[i] > maximo) maximo = lista[i];
        if (lista[i] < minimo) minimo = lista[i];
        suma += lista[i];
    }

    double promedio = suma / TAMANO;

    // ── Imprimir la lista y resultados ────────────────────────────────────────
    std::cout << "\nLista ingresada: ";
    for (int i = 0; i < TAMANO; i++) {
        std::cout << lista[i];
        if (i < TAMANO - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    std::cout << "Maximo  : " << maximo   << std::endl;
    std::cout << "Minimo  : " << minimo   << std::endl;
    std::cout << "Suma    : " << suma     << std::endl;
    std::cout << "Promedio: " << promedio << std::endl;

    return 0;
}
