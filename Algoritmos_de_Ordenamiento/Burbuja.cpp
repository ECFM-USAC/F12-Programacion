#include <iostream>
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<int> &lista, int n)
{
    for (int i = 0; i <= n - 2; ++i)
    {
        bool intercambiado = false;

        for (int j = 0; j <= n - 2 - i; ++j)
        {
            if (lista[j] > lista[j + 1])
            {
                std::swap(lista[j], lista[j + 1]);
                intercambiado = true;
            }
        }

        if (!intercambiado)
        {
            break;
        }
    }
}