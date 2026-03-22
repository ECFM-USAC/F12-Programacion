// 16_vector_vs_lista.cpp
// Compara std::vector y std::list: operaciones equivalentes, diferencias
// de acceso y casos donde cada uno tiene ventaja.
//
// Compilar: g++ -std=c++17 -o vector_vs_lista 16_vector_vs_lista.cpp
// Ejecutar: ./vector_vs_lista
//
// Resumen rapido:
//   vector  → memoria contigua, acceso por indice O(1), insertar en medio O(n)
//   list    → nodos enlazados, sin acceso por indice,  insertar en medio O(1)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>   // std::find

// Funcion auxiliar para imprimir cualquier contenedor con rango-for
template <typename Contenedor>
void imprimir(const std::string& etiqueta, const Contenedor& c) {
    std::cout << etiqueta << ": ";
    for (const auto& x : c) std::cout << x << " ";
    std::cout << std::endl;
}

int main() {

    // =========================================================================
    // 1. INICIALIZACION — identica para ambos
    // =========================================================================
    std::cout << "=== 1. Inicializacion ===" << std::endl;

    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::list<int>   lst = {10, 20, 30, 40, 50};

    imprimir("vector", vec);
    imprimir("lista ", lst);

    // =========================================================================
    // 2. AGREGAR ELEMENTOS
    // =========================================================================
    std::cout << "\n=== 2. Agregar elementos ===" << std::endl;

    // Ambos pueden agregar al final
    vec.push_back(60);
    lst.push_back(60);

    // VENTAJA DE list: tambien puede agregar al inicio en O(1)
    // vector NO tiene push_front (hacerlo con insert es O(n))
    lst.push_front(0);

    imprimir("vector (solo push_back)", vec);
    imprimir("lista  (push_front + push_back)", lst);

    // =========================================================================
    // 3. ACCESO A ELEMENTOS
    // =========================================================================
    std::cout << "\n=== 3. Acceso a elementos ===" << std::endl;

    // VENTAJA DE vector: acceso directo por indice en O(1)
    std::cout << "vec[0]   = " << vec[0]     << "  (acceso directo por indice)" << std::endl;
    std::cout << "vec[2]   = " << vec[2]     << std::endl;
    std::cout << "vec.front() = " << vec.front() << std::endl;
    std::cout << "vec.back()  = " << vec.back()  << std::endl;

    // list NO tiene operador []: para llegar al elemento i hay que recorrer
    // desde el inicio (O(n)).  Solo front() y back() son O(1).
    std::cout << "lst.front() = " << lst.front() << "  (list: solo front/back son O(1))" << std::endl;
    std::cout << "lst.back()  = " << lst.back()  << std::endl;

    // =========================================================================
    // 4. INSERTAR EN EL MEDIO
    // =========================================================================
    std::cout << "\n=== 4. Insertar en el medio ===" << std::endl;

    // vector: insertar en posicion arbitraria requiere mover todos los
    // elementos siguientes → O(n).  Se usa un iterador.
    auto it_vec = vec.begin();
    std::advance(it_vec, 2);          // apunta al tercer elemento
    vec.insert(it_vec, 99);           // inserta 99 antes de la posicion 2

    // list: insertar es O(1) — solo reenlaza punteros, no mueve datos
    auto it_lst = lst.begin();
    std::advance(it_lst, 2);
    lst.insert(it_lst, 99);

    imprimir("vector despues de insertar 99 en pos 2", vec);
    imprimir("lista  despues de insertar 99 en pos 2", lst);

    // =========================================================================
    // 5. ELIMINAR ELEMENTOS
    // =========================================================================
    std::cout << "\n=== 5. Eliminar elementos ===" << std::endl;

    // Eliminar el ultimo: O(1) en ambos
    vec.pop_back();
    lst.pop_back();

    // list ademas puede eliminar el primero en O(1)
    lst.pop_front();

    imprimir("vector (pop_back)", vec);
    imprimir("lista  (pop_back + pop_front)", lst);

    // Eliminar por valor con erase + find (vector) o remove (list)
    // vector: buscar con std::find O(n), luego erase O(n) por el desplazamiento
    auto pos = std::find(vec.begin(), vec.end(), 99);
    if (pos != vec.end()) vec.erase(pos);

    // list: remove elimina todas las ocurrencias del valor en O(n),
    // pero cada eliminacion individual es O(1) sin desplazar datos
    lst.remove(99);

    imprimir("vector sin el 99", vec);
    imprimir("lista  sin el 99", lst);

    // =========================================================================
    // 6. TAMANIO Y RECORRIDO
    // =========================================================================
    std::cout << "\n=== 6. Tamanio y recorrido ===" << std::endl;

    std::cout << "vector size: " << vec.size() << std::endl;
    std::cout << "lista  size: " << lst.size() << std::endl;

    // Ambos soportan rango-for de forma identica
    std::cout << "Recorrido vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "Recorrido lista : ";
    for (int x : lst) std::cout << x << " ";
    std::cout << std::endl;

    // =========================================================================
    // RESUMEN
    // =========================================================================
    std::cout << "\n=== Resumen: cuando usar cada uno ===" << std::endl;
    std::cout << "vector  → acceso por indice, recorridos, ordenamiento" << std::endl;
    std::cout << "list    → muchas inserciones/eliminaciones en el medio" << std::endl;
    std::cout << "         o necesitas push_front eficiente" << std::endl;
    std::cout << "\nEn la mayoria de casos: usa vector." << std::endl;

    return 0;
}
