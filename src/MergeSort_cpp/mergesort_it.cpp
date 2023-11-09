/*
* File: mergeSort2.cpp
* Author: Ivam
*
* Created on 23/09/2023
*/
#include <iostream>

using namespace std;

/* Prototipi di funzioni					*/
void riempiVettore(int * array,int size);
void stampaVettore(string message, int * array, int size);

void mergeIt(int * array,int size);

/* Variabili globali						*/
int swapMerge = 0;

/* argc->  argument   counter,  e'  il  numero degli  argomenti	*
 * compreso  il  nome  del   programma,  argv (** perche e'  un	*
 * puntatore a puntatore)  il secondo puntatore  e' quello  che	*
 * mi permette di leggere tutto  il   nome  che  sto  puntando.	*
 * (non serve a nulla perche non viene trattato)		*
 * int main(int argc, char** argv)				*/
int main()
{

	const int n = 8;
	int v[n];

	riempiVettore(v,n);

	stampaVettore("Vettore di Partenza: ",v,n);

	mergeIt(v, n);

	//cout << "MergeSort: " << swapMerge << " scambi" << endl;

	stampaVettore("Ordinamento di tipo MergeSort: ", v, n);

	return 0;
}

void riempiVettore(int *array,int size)
{
	array[0] = rand() % 10 + 1;
	for(int i = 1; i < size; i++)
		array[i] = rand() % 10 + 1;
/*

	int half = size / 2;
	int i;
	for(i = 0; i < half; i++)
	{
		array[i + half] = i * 2;
		array[i] = i * 2 + 1;
	}
	if (size & 1)
 		array[i + half] = i * 2 + 1;
*/
}

void stampaVettore(string message, int * array, int size)
{
	cout << message;
	for(int i = 0; i < size; i++)
		cout << " " << array[i];
	cout << endl;
}


void mergeIt(int *array,int size)
{
	int run = 2;
	int begin = 0;
	int end = run - 1;
	while (run < size)
	{
		while (begin < size)
		{
			for(int i = begin; i < end; i ++)
				if(array[i] > array[i+run-1])
					swap(array[i],array[i+run-1]);
			begin = end + 1;
			end += run;
		}
	cout << "Run " << run << " ";
	stampaVettore("Passaggio: ", array, size);

	run *= 2 + 1;
	int begin = 0;
	int end = run - 1;
	}

}
