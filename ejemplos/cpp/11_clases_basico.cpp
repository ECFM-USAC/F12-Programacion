// 11_clases_basico.cpp
// Introduce el concepto de clase: como definir una clase con atributos
// y metodos, y como crear objetos (instancias) de esa clase.
//
// Compilar: g++ -o clases_basico 11_clases_basico.cpp
// Ejecutar: ./clases_basico

#include <iostream>
#include <string>

// ── Definicion de la clase ────────────────────────────────────────────────────
// Una clase es una plantilla que agrupa datos (atributos) y
// comportamiento (metodos) en una sola unidad.

class Rectangulo {
public:
    // Atributos: datos que describe el objeto
    double ancho;
    double alto;

    // Metodos: funciones que pertenecen a la clase
    double area() {
        return ancho * alto;
    }

    double perimetro() {
        return 2 * (ancho + alto);
    }

    void imprimir() {
        std::cout << "Rectangulo " << ancho << " x " << alto << std::endl;
        std::cout << "  Area:      " << area()      << std::endl;
        std::cout << "  Perimetro: " << perimetro() << std::endl;
    }
};

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    // Crear un objeto (instancia) de la clase Rectangulo
    Rectangulo r1;
    r1.ancho = 5.0;
    r1.alto  = 3.0;
    r1.imprimir();

    std::cout << std::endl;

    // Cada objeto es independiente
    Rectangulo r2;
    r2.ancho = 8.0;
    r2.alto  = 2.5;
    r2.imprimir();

    std::cout << std::endl;

    // Comparar areas
    if (r1.area() > r2.area()) {
        std::cout << "r1 tiene mayor area" << std::endl;
    } else {
        std::cout << "r2 tiene mayor area" << std::endl;
    }

    return 0;
}
