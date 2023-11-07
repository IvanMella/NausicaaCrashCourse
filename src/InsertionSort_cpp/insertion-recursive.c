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
	stampa(v,n);

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


/* Variante riscorsiva dell'algoritmo Insertion sort 			*
 * i vettore 0..n e' uguale al vettore 0..n-1 ordinato. il vettore di	*
 * due elementi chiude l'algoritmo e fa implodere la ricorsione		*/
void InsertionSort(char *v, int n)
{
	if (n>1)
	{
	cout << "InsertionSort(v, "<< n - 1 <<") --> ";
	InsertionSort(v, n - 1);
		int val = v[n-1];
		int j = n - 2;
		while(j >= 0 && v[j] > val)
		{
			cout << "Sort..";
			v[j +1] = v[j];
			j--;
		}
		v[j+1] = val;
	}
	cout << "Return --> ";
}
