include <iostream>
#include <vector>

// Función de búsqueda de 2 en 2 con retroceso
int busquedaDosEnDos(const std::vector<int>& lista, int objetivo) {
    int n = lista.size();
    int i = 0;

    // 1. Avanzar de dos en dos
    while (i < n && lista[i] < objetivo) {
        i += 2;
    }

    // 2. Si nos pasamos o llegamos al final, retrocedemos uno
    // Caso A: i >= n (se salió de rango)
    // Caso B: lista[i] >= objetivo (encontramos el límite)
    
    // Verificamos la posición actual (i) si está en rango
    if (i < n && lista[i] == objetivo) {
        return i;
    }

    // Verificamos la posición anterior (i-1) si es válida
    if (i - 1 >= 0 && i - 1 < n && lista[i - 1] == objetivo) {
        return i - 1;
    }

    // Si no está en ninguna, no existe
    return -1;
}

int main() {
    std::vector<int> datos = {10, 20, 30, 40, 50, 60, 70};
    int buscar = 40;

    int resultado = busquedaDosEnDos(datos, buscar);

    if (resultado != -1) {
        std::cout << "Elemento encontrado en el indice: " << resultado << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }

    return 0;
}
