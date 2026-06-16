// busqueda dos en dos
#include <iostream>
#include <vector>

using namespace std;

int busqueda_dos_en_dos(const vector<int> &lista, int n, int objetivo)
{
    int i = 0;
    while (i < n && lista[i] < objetivo)
    {
        i = i + 2; // Se avanza de posiciones
    }

    i = i - 1; // Se retrocede de posiciones

    int inicio = i;
    if (inicio < 0)
        inicio = 0;

    int fin = i + 1;
    if (fin >= n)
        fin = n - 1;

    for (int j = inicio; j <= fin; j++)
    {
        if (lista[j] == objetivo)
        {
            return j;
        }
    }

    return -1; // No se encuentra chamo
}

int main()
{
    vector<int> lista = {5, 12, 18, 25, 30, 45};
    int objetivo = 7; // Aquí se ubica el caso a probar, aqui es donde cambio manualmente.
    int n = lista.size();

    int resultado = busqueda_dos_en_dos(lista, n, objetivo);

    if (resultado != -1)
    {
        cout << "Elemento encontrado en el indice: " << resultado << endl;
    }
    else
    {
        cout << "Elemento no encontrado." << endl;
    }

    return 0;
}