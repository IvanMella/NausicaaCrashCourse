#include <iostream>
#include <fstream>//libreria dei file

using namespace std;

int main() {

    int N , M , A , B ;

    // Apertura del file
    ifstream inputFile("input.txt");

    // Lettura dei valori dal file
    inputFile >> N >> M >> A >> B;

    // Chiusura del file
    inputFile.close();

    cout << "Numero dei viaggi che deve fare Gabriele: " << N << endl;
    cout << "Numero di viaggi disponibili per carnet : " << M << endl;
    cout << "Centesimi per una singola corsa: " << A << endl;
    cout << "Centesimi per carnet: " << B << endl;

    int risultato;

    ifstream inputFile2("output.txt");
    inputFile >> risultato;
    inputFile2.close();

    cout<< "il risultato corretto e: " << risultato <<endl;

    int X=0;
    int Z=M;
    while ( N > M)
	{
	    X++;
	    M=M+Z;
	}



    int cost1 = N * A;
    int cost2 = X * B;
    int cost3 =0;

    int minimo = cost1;

    if (cost2 < minimo)
    {
        minimo = cost2;
    }
    else if(cost3 < minimo)
    {
        minimo = cost3;
    }

    cout << "il tuo risultato e' : " << minimo << endl;

    if(minimo==risultato)
	{
	    cout << "il tuo risultato e'corretto" <<endl;
	}
    else
	{
	    cout<< "hai sbagliato, il risultato corretto era : " << risultato
	    << endl;
	}

    return 0;
}
