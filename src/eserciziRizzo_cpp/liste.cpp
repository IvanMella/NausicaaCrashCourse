/*Scrivere un programma C++ che permetta di:
- dichiarare un vettore di interi di lunghezza 10 x
- farlo valorizzare con numeri casuali dispari compresi tra 0 e 100 x
- stamparlo a video in riga x
- costruire una lista ordinata a con i dati presenti nell'array (senza ricerca del massimo) x
- stampare a video il contenuto della lista*/
#include <iostream>
#include <list>
using namespace std;

void ranDispari (int *, int);
void stampaVettore( string , int *, int);
void stampaLista( string , list<int>);


int main()
{

	int v[10];
	ranDispari(v, 10);
	stampaVettore("il vettore contiene :", v, 10);

	int w = 0;
	std::list <int> lista;

	for (int i = 0; i < 10; i++)
		lista.push_back(v[i]);

	stampaLista("Lista disordinata: ", lista);

	lista.sort();

	stampaLista("   Lista ordinata: ", lista);

	return 0;
}
void ranDispari (int *v, int size)
{
	srand(time(NULL));
	int r;
	for(int i = 0; i < size; i++)
	{
		r=rand() % 101;
		if(r % 2)
			v[i] = r;
		else
			v[i] = r + 1;
	}

}
void stampaVettore( string msg ,int *arr, int size)
{
	int i;
	cout << msg;
	for(i = 0; i < size - 1; i++)
		cout << arr[i] << ", ";
	cout << arr[i] << endl;
}

void stampaLista( string msg ,list <int> lista)
{
	cout << msg;
	for (int i : lista)
		cout << i << ", ";
	cout << endl;
}
