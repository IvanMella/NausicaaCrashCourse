//BATTELLO
#include <iostream>

using namespace std;

int trovaRisultato(int *, int [][8], int, int);
void sommaVettore(int *, int *, int *, int);
void stampaVettore(char *, int *, int);

int main()
{
	int left[] =    {0,1,1,1,0,0,1,0};
	int right[] =   {0,0,0,1,1,0,1,1};
	int sum[8] =	{0};

	int result[][8]=
	{
		{1,0,1,0,2,1,2,1},
		{1,1,2,2,1,0,1,1},
		{0,1,1,2,1,0,2,1},
		{1,1,2,2,1,0,1,1},
		{0,2,1,0,1,0,2,1},
		{0,1,1,2,1,0,2,1}

	};

	int riga;

	sommaVettore(sum, left, right, 8);

	stampaVettore("Il risultato calcolato e': ", sum, 8);

	riga = trovaRisultato(sum, result, 4, 8);

	if (riga)
		cout << "il risultato e' la riga nr:" << riga << endl;
	else
		cout << "il risultato non e´ fra le righe." << endl;
	return 0;
}

void sommaVettore(int *sum, int *left, int *right, int size)
{
	for(int i = 0; i < size; i++)
		sum[i] = left[i] + right[i];
}

void stampaVettore(char *msg ,int *arr, int size)
{
	int i;
	cout << msg;
	for(i = 0; i < size - 1; i++)
		cout << arr[i] << ", ";
	cout << arr[i] << ", " << endl;
}


int trovaRisultato(int * vettoreDaCercare,
                  int matrice [][8], int righe, int colonne)
{
	for (int i = 0; i < righe; i++)
	{
		for (int j = 0; j < colonne; j++)
			if (vettoreDaCercare[j] != matrice[i][j])
				break;
			else
				return i + 1;
	}
    return 0;
}
