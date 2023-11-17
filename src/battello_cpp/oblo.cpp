//BATTELLO
#include <iostream>

using namespace std;
bool cercaVettore(int vettoreDaCercare[], int matrice[4][8], int righe, int
colonne) {
    for (int i = 0; i < righe; i++) {
        bool trovato = true;

        for (int j = 0; j < colonne; j++) {
            if (vettoreDaCercare[j] != matrice[i][j]) {
                trovato = false;
                break;
            }
        }

        if (trovato) {
            return true;
        }
    }

    return false;
}

int main()
{
    int n = 8;
    int left[]= {0,1,1,1,0,0,1,0};
    int right[] = {0,0,0,1,1,0,1,1};
    int sum[n];
    cout<<"il risultato calcolato e': ";
    for(int i = 0; i < n; i++)
    {
        sum[i]=left[i]+right[i];
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    int result[4][8]={
	{0,1,1,2,1,0,2,1},
	{1,1,1,0,1,1,2,1},
	{1,1,2,2,1,0,1,1},
	{0,1,1,2,1,0,2,1}

    };
    int righe = n/2;
    int colonne = n;

    if (cercaVettore(sum, result, righe, colonne)) {
        cout << "il risultato e´ corretto." << endl;
    } else {
        cout << "il risultato non e´ corretto." << endl;
    }

    return 0;
}

