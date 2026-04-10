// poo/estudiante_curso.cpp
// Ejemplo integrador de POO: clases Curso y Estudiante.
// Cada estudiante esta inscrito en 4 cursos con una nota por curso.
// Se calcula el promedio general y se indica si cada curso fue aprobado (>= 61).
//
// Compilar: g++ -std=c++17 -o estudiante_curso estudiante_curso.cpp
// Ejecutar: ./estudiante_curso

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>

// ── Clase Curso ───────────────────────────────────────────────────────────────
// Representa un curso con su codigo, nombre y creditos.

class Curso {
public:
    std::string codigo;
    std::string nombre;
    int         creditos;

    Curso(std::string codigo, std::string nombre, int creditos)
        : codigo(codigo), nombre(nombre), creditos(creditos) {}
};

// ── Estructura Inscripcion ────────────────────────────────────────────────────
// Une un Curso con la nota obtenida por el estudiante en ese curso.

struct Inscripcion {
    Curso  curso;
    double nota;

    Inscripcion(Curso c, double n) : curso(c), nota(n) {}

    bool aprobado() const { return nota >= 61; }
};

// ── Clase Estudiante ──────────────────────────────────────────────────────────
// Almacena el nombre y carnet del estudiante y su lista de inscripciones.

class Estudiante {
private:
    std::string            nombre;
    std::string            carnet;
    std::vector<Inscripcion> inscripciones;

public:
    Estudiante(std::string nombre, std::string carnet)
        : nombre(nombre), carnet(carnet) {}

    // Agrega un curso con su nota a la lista del estudiante
    void inscribir(const Curso& curso, double nota) {
        inscripciones.push_back(Inscripcion(curso, nota));
    }

    // Promedio simple de todas las notas
    double promedio() const {
        if (inscripciones.empty()) return 0.0;
        double suma = 0.0;
        for (const Inscripcion& i : inscripciones) {
            suma += i.nota;
        }
        return suma / inscripciones.size();
    }

    // Imprime el resumen completo del estudiante
    void imprimir() const {
        std::cout << "Estudiante : " << nombre
                  << "  (carnet: " << carnet << ")" << std::endl;
        std::cout << std::string(55, '-') << std::endl;

        for (const Inscripcion& i : inscripciones) {
            std::cout << "  [" << i.curso.codigo << "] "
                      << std::left << std::setw(22) << i.curso.nombre
                      << std::right
                      << "  Nota: " << std::setw(5) << std::fixed
                      << std::setprecision(1) << i.nota
                      << "   " << (i.aprobado() ? "APROBADO" : "REPROBADO")
                      << std::endl;
        }

        double prom = promedio();
        std::cout << std::string(55, '-') << std::endl;
        std::cout << "  Promedio  : " << std::fixed << std::setprecision(2)
                  << prom
                  << "   (" << (prom >= 61 ? "APROBADO" : "REPROBADO") << ")"
                  << std::endl;
    }
};

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    // Definicion de los 4 cursos del pensum
    Curso algebra("m11", "Algebra Superior",  12);
    Curso calculo ("m12", "Calculo",            6);
    Curso fisica  ("f11", "Topicos de Fisica",  6);
    Curso prog    ("f12", "Programacion 1",     6);

    // Crear 5 estudiantes e inscribirlos en los 4 cursos con sus notas
    std::vector<Estudiante> estudiantes;

    Estudiante e1("Ana Ramirez",      "202300001");
    e1.inscribir(algebra, 75.0);
    e1.inscribir(calculo,  82.0);
    e1.inscribir(fisica,   68.0);
    e1.inscribir(prog,     91.0);
    estudiantes.push_back(e1);

    Estudiante e2("Carlos Perez",     "202300002");
    e2.inscribir(algebra, 55.0);
    e2.inscribir(calculo,  70.0);
    e2.inscribir(fisica,   48.0);
    e2.inscribir(prog,     83.0);
    estudiantes.push_back(e2);

    Estudiante e3("Maria Lopez",      "202300003");
    e3.inscribir(algebra, 88.0);
    e3.inscribir(calculo,  74.0);
    e3.inscribir(fisica,   91.0);
    e3.inscribir(prog,     95.0);
    estudiantes.push_back(e3);

    Estudiante e4("Diego Gonzalez",   "202300004");
    e4.inscribir(algebra, 42.0);
    e4.inscribir(calculo,  58.0);
    e4.inscribir(fisica,   61.0);
    e4.inscribir(prog,     77.0);
    estudiantes.push_back(e4);

    Estudiante e5("Sofia Mendez",     "202300005");
    e5.inscribir(algebra, 65.0);
    e5.inscribir(calculo,  61.0);
    e5.inscribir(fisica,   70.0);
    e5.inscribir(prog,     88.0);
    estudiantes.push_back(e5);

    // Imprimir el reporte de cada estudiante
    std::cout << "====== REPORTE DE NOTAS ======" << std::endl << std::endl;
    for (const Estudiante& e : estudiantes) {
        e.imprimir();
        std::cout << std::endl;
    }

    return 0;
}
