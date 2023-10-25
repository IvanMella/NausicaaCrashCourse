#include <iostream>
#include <time.h>
using namespace std;

void stampa(int*, int);

void InsertionSort(int*, int);

int main()
{
	const int n = 5;
	int v [n];

	srand(time(NULL));

	for(int i = 0 ; i < n ; i ++)
	{
		v[i] = rand()% 10 + 1 ;
	}

	stampa(v,n);

	InsertionSort(v,n);

	stampa(v,n);
}

void stampa(int *v, int n)
{

	cout << "il vettore contiene:" << endl;

	for( int i = 0 ; i < n-1 ; i++)
	{
		cout << v [i] << " , ";
	}
	cout << v [n];
	cout << endl;
};
void InsertionSort( int *v, int n)
{
	int aus = v [0];
	int j = 0;
	for(int i = 1 ; i < n ; i++)
	{
		if ( aus > v[i])
		{
			v[j] = v[i];
			v[i] = aus;
			j++;
			aus = v[j];
		}
		else
		{

		}
	}
};
