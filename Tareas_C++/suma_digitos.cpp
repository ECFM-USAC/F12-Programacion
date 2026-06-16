#include <iostream>
using namespace std;

int main()
{
    int numero, suma = 0, residuo;

    cout << "Ingresa un entero positivo: ";
    cin >> numero;

    // Aquí se asegura de que sea positivo
    if (numero < 0)
        numero = -numero;

    while (numero > 0)
    {
        residuo = numero % 10; // Obtiene el último dígito
        suma = suma + residuo; // Lo acumula en la suma
        numero = numero / 10;  // Elimina el último dígito del número
    }

    cout << "La suma de los digitos es: " << suma << endl;

    return 0;
}