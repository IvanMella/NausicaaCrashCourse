//BATTELLO
#include <iostream>

using namespace std;

int trovaRisultato(char *, char *[8], int);
void sommaVettore(char *, char *, char *);
// void stampaVettore(char *, int *, int);

int main()
{
	char *left =	"tsssttst";
	char *right =   "tttsstss";
	char *sum =	"--------";

	char *result[8]=
	{
		"ststosos",
		"ssoososs",
		"tssostos",
		"ssoostoo",
		"toststos",
		"tssostos"
	};

	int riga;

	sommaVettore(sum, left, right);

	cout << ("Il risultato calcolato e': " << sum << endl;

	riga = trovaRisultato(sum, result, 4, 8);

	if (riga)
		cout << "il risultato e' la riga nr:" << riga << endl;
	else
		cout << "il risultato non e´ fra le righe." << endl;
	return 0;
}

void sommaVettore(char *sum, char *left, char *right)
{
	while(*left)
	{
		if (*left + *right == 's' + 't')
			*sum = 's';
		else if (*left + *right == 's' + 's')
			*sum = 'o';
		else
			*sum = 't';
	left++;
	right++;
	sum++;
	}
}

void stampaVettore(char *msg ,int *arr, int size)
{
	int i;
	cout << msg;
	for(i = 0; i < size - 1; i++)
		cout << arr[i] << ", ";
	cout << arr[i] << ", " << endl;
}

int trovaRisultato(char *vettoreDaCercare, char * matrice[8], int righe)
{
	for (int i = 0; i < righe; i++)
	{
		while()
		for (int j = 0; j < colonne; j++)
			if (vettoreDaCercare[j] != matrice[i][j])
				break;
			else
				return i + 1;
	}
    return 0;
}
