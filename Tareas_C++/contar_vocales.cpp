#include <iostream>
#include <string>

using namespace std;

int main()
{
    string texto;
    int contador = 0;

    cout << "Escribe una frase: ";
    getline(cin, texto); // Lee la línea completa

    for (char c : texto)
    {
        // Convertimos a minúscula temporalmente para simplificar la comparación
        char minuscula = tolower(c);

        if (minuscula == 'a' || minuscula == 'e' || minuscula == 'i' ||
            minuscula == 'o' || minuscula == 'u')
        {
            contador++;
        }
    }

    cout << "Total de vocales: " << contador << endl;

    return 0;
}