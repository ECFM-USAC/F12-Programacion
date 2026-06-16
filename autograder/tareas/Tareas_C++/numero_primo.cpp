#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    bool es_primo = true;

    cout << "Ingresa un número entero (n > 2): ";
    cin >> n;

    // Un número es primo si solo es divisible por 1 y por sí mismo
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            es_primo = false;
            break; // Si se encuentra un divisor, dejamos de buscar
        }
    }

    if (es_primo)
    {
        cout << n << " es primo." << endl;
    }
    else
    {
        cout << n << " es no primo." << endl;
    }

    return 0;
}