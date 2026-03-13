// 05_ciclos.cpp
// Muestra los tres tipos de ciclo en C++:
//   1. for   — cuando se conoce el numero de repeticiones
//   2. while — repite mientras una condicion sea verdadera
//   3. do-while — igual que while pero ejecuta al menos una vez
//
// Compilar: g++ -o ciclos 05_ciclos.cpp
// Ejecutar: ./ciclos

#include <iostream>

int main() {
    // ── 1. for ────────────────────────────────────────────────────────────────
    std::cout << "[for] Tabla del 3:" << std::endl;
    for (int i = 1; i <= 10; i++) {
        std::cout << "  3 x " << i << " = " << 3 * i << std::endl;
    }

    // ── 2. while ──────────────────────────────────────────────────────────────
    // Cuenta regresiva; el cuerpo puede no ejecutarse si la condicion es falsa
    std::cout << "\n[while] Cuenta regresiva:" << std::endl;
    int n = 5;
    while (n > 0) {
        std::cout << "  " << n << std::endl;
        n--;   // sin esto el ciclo seria infinito
    }
    std::cout << "  Despegue!" << std::endl;

    // ── 3. do-while ───────────────────────────────────────────────────────────
    // Solicita un numero valido; siempre pide al menos una vez
    std::cout << "\n[do-while] Pide un numero entre 1 y 10:" << std::endl;
    int valor;
    do {
        std::cout << "  Ingresa un valor (1-10): ";
        std::cin >> valor;
        if (valor < 1 || valor > 10) {
            std::cout << "  Fuera de rango, intenta de nuevo." << std::endl;
        }
    } while (valor < 1 || valor > 10);
   
    std::cout << "  Valor aceptado: " << valor << std::endl;

    // ── break y continue ──────────────────────────────────────────────────────
    std::cout << "\n[break/continue] Numeros del 1 al 10, omitiendo multiplos de 3:" << std::endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) continue;   // salta multiplos de 3
        std::cout << "  " << i;
        if (i == 8) break;          // detiene el ciclo en 8
    }
    std::cout << std::endl;

    return 0;
}
