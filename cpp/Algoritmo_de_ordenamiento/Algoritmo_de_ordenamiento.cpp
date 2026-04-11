#include <iostream>      // Entrada y salida estándar
#include <vector>        // Uso de arreglos dinámicos (vector)
#include <string>        // Manejo de texto (string)
using namespace std;     // Evita escribir std:: en todo

// =========================
// ORDENAMIENTO BURBUJA
// =========================
void ordenarBurbuja(vector<int>& datos) { // Recibe el arreglo por referencia
    int tam = datos.size(); // Tamaño del arreglo

    // Recorre el arreglo varias veces
    for (int i = 0; i < tam - 1; i++) {
        bool huboCambio = false; // Control para optimizar si ya está ordenado

        // Comparaciones internas
        for (int j = 0; j < tam - 1 - i; j++) {
            // Si el actual es mayor que el siguiente, intercambiar
            if (datos[j] > datos[j + 1]) {
                swap(datos[j], datos[j + 1]); // Intercambio de valores
                huboCambio = true; // Se realizó un cambio
            }
        }

        // Si no hubo cambios, el arreglo ya está ordenado
        if (!huboCambio) break;
    }
}

// =========================
// ORDENAMIENTO SELECCIÓN
// =========================
void ordenarSeleccion(vector<int>& datos) {
    int tam = datos.size(); // Tamaño del arreglo

    // Recorre cada posición
    for (int i = 0; i < tam - 1; i++) {
        int indiceMin = i; // Se asume que el mínimo es el actual

        // Buscar el menor en el resto del arreglo
        for (int j = i + 1; j < tam; j++) {
            if (datos[j] < datos[indiceMin]) {
                indiceMin = j; // Actualiza el índice del menor
            }
        }

        // Si se encontró un menor diferente, se intercambia
        if (indiceMin != i) {
            swap(datos[i], datos[indiceMin]);
        }
    }
}

// =========================
// FUNCIÓN AUXILIAR MERGE
// =========================
vector<int> combinar(const vector<int>& izquierda, const vector<int>& derecha) {
    vector<int> resultado; // Aquí se guarda el arreglo ordenado final
    int i = 0, j = 0; // Índices para recorrer ambos arreglos

    // Comparar elementos de ambos arreglos
    while (i < izquierda.size() && j < derecha.size()) {
        if (izquierda[i] <= derecha[j]) {
            resultado.push_back(izquierda[i]); // Inserta el menor
            i++; // Avanza en el arreglo izquierdo
        } else {
            resultado.push_back(derecha[j]); // Inserta el menor
            j++; // Avanza en el arreglo derecho
        }
    }

    // Agregar elementos restantes del arreglo izquierdo
    while (i < izquierda.size()) {
        resultado.push_back(izquierda[i]);
        i++;
    }

    // Agregar elementos restantes del arreglo derecho
    while (j < derecha.size()) {
        resultado.push_back(derecha[j]);
        j++;
    }

    return resultado; // Devuelve el arreglo combinado
}

// =========================
// MERGE SORT (RECURSIVO)
// =========================
vector<int> ordenarMergeSort(const vector<int>& datos) {
    // Caso base: si tiene 0 o 1 elemento ya está ordenado
    if (datos.size() <= 1) return datos;

    // Encontrar el punto medio
    int mitad = datos.size() / 2;

    // Dividir en dos arreglos
    vector<int> izquierda(datos.begin(), datos.begin() + mitad);
    vector<int> derecha(datos.begin() + mitad, datos.end());

    // Llamadas recursivas
    izquierda = ordenarMergeSort(izquierda);
    derecha = ordenarMergeSort(derecha);

    // Combinar resultados
    return combinar(izquierda, derecha);
}

// =========================
// FUNCIÓN PRINCIPAL
// =========================
int main() {
    string metodo; // Nombre del algoritmo a usar
    int cantidad;  // Cantidad de números

    // Leer tipo de algoritmo y cantidad
    cin >> metodo >> cantidad;

    vector<int> lista(cantidad); // Crear vector con tamaño definido

    // Leer los valores del arreglo
    for (int i = 0; i < cantidad; i++) {
        cin >> lista[i];
    }

    // Selección del algoritmo según texto ingresado
    if (metodo == "burbuja") {
        ordenarBurbuja(lista);
    } else if (metodo == "seleccion") {
        ordenarSeleccion(lista);
    } else if (metodo == "mergesort") {
        lista = ordenarMergeSort(lista);
    }

    // Imprimir resultados ordenados
    for (int i = 0; i < cantidad; i++) {
        if (i > 0) cout << " "; // Espacio entre números
        cout << lista[i];
    }

    cout << endl; // Salto de línea final

    return 0; // Fin del programa
}