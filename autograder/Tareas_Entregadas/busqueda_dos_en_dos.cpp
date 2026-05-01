#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::max y std::min

int busqueda_dos_en_dos(const std::vector<int>& lista, int n, int objetivo) {
    int i = 0;

    // 1. Avanzar de 2 en 2 mientras el elemento sea menor al objetivo
    while (i < n && lista[i] < objetivo) {
        i = i + 2;
    }

    // 2. Retroceder 1 posicion (el objetivo puede estar en i-1 o i)
    i = i - 1;

    // 3. Revisar hasta 2 posiciones a partir de la nueva i
    // Usamos max y min para no salirnos de los bordes del vector
    int inicio = std::max(0, i);
    int fin = std::min(i + 1, n - 1);

    for (int j = inicio; j <= fin; j++) {
        if (lista[j] == objetivo) {
            return j; // Retorna la primera ocurrencia
        }
    }

    return -1; // No encontrado
}

int main() {
    int n, objetivo;
    
    // Leer cantidad de elementos
    if (!(std::cin >> n)) return 0;
    
    // Leer la lista ordenada
    std::vector<int> lista(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }
    
    // Leer el valor a buscar
    std::cin >> objetivo;

    // Ejecutar búsqueda e imprimir resultado
    std::cout << busqueda_dos_en_dos(lista, n, objetivo) << std::endl;

    return 0;
}




