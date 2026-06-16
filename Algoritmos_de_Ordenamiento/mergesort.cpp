#include <iostream>
#include <vector>

using namespace std;

void mezclar(vector<int> &lista, int inicio, int medio, int fin)
{
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    vector<int> izq(n1), der(n2);

    for (int i = 0; i < n1; i++)
        izq[i] = lista[inicio + i];
    for (int j = 0; j < n2; j++)
        der[j] = lista[medio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2)
    {
        if (izq[i] <= der[j])
        {
            lista[k] = izq[i];
            i++;
        }
        else
        {
            lista[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        lista[k] = izq[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        lista[k] = der[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &lista, int inicio, int fin)
{
    if (inicio >= fin)
        return;

    int medio = inicio + (fin - inicio) / 2; // (Paso 5)

    mergeSort(lista, inicio, medio);
    mergeSort(lista, medio + 1, fin);

    mezclar(lista, inicio, medio, fin);
}

int main()
{
    int n, temp;
    vector<int> datos;

    while (cin >> temp)
    {
        datos.push_back(temp);
    }

    if (!datos.empty())
    {
        mergeSort(datos, 0, datos.size() - 1);

        for (size_t i = 0; i < datos.size(); i++)
        {
            cout << datos[i] << (i == datos.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}