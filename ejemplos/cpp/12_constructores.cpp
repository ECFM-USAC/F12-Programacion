// 12_constructores.cpp
// Muestra como usar constructores para inicializar objetos al crearlos,
// y el destructor que se ejecuta automaticamente al destruir el objeto.
//
// Compilar: g++ -o constructores 12_constructores.cpp
// Ejecutar: ./constructores

#include <iostream>
#include <string>
#include <cmath>

// ── Clase con constructor y destructor ───────────────────────────────────────

class Persona {
public:
    std::string nombre;
    int         edad;

    // Constructor por defecto (sin parametros)
    Persona() {
        nombre = "Sin nombre";
        edad   = 0;
        std::cout << "[Constructor] Persona creada (sin datos)" << std::endl;
    }

    // Constructor con parametros
    Persona(std::string n, int e) {
        nombre = n;
        edad   = e;
        std::cout << "[Constructor] Persona creada: " << nombre << std::endl;
    }

    // Destructor: se llama automaticamente cuando el objeto sale de scope
    ~Persona() {
        std::cout << "[Destructor]  Persona destruida: " << nombre << std::endl;
    }

    void saludar() {
        std::cout << "Hola, soy " << nombre
                  << " y tengo " << edad << " anios." << std::endl;
    }
};

// ── Clase con lista de inicializacion ────────────────────────────────────────
// Forma mas eficiente de inicializar atributos en el constructor.

class Punto {
public:
    double x;
    double y;

    // Lista de inicializacion: atributo(valor)
    Punto(double x, double y) : x(x), y(y) {}

    void imprimir() {
        std::cout << "Punto(" << x << ", " << y << ")" << std::endl;
    }

    double distancia_al_origen() {
        return std::sqrt(x*x + y*y);
    }
};

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    std::cout << "--- Constructores de Persona ---" << std::endl;

    Persona p1;                        // constructor por defecto
    Persona p2("Ana Lopez", 20);       // constructor con parametros
    Persona p3("Carlos Ruiz", 25);

    std::cout << std::endl;
    p1.saludar();
    p2.saludar();
    p3.saludar();

    std::cout << std::endl << "--- Puntos ---" << std::endl;

    Punto pt(3.0, 4.0);
    pt.imprimir();
    std::cout << "Distancia al origen: " << pt.distancia_al_origen() << std::endl;

    std::cout << std::endl << "--- Fin del programa (destructores) ---" << std::endl;
    // Al terminar main, los destructores se llaman en orden inverso
    return 0;
}
