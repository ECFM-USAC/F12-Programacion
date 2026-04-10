// 14_herencia.cpp
// Muestra herencia: como una clase hija hereda atributos y metodos
// de una clase padre, y puede agregar o modificar comportamiento.
//
// Compilar: g++ -o herencia 14_herencia.cpp
// Ejecutar: ./herencia

#include <iostream>
#include <string>

// ── Clase base (padre) ────────────────────────────────────────────────────────

class Animal {
protected:
    // 'protected': accesible desde esta clase y sus clases hijas
    std::string nombre;
    int         edad;

public:
    Animal(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

    void comer() {
        std::cout << nombre << " esta comiendo." << std::endl;
    }

    void dormir() {
        std::cout << nombre << " esta durmiendo." << std::endl;
    }

    void imprimir() {
        std::cout << "Animal: " << nombre << ", edad: " << edad << std::endl;
    }
};

// ── Clases derivadas (hijas) ──────────────────────────────────────────────────
// Sintaxis: class Hija : public Padre

class Perro : public Animal {
private:
    std::string raza;

public:
    Perro(std::string nombre, int edad, std::string raza)
        : Animal(nombre, edad), raza(raza) {}   // llama al constructor del padre

    // Metodo propio de Perro
    void ladrar() {
        std::cout << nombre << " dice: Guau! Guau!" << std::endl;
    }

    void imprimir() {
        std::cout << "Perro: " << nombre
                  << ", edad: " << edad
                  << ", raza: " << raza << std::endl;
    }
};

class Gato : public Animal {
private:
    bool es_domestico;

public:
    Gato(std::string nombre, int edad, bool domestico)
        : Animal(nombre, edad), es_domestico(domestico) {}

    void maullar() {
        std::cout << nombre << " dice: Miau!" << std::endl;
    }

    void imprimir() {
        std::cout << "Gato: " << nombre
                  << ", edad: " << edad
                  << ", domestico: " << (es_domestico ? "si" : "no") << std::endl;
    }
};

// ── Herencia en cadena ────────────────────────────────────────────────────────
// Perro -> Animal -> ...  se puede heredar de una clase derivada tambien.

class PerroPolicia : public Perro {
private:
    int numero_placa;

public:
    PerroPolicia(std::string nombre, int edad, std::string raza, int placa)
        : Perro(nombre, edad, raza), numero_placa(placa) {}

    void patrullar() {
        std::cout << nombre << " (placa #" << numero_placa
                  << ") esta patrullando." << std::endl;
    }
};

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    std::cout << "--- Perro ---" << std::endl;
    Perro p("Rex", 3, "Pastor Aleman");
    p.imprimir();
    p.comer();     // heredado de Animal
    p.dormir();    // heredado de Animal
    p.ladrar();    // propio de Perro

    std::cout << std::endl << "--- Gato ---" << std::endl;
    Gato g("Michi", 2, true);
    g.imprimir();
    g.comer();     // heredado de Animal
    g.maullar();   // propio de Gato

    std::cout << std::endl << "--- Perro Policia ---" << std::endl;
    PerroPolicia pp("Zeus", 5, "Labrador", 1042);
    pp.imprimir();    // de Perro
    pp.ladrar();      // de Perro
    pp.patrullar();   // propio de PerroPolicia

    return 0;
}
