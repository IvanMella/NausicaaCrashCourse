Sorridere?
Lo stile di programmazione e' molto buono, Il codice e' pulito e intelligibile anche senza commenti (non davano fastidio tuttavia). La cosa che stride di più e' l'uso di string. string non e' un tipo di dato bensì un oggetto, quindi implica una meccanica di processo molto opaca che sicuramente ti sfugge. (lo dico perché se saltano fuori problemi son dolori a risolverli). Bene cout.flush (mi piace tu abbia trovato una diversa soluzione rispetto a ciò che ti avevo suggerito. Infine Adoro il tocco personale che hai dato per avere una diversa temporizzazione per gli spazi ed il punto. Molto bene. Brava.
Si vorrei dire che le cose non le sapevo già di mio le ho cercate in internet le funzioni e le librerie da mettere
ah.. dimenticavo, con sleep_for stai usando smaliziatamente la libreria threads che e' specificatamente progettata per la multiprogrammazione (per il multithreading , il calcolo parallelo) Hai scoperchiato il vaso di Pandora insomma.. 🤭
Aumentare il tempo mi sembrava logico perché una persona normale impiega più tempo a cercare gli spazi e i punti
Aia
Sietye per strada?
*Siete
Siamo a già a fiaschetti
E Umberto:
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    string s = "All work and no play makes Ivan a dull boy";

    while (true)
    {
        for (char c : s)
        {
            cout << c;
            cout.flush();

            if (c != ' ' && c != '.')
            {
                this_thread::sleep_for(chrono::milliseconds(100));
            } else
            {
                this_thread::sleep_for(chrono::milliseconds(400));
            }
        }

        cout << endl;
    }

    return 0;
}
/*
 * File:   main.cpp
 * Author: Gabriele
 *
 * Created on 22 febbraio 2019, 15.04
 */

#include <iostream>

using namespace std;

int swapQuick=0;
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

int bubbleSort(int v[], int n)
 {
    int tmp;
    int scambi=0;
    for(int j=n-1;j>0;j--)
     {
         for(int i=0;i<j;i++)
         {
           if (v[i]>v[i+1])
           {
             tmp=v[i];
             v[i]=v[i+1];
             v[i+1]=tmp;
             scambi++;
           }
         }
     }
    return scambi;
 }

int insertionSort(int arr[], int n)
{
   int scambi=0;
   int i,key,j;
   for(i=1;i<n;i++)
   {
       key=arr[i];
       j=i-1;
       while(j>=0 && arr[j]>key)
       {
           arr[j+1]=arr[j];
           j=j-1;
           scambi++;
       }
       arr[j+1]=key;
       scambi++;
   }
   return scambi;
}

int selectionSort(int v[], int n)
{
    int i,j,minIdx,tmp;
    int scambi=0;

    for(i=0;i<n-1;i++)
    {
        minIdx=i;
        for(j=i+1;j<n;j++)
        {
          if(v[j]<v[minIdx])
          {
              minIdx=j;
          }
        }
        tmp=v[minIdx];
        v[minIdx]=v[i];
        v[i]=tmp;
        scambi++;
    }
    return scambi;
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

int partition(int arr[],int low,int high)
{

    int pivot=arr[high];
    int i=(low-1);
    int tmp;

    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            swapQuick++;
        }
    }
    tmp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=tmp;
    swapQuick++;
    return(i+1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char** argv)
{
    const int n=10;
    int v[n];
    valorizzaVettore(v,n);
    stampaVettore("Vettore di Partenza: ",v,n);
    int swapBubble=bubbleSort(v,n);
    cout<<"BubbleSort: "<<swapBubble<<" scambi"<<endl;
    stampaVettore("Ordinamento di tipo BubbleSort: ",v,n);
    valorizzaVettore(v,n);

    int swapInsertion=insertionSort(v,n);
    cout<<"InsertionSort: "<<swapInsertion<<" scambi"<<endl;
    stampaVettore("Ordinamento di tipo InsertionSort: ",v,n);
    valorizzaVettore(v,n);

    int swapSelection=selectionSort(v,n);
    cout<<"SelectionSort: "<<swapSelection<<" scambi"<<endl;
    stampaVettore("Ordinamento di tipo SelectionSort: ",v,n);
    valorizzaVettore(v,n);

    mergeSort(v,0,n-1);
    cout<<"MergeSort: "<<swapMerge<<" scambi"<<endl;
    stampaVettore("Ordinamento di tipo MergeSort: ",v,n);
    valorizzaVettore(v,n);

    quickSort(v,0,n-1);
    cout<<"QuickSort: "<<swapQuick<<" scambi"<<endl;
    stampaVettore("Ordinamento di tipo QuickSort: ",v,n);
    return 0;
}
