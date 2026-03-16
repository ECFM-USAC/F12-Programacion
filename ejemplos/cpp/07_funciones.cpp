// 07_funciones.cpp
// Muestra como definir y usar funciones en C++:
// declaracion, parametros, valor de retorno y funciones void.
//
// Compilar: g++ -o funciones 07_funciones.cpp
// Ejecutar: ./funciones

#include <iostream>

// ── Declaraciones (prototipos) ────────────────────────────────────────────────
// Permiten llamar la funcion antes de definirla.
double area_rectangulo(double base, double altura);
double area_circulo(double radio);
void   imprimir_linea(int n);
int    mayor_de_dos(int a, int b);

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    double b = 5.0, h = 3.0;
    std::cout << "Area del rectangulo (" << b << " x " << h << "): "
              << area_rectangulo(b, h) << std::endl;

    double r = 4.0;
    std::cout << "Area del circulo (radio " << r << "): "
              << area_circulo(r) << std::endl;

    imprimir_linea(20);

    int x = 7, y = 12;
    std::cout << "El mayor entre " << x << " y " << y << " es: "
              << mayor_de_dos(x, y) << std::endl;

    return 0;
}

// ── Definiciones ──────────────────────────────────────────────────────────────

// Retorna el area de un rectangulo.
double area_rectangulo(double base, double altura) {
    return base * altura;
}

// Retorna el area de un circulo.
double area_circulo(double radio) {
    const double PI = 3.14159265358979;
    return PI * radio * radio;
}

// Funcion void: no retorna ningun valor, solo imprime.
void imprimir_linea(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

// Retorna el mayor de dos enteros.
int mayor_de_dos(int a, int b) {
    if (a > b) return a;
    return b;
}
