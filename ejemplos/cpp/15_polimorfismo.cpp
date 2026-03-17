// 15_polimorfismo.cpp
// Demuestra polimorfismo con metodos virtuales: una misma llamada
// a metodo se comporta diferente segun el tipo real del objeto.
//
// Compilar: g++ -o polimorfismo 15_polimorfismo.cpp
// Ejecutar: ./polimorfismo

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// ── Clase base abstracta ──────────────────────────────────────────────────────
// Un metodo virtual puro (= 0) obliga a las clases hijas a implementarlo.
// Una clase con al menos un metodo virtual puro es abstracta:
// no se pueden crear objetos de ella directamente.

class Figura {
public:
    // Metodos virtuales puros: cada figura calcula su area y perimetro diferente
    virtual double area()      const = 0;
    virtual double perimetro() const = 0;
    virtual std::string tipo() const = 0;

    // Metodo concreto: usa los virtuales, funciona para cualquier figura
    void imprimir() const {
        std::cout << tipo() << std::endl;
        std::cout << "  Area:      " << area()      << std::endl;
        std::cout << "  Perimetro: " << perimetro() << std::endl;
    }

    // Destructor virtual: necesario cuando se usan punteros a la clase base
    virtual ~Figura() {}
};

// ── Clases derivadas ──────────────────────────────────────────────────────────

class Circulo : public Figura {
private:
    double radio;
    static constexpr double PI = 3.14159265358979;

public:
    Circulo(double r) : radio(r) {}

    double area()      const { return PI * radio * radio; }
    double perimetro() const { return 2 * PI * radio; }
    std::string tipo() const { return "Circulo (radio=" + std::to_string(radio) + ")"; }
};

class Rectangulo : public Figura {
private:
    double ancho, alto;

public:
    Rectangulo(double a, double b) : ancho(a), alto(b) {}

    double area()      const { return ancho * alto; }
    double perimetro() const { return 2 * (ancho + alto); }
    std::string tipo() const {
        return "Rectangulo (" + std::to_string(ancho) + " x " + std::to_string(alto) + ")";
    }
};

class TrianguloEquilatero : public Figura {
private:
    double lado;

public:
    TrianguloEquilatero(double l) : lado(l) {}

    double area()      const { return (std::sqrt(3.0) / 4.0) * lado * lado; }
    double perimetro() const { return 3 * lado; }
    std::string tipo() const { return "Triangulo equilatero (lado=" + std::to_string(lado) + ")"; }
};

// ── Funcion que trabaja con cualquier Figura ──────────────────────────────────
// Gracias al polimorfismo, esta funcion funciona con Circulo,
// Rectangulo, Triangulo, o cualquier clase que herede de Figura.

void describir_figura(const Figura& f) {
    f.imprimir();
}

double area_total(const std::vector<Figura*>& figuras) {
    double total = 0;
    for (const Figura* f : figuras) {
        total += f->area();
    }
    return total;
}

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    std::cout << "--- Figuras individuales ---" << std::endl;
    Circulo            c(5.0);
    Rectangulo         r(4.0, 6.0);
    TrianguloEquilatero t(3.0);

    describir_figura(c);
    std::cout << std::endl;
    describir_figura(r);
    std::cout << std::endl;
    describir_figura(t);

    // ── Uso polimorfico con vector de punteros ────────────────────────────────
    // El vector guarda Figura*, pero cada objeto es de tipo diferente.
    // Al llamar f->area(), C++ ejecuta el metodo correcto segun el tipo real.
    std::cout << std::endl << "--- Coleccion de figuras ---" << std::endl;

    std::vector<Figura*> figuras;
    figuras.push_back(new Circulo(2.0));
    figuras.push_back(new Rectangulo(3.0, 5.0));
    figuras.push_back(new TrianguloEquilatero(4.0));
    figuras.push_back(new Circulo(1.5));

    for (const Figura* f : figuras) {
        std::cout << f->tipo() << "  ->  area = " << f->area() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Area total de todas las figuras: " << area_total(figuras) << std::endl;

    // Liberar memoria
    for (Figura* f : figuras) delete f;

    return 0;
}
