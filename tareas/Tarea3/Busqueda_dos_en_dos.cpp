#include <iostream>
#include <vector>
#include <algorithm>

int busqueda_de_dos_en_dos(const std::vector<int>& lista, int n, int objetivo) {
    int i = 0;
    //Avanzar de 2 en 2 mientras el elemento sea menor que el objetivo
    while (i < n && lista[i] < objetivo) {
        i += 2;
    }
    //Retroceder un paso si el objetivo es menor que el elemento actual
    if (i < n && lista[i] > objetivo) {
        i=i-1;
 }
//Revisar hasta 2 posiciones a partir de i
    for (int j= std::max(0, i); j <= std::min(i+1, n-1); j++) {
        if (lista[j] == objetivo) {
            return j; // Retorna el índice del objetivo
        }
    }
    return -1; // Retorna -1 si el objetivo no se encuentra
}

int main(){
std::vector<int> lista;
int n, objetivo;
std::cin >> n;

for (int i = 0; i < n; i++) {
    int elemento;
    std::cin >> elemento;
    lista.push_back(elemento);
}

std::cin >> objetivo;
int indice = busqueda_de_dos_en_dos(lista, n, objetivo);
std::cout << indice << std::endl;
return -1;
}