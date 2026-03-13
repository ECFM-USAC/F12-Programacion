// 04_condicionales.cpp
// Muestra los tres tipos de condicional en C++:
//   1. if / else if / else
//   2. operador ternario
//   3. switch
//
// Compilar: g++ -o condicionales 04_condicionales.cpp
// Ejecutar: ./condicionales

#include <iostream>

int main() {
    int nota;
    std::cout << "Ingresa una nota (0-100): ";
    std::cin >> nota;

    // ── 1. if / else if / else ────────────────────────────────────────────────
    std::cout << "\n[if/else if/else]" << std::endl;
    if (nota >= 90) {
        std::cout << "Excelente" << std::endl;
    } else if (nota >= 70) {
        std::cout << "Aprobado" << std::endl;
    } else if (nota >= 60) {
        std::cout << "Minimo aprobatorio" << std::endl;
    } else {
        std::cout << "Reprobado" << std::endl;
    }

    // ── 2. Operador ternario ──────────────────────────────────────────────────
    // condicion ? valor_si_verdadero : valor_si_falso
    std::cout << "\n[Operador ternario]" << std::endl;
    std::string resultado = (nota >= 61) ? "Aprobado" : "Reprobado";
    std::cout << "Resultado: " << resultado << std::endl;

    // ── 3. switch ─────────────────────────────────────────────────────────────
    // Util cuando se compara una variable contra valores exactos
    std::cout << "\n[switch]" << std::endl;
    int dia;
    std::cout << "Ingresa un numero de dia (1-7): ";
    std::cin >> dia;

    switch (dia) {
        case 1:
            std::cout << "Lunes" << std::endl;
            break;
        case 2:
            std::cout << "Martes" << std::endl;
            break;
        case 3:
            std::cout << "Miercoles" << std::endl;
            break;
        case 4:
            std::cout << "Jueves" << std::endl;
            break;
        case 5:
            std::cout << "Viernes" << std::endl;
            break;
        case 6:
        case 7:
            std::cout << "Fin de semana" << std::endl;
            break;
        default:
            std::cout << "Dia invalido" << std::endl;
    }

    return 0;
}
