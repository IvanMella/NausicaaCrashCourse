/*
* File: main.cpp
* Author: Gabriele
*
* Created on 22 febbraio 2019, 15.04
*/
#include <iostream>

using namespace std;

int swapMerge=0;
void valorizzaVettore(int v[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            v[i/2]=i;
        }
        else
        {
            v[i/2+n/2]=i;
        }
    }
}
void stampaVettore(string messaggio, int v[],int n)
{
	cout<<messaggio;
	for(int i=0;i<n;i++)
	{
		cout<<" "<<v[i];
	}
	cout<<endl;
}
void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for (i=0;i<n1;i++)
	{
		L[i]=arr[l+i];
	}
	for (j=0;j<n2;j++)
	{
		R[j] = arr[m+1+j];
	}

	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			swapMerge++;
			i++;
		}
		else
		{
			arr[k]=R[j];
			swapMerge++;
			j++;
		}

		k++;

	}

	while(i<n1)
	{
		arr[k]=L[i];
		swapMerge++;
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k]=R[j];
		swapMerge++;
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r)
{
	if (l<r)
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

/* argc-> argument  counter,  e'  il numero degli argomenti compreso il	*
 * nome del programma, argv (** perche e' un puntatore a puntatore)  il	*
 * secindo puntatore e' quello che mi permette di eggere tutto il  nome	*
 * che sto puntando.(non serve a nulla perche non viene trattato)	*
 * int main(int argc, char** argv)					*/
int main()
{
	const int n=10;
	int v[n];
	stampaVettore("Vettore di Partenza: ",v,n);
	mergeSort(v,0,n-1);
	cout<<"MergeSort: "<<swapMerge<<" scambi"<<endl;
	stampaVettore("Ordinamento di tipo MergeSort: ",v,n);
	valorizzaVettore(v,n);
}
