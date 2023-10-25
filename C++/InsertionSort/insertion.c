#include <iostream>
#include <time.h>
#include <cstring>

using namespace std;

void stampa(char *, int);
void InsertionSort(char *, int);
void swap(char *, char *);


int main()
{
	/* vettore da ordinare				*/
	char v[] = "NAUSICAA";

	/* lunghezza del vettore			*/
	int n = strlen(v);

	/* lasciamo  stare per un attimo questo		*
	srand(time(NULL));

	for(int i = 0 ; i < n ; i ++)
	{
		v[i] = rand()% 10 + 1 ;
	}
							*/
	//stampa(v,n);

	InsertionSort(v,n);

	stampa(v,n);
}

void stampa(char *v, int n)
{

	cout << "il vettore contiene: ";

	for( int i = 0 ; i < n-1 ; i++)
	{
		cout << v[i] << " , ";
	}

	/* n-1! se gli elementi son 7 l'ultimo indice e' il 6sto	*/
	cout <<  v[n - 1];
	cout << endl;
};
void InsertionSort( char *v, int n)
{
	/* da 0 a questo indice son gia' ordinati			*/
	int indOrd = 0;

	/* Elemento in esame, 1 a destra dell'indice ordinato		*/
	int currEl = indOrd + 1;

	/* Finche non ho scorruto tutto il vettore da Sx a Dx		*/
	while (indOrd < n - 1)
	{
		stampa(v,n);
		cout << "currEl:" << currEl << ", Swap:";
		/* Se  l'elemento  corrente  e'  piu  piccolo  del  suo	*
		 * adiacente a sx E non ho ancora attraversato tutto il *
		 * vettore da dx a sx...   Swappolo!			*/
		while (v[currEl] < v[currEl - 1] && currEl > 0)
		{
			cout << " | " << currEl << " <-> " << currEl - 1;

			swap(v[currEl], v[currEl - 1]);
			/* decrementa curEl per esaminare il prossimo 	*
			 * elemento a sx				*/
			currEl --;
		}
		cout << endl << endl;
		/* Altrimenti sposto a dx l'indice degli  elementi   ed	*
		 * esamino il primo elemento a dx dell  elenco ordinato	*
		 * l'insieme ordinato  e'   cresciuto   quindi   indOrd	*
		 * incrementa						*/
		indOrd++;
		/* L'elemento corrente e' sempre 1 a dx di indOrd	*/
		currEl = indOrd + 1;
	}
}

void swap(char *s, char *d)
{
	char swap = *s;
	*s = *d;
	*d = swap;
}
