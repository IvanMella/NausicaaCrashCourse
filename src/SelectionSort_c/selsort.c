 
#include <iostream>
using namespace std;

void stampa(uint8_t *, int);

int main()
{
    const int n = 10;
    uint8_t v[n];

    srand(time(NULL));

    for(int i = 0; i < n; i++)
        v[i] = rand() % 3000 + 1;

    stampa(v, n);

    //SELECTION SORT
    for(int i = 0; i < n - 1; i++)
    {
        //
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min])
                min = j;

    // Scambia l'elemento corrente con l'elemento minimo trovato
    int temp = v[i];
    v[i] = v[min];
    v[min] = temp;
    }

    //stampa
    stampa(v, n);
    return 0;
}

void stampa(uint8_t *v, int n)
{
    int i;
    for(i = 0; i < n - 1; i++)
        cout << (int)v[i] << ", ";

    cout << (int)v[i] << endl;
}
