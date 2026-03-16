// 10_matrices.cpp
// Declara y recorre una matriz (arreglo 2D) en C++.
// Calcula la suma de cada fila y la traza (diagonal principal).
//
// Compilar: g++ -o matrices 10_matrices.cpp
// Ejecutar: ./matrices

#include <iostream>

int main() {
    const int FILAS   = 3;
    const int COLUMNAS = 4;

    // ── Inicializar la matriz ──────────────────────────────────────────────────
    // Los elementos se acceden con matriz[fila][columna]
    int matriz[FILAS][COLUMNAS] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12}
    };

    // ── Imprimir la matriz ─────────────────────────────────────────────────────
    std::cout << "Matriz (" << FILAS << "x" << COLUMNAS << "):" << std::endl;
    for (int f = 0; f < FILAS; f++) {
        std::cout << "  [";
        for (int c = 0; c < COLUMNAS; c++) {
            std::cout << " " << matriz[f][c];
            if (c < COLUMNAS - 1) std::cout << ",";
        }
        std::cout << " ]" << std::endl;
    }

    // ── Suma de cada fila ──────────────────────────────────────────────────────
    std::cout << "\nSuma por fila:" << std::endl;
    for (int f = 0; f < FILAS; f++) {
        int suma = 0;
        for (int c = 0; c < COLUMNAS; c++) {
            suma += matriz[f][c];
        }
        std::cout << "  Fila " << f << ": " << suma << std::endl;
    }

    // ── Traza (diagonal principal, solo en matrices cuadradas) ─────────────────
    const int N = 3;
    int cuadrada[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int traza = 0;
    for (int i = 0; i < N; i++) {
        traza += cuadrada[i][i];    // elemento [i][i] es la diagonal
    }
    std::cout << "\nTraza de la matriz cuadrada: " << traza << std::endl;

    return 0;
}
