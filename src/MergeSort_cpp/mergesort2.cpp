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

void mergeSort(int * array, int left,int right);
void merge(int * array, int left, int middle, int right);

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

	const int n = 4;
	int v[n];

	riempiVettore(v,n);

	stampaVettore("Vettore di Partenza: ",v,n);

	mergeSort(v, 0, n - 1);

	cout << "MergeSort: " << swapMerge << " scambi" << endl;

	stampaVettore("Ordinamento di tipo MergeSort: ", v, n);

	return 0;
}

void riempiVettore(int *array,int size)
{
	/* che bislaccheria mer*osa!
	for(int i = 0; i < size; i++)
	{
		if(i % 2 == 0)
			array[i / 2] = i;
		else
			array[i / 2 + size / 2] = i;
	}
	*/
	int half = size / 2;
	int i;
	for(i = 0; i < half; i++)
	{
		array[i] = i * 2;
		array[i + half] = i * 2 + 1;
	}
	if (size & 1)
 		array[i + half] = i * 2 + 1;

}

void stampaVettore(string message, int * array, int size)
{
	cout << message;
	for(int i = 0; i < size; i++)
		cout << " " << array[i];
	cout << endl;
}

void merge(int * array, int left, int mid, int right)
{
	int i = 0;
	int sizL = mid - left + 1;
	int sizR = right - mid;

	cout << "left: " << left << " mid: " << mid
	<< " right: " << right<< " sizL: " << sizL
	<< " sizR: " << sizR << endl;
	/* Brutto. allocazione dinamica della memoria sullo stack. Non 	*
	 * funzionera' per grandi numeri'				*/
		//int runL[sizL], runR[sizR];

	/* Meglio, (la keyword auto deduce il tipo di dato dal R-value	*
	 * in questo caso int)						*/
	auto	*runL = new int[sizL],
		*runR = new int[sizR];

	/* Copia il vettore nei due vettori di appoggio	in modo		*
	 * efficiente e pulito						*/
	for (i = 0; i < sizR; i++)
	{
		runL[i] = array[i + left];
		runR[i] = array[i + mid + 1];
	}
	/* Se right - left e' pari manca l'ultimo valore da copiare	*/
	if ((right - left) % 2 == 0)
		runL[i] = array[mid];

	stampaVettore("runL: ", runL, sizL);
	stampaVettore("runR: ", runR, sizR);

	i = 0;
	int j = 0;
	int k = left;

	/* Riporta i dati nel vettore array (da sinistra a destra)	*/
	while(i < sizL && j < sizR)
	{
		if(runL[i] <= runR[j])
		{
			array[k] = runL[i];
			swapMerge++;
			i++;
		}
		else
		{
			array[k] = runR[j];
			swapMerge++;
			j++;
		}
		k++;
	}

	/* Se ce ne sono, copia gli elementi restanti di sinistra	*/
	while(i < sizL)
	{
		array[k] = runL[i];
		swapMerge++;
		i++;
		k++;
	}

	/* Se ce ne sono, copia gli elementi restanti di destra		*/
	while(j < sizR)
	{
		array[k] = runR[j];
		swapMerge++;
		j++;
		k++;
	}

	/* dealloca la memoria						*/
	delete runL;
	delete runR;
}

void mergeSort(int * array,int left, int right)
{
	if (left < right)
	{

		int mid = (left + right) / 2;

		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}
