// 13_encapsulacion.cpp
// Demuestra encapsulacion: ocultar datos con 'private' y exponer
// solo lo necesario con 'public' mediante getters y setters.
//
// Compilar: g++ -o encapsulacion 13_encapsulacion.cpp
// Ejecutar: ./encapsulacion

#include <iostream>
#include <string>

// ── Clase con encapsulacion ───────────────────────────────────────────────────
// Los atributos son private: solo los metodos de la clase pueden accederlos.
// Los metodos publicos son la "interfaz" del objeto.

class CuentaBancaria {
private:
    std::string titular;
    double      saldo;
    int         num_transacciones;

public:
    // Constructor: unico punto donde se fija el titular y saldo inicial
    CuentaBancaria(std::string nombre, double saldo_inicial) {
        titular            = nombre;
        saldo              = saldo_inicial;
        num_transacciones  = 0;
    }

    // Getter: leer el saldo (solo lectura, no se puede modificar directamente)
    double getSaldo() const {
        return saldo;
    }

    std::string getTitular() const {
        return titular;
    }

    int getNumTransacciones() const {
        return num_transacciones;
    }

    // Metodos que modifican el estado con validacion
    bool depositar(double monto) {
        if (monto <= 0) {
            std::cout << "Error: el monto debe ser positivo." << std::endl;
            return false;
        }
        saldo += monto;
        num_transacciones++;
        return true;
    }

    bool retirar(double monto) {
        if (monto <= 0) {
            std::cout << "Error: el monto debe ser positivo." << std::endl;
            return false;
        }
        if (monto > saldo) {
            std::cout << "Error: saldo insuficiente." << std::endl;
            return false;
        }
        saldo -= monto;
        num_transacciones++;
        return true;
    }

    void imprimir() const {
        std::cout << "Cuenta de " << titular << std::endl;
        std::cout << "  Saldo:          Q" << saldo << std::endl;
        std::cout << "  Transacciones:  " << num_transacciones << std::endl;
    }
};

// ── Funcion main ──────────────────────────────────────────────────────────────
int main() {
    CuentaBancaria cuenta("Maria Garcia", 1000.0);
    cuenta.imprimir();

    std::cout << std::endl;

    // Operaciones validas
    cuenta.depositar(500.0);
    std::cout << "Deposito Q500  -> Saldo: Q" << cuenta.getSaldo() << std::endl;

    cuenta.retirar(200.0);
    std::cout << "Retiro  Q200  -> Saldo: Q" << cuenta.getSaldo() << std::endl;

    std::cout << std::endl;

    // Operaciones invalidas (la clase las rechaza)
    cuenta.depositar(-100.0);
    cuenta.retirar(5000.0);

    std::cout << std::endl;
    cuenta.imprimir();

    // Esto causaria un error de compilacion (saldo es privado):
    // cuenta.saldo = 999999;

    return 0;
}
