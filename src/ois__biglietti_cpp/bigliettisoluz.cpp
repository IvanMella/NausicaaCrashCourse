#include <iostream>
#include <fstream>

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

    int X=B;
    while ( N > M)
	{
	    X=X+B;
	}

    return 0; // Uscita senza errori
}
