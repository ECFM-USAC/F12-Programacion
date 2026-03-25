// poo/semestre.cpp
// Similar a estudiante_curso.cpp pero usando std::list para los cursos
// y los estudiantes. Las notas se asignan con numeros aleatorios mediante
// ciclos anidados: el ciclo exterior recorre estudiantes, el interior cursos.
//
// Compilar: g++ -std=c++17 -o semestre semestre.cpp
// Ejecutar: ./semestre

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

// ── Clase Curso ───────────────────────────────────────────────────────────────

class Curso {
public:
    std::string codigo;
    std::string nombre;
    int         creditos;

    Curso(std::string codigo, std::string nombre, int creditos)
        : codigo(codigo), nombre(nombre), creditos(creditos) {}
};

// ── Estructura Inscripcion ────────────────────────────────────────────────────

struct Inscripcion {
    Curso  curso;
    double nota;

    Inscripcion(Curso curso, double nota) : curso(curso), nota(nota) {}

    bool aprobado() const { return nota >= 61; }
};

// ── Clase Estudiante ──────────────────────────────────────────────────────────

class Estudiante {
private:
    std::string              nombre;
    std::string              carnet;
    std::list<Inscripcion>   inscripciones;

public:
    Estudiante(std::string nombre, std::string carnet)
        : nombre(nombre), carnet(carnet) {}

    void inscribir(const Curso& curso, double nota) {
        inscripciones.push_back(Inscripcion(curso, nota));
    }

    double promedio() const {
        if (inscripciones.empty()) return 0.0;
        double suma = 0.0;
        for (const Inscripcion& inscripcion : inscripciones) {
            suma += inscripcion.nota;
        }
        return suma / inscripciones.size();
    }

    void imprimir() const {
        std::cout << "Estudiante : " << nombre
                  << "  (carnet: " << carnet << ")" << std::endl;
        std::cout << std::string(55, '-') << std::endl;

        for (const Inscripcion& inscripcion : inscripciones) {
            std::cout << "  [" << inscripcion.curso.codigo << "] "
                      << std::left  << std::setw(22) << inscripcion.curso.nombre
                      << std::right
                      << "  Nota: " << std::setw(5) << std::fixed
                      << std::setprecision(1) << inscripcion.nota
                      << "   " << (inscripcion.aprobado() ? "APROBADO" : "REPROBADO")
                      << std::endl;
        }

        double promedio_final = promedio();
        std::cout << std::string(55, '-') << std::endl;
        std::cout << "  Promedio  : " << std::fixed << std::setprecision(2)
                  << promedio_final
                  << "   (" << (promedio_final >= 61 ? "APROBADO" : "REPROBADO") << ")"
                  << std::endl;
    }
};

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    srand(time(0));   // semilla para numeros aleatorios

    // ── Lista de cursos del primer semestre ───────────────────────────────────
    std::list<Curso> primer_semestre;
    primer_semestre.push_back(Curso("m11", "Algebra Superior",  12));
    primer_semestre.push_back(Curso("m12", "Calculo",            6));
    primer_semestre.push_back(Curso("f11", "Topicos de Fisica",  6));
    primer_semestre.push_back(Curso("f12", "Programacion 1",     6));

    // ── Lista de estudiantes ──────────────────────────────────────────────────
    std::list<Estudiante> estudiantes;
    estudiantes.push_back(Estudiante("Ana Ramirez",    "202300001"));
    estudiantes.push_back(Estudiante("Carlos Perez",   "202300002"));
    estudiantes.push_back(Estudiante("Maria Lopez",    "202300003"));
    estudiantes.push_back(Estudiante("Diego Gonzalez", "202300004"));
    estudiantes.push_back(Estudiante("Sofia Mendez",   "202300005"));

    // ── Ciclos anidados: asignar nota aleatoria a cada estudiante por curso ───
    // Nota aleatoria entre 40 y 100
    for (Estudiante& estudiante : estudiantes) {
        // impiorimir nombre carnet
        for (const Curso& curso : primer_semestre) {
            // imprimir curso 
            double nota_aleatoria = 40 + rand() % 61;   // [40, 100]
            estudiante.inscribir(curso, nota_aleatoria);
        }
    }

    // ── Imprimir reporte ──────────────────────────────────────────────────────
    std::cout << "====== REPORTE DE NOTAS — PRIMER SEMESTRE ======" << std::endl
              << std::endl;

    for (const Estudiante& estudiante : estudiantes) {
        estudiante.imprimir();
        std::cout << std::endl;
    }

    return 0;
}
