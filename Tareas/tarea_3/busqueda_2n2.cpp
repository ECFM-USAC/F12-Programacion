// busqueda_2n2.cpp
// Compilar: g++ -o busqueda_2n2 busqueda_2n2.cpp
// Ejecutar: ./busqueda_2n2

#include <iostream>

int main() {
    const int TAMANO = 10;
    double lista[TAMANO] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    double numeroABuscar;

    std::cout << "Ingrese el numero que desea buscar: ";
    std::cin >> numeroABuscar;

    bool encontrado = false;

    // El incremento i += 2 hace que busque "de dos en dos"
    for (int i = 0; i < TAMANO; i += 2) {
        if (lista[i] == numeroABuscar) {
            std::cout << "El numero " << numeroABuscar << " se encuentra en la posicion " << i << std::endl;
            encontrado = true;
            break; 
        }
    }

    if (!encontrado) {
        std::cout << "El numero no se encontro en las posiciones pares consultadas." << std::endl;
    }

    return 0;
}