#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> &lista, int n)
{
    for (int i = 0; i <= n - 2; ++i)
    {
        int min_idx = i;

        for (int j = i + 1; j <= n - 1; ++j)
        {
            if (lista[j] < lista[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            swap(lista[i], lista[min_idx]);
        }
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> lista(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> lista[i];
    }

    selectionSort(lista, n);

    for (int i = 0; i < n; ++i)
    {
        cout << lista[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}