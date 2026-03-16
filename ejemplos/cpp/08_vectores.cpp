// 08_vectores.cpp
// Muestra el uso de std::vector: lista dinamica que puede crecer o
// reducirse en tiempo de ejecucion, a diferencia de los arreglos estaticos.
//
// Compilar: g++ -std=c++17 -o vectores 08_vectores.cpp
// Ejecutar: ./vectores

#include <iostream>
#include <vector>

int main() {
    // ── Crear e inicializar un vector ─────────────────────────────────────────
    std::vector<int> nums = {10, 30, 50, 20, 40};

    std::cout << "Vector inicial: ";
    for (int x : nums) {          // rango-for: recorre todos los elementos
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // ── Agregar y eliminar elementos ──────────────────────────────────────────
    nums.push_back(60);           // agrega al final
    nums.push_back(70);
    nums.pop_back();              // elimina el ultimo

    std::cout << "Despues de push/pop: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << std::endl;

    // ── Acceso por indice y tamanio ───────────────────────────────────────────
    std::cout << "Tamanio: " << nums.size()  << std::endl;
    std::cout << "Primero: " << nums.front() << std::endl;
    std::cout << "Ultimo : " << nums.back()  << std::endl;
    std::cout << "nums[2] : " << nums[2]     << std::endl;

    // ── Leer un vector del teclado ────────────────────────────────────────────
    int n;
    std::cout << "\nIngresa cuantos numeros quieres guardar: ";
    std::cin >> n;

    std::vector<double> datos;
    datos.reserve(n);             // opcional: reserva memoria de antemano

    for (int i = 0; i < n; i++) {
        double val;
        std::cout << "  Numero [" << i + 1 << "]: ";
        std::cin >> val;
        datos.push_back(val);
    }

    std::cout << "Guardaste " << datos.size() << " numeros." << std::endl;

    return 0;
}
