/************************************************************************
 * Implementare i tre algoritmi:					*
 *    - Ricerca sequenziale						*
 *    - Ricerca sequenziale ottimizzata (si ferma alla prima occorrenza *
 *  	della chiave di ricerca)					*
 *    - Ricerca binaria dicotomica					*
 *									*
 * Valorizzare  un  array  in  modo  che  gli elementi siano ordinati	*
 * in ordine crescente.							*
 *									*
 * Richiamare  i  3  metodi  sul  vettore  (variandone  di  volta  in	*
 * volta la dimensione) e annotare i tempi. Fare attenzione al tipo di	*
 * ricerca (caso ottimo, medio e pessimo)				*
 *									*
 * Realizzare uno o più grafici di confronto dei 3 algoritmi.		*
 ************************************************************************/

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	const int n = 100000000;
	int v[n];
	int n_ricerca, mid, pos, left, right;
	int i = 0;
	clock_t begin, end;
	float tempo, tempo1, tempo2;
	float gScaleFactor = .01;


	srand(time(NULL));

	/* Assegno il  primo  elemento  del  vettore, poi per tutti gli	*/
	/* altri  creo  un   valore   che  e'  pari   alla   somma  del	*/
	/* precedente piu un numero casuale da 1 a 10			*/
	v[0] = rand() % 10 + 1;
	for(int i = 1; i < n; i++)
		v[i] = v[i - 1] + rand() % 10 + 1;

	/* Stampo tutto il vettore sullo stdout meno l'ultimo elemento	*/
	/* poi stampo l'ultimo elemento con un carattere di a capo	*/
//	for(int i = 0; i < n - 1; i++)
//		cout << v[i] << ", ";
//	cout << v[n - 1] << endl;

	/* Inserimento da tastiera (stdin)				*/
	cout << "Inserire il numero che si vuole ricercare: ";
	cin >> n_ricerca;

	/****************************************************************/
	/*			Ricerca sequenziale			*/
	/****************************************************************/

	/* Inizio il conteggio dei clock ticks				*/
	begin = clock();

	/* Finche  l' elemento  del  vettore  e'  diverso  da n_ricerca	*/
	/* incremento i 						*/
	while(n_ricerca != v[i] && i < n)
		i++;

	end = clock();
	tempo = 1000000.0 * ((double)(end - begin)) / CLOCKS_PER_SEC;

	/* Se non ho raggiunto la fine del  vettore vuol  dire  che  il	*/
	/* numero c'e' e si trova all'i-esima posizione  altrimenti  il	*/
	/* numero non e' stato trovato.					*/
	cout << "Seq: Il numero " << n_ricerca;
	if(i < n)
		cout << " è stato trovato nella posizione " << i;
	else
		cout << " non è stato trovato";

	/* Stampo il tempo impiegato 					*/
	cout << ". Tempo impiegato: " << tempo << "us" << endl;

	/****************************************************************/
	/*		Ricerca sequenziale ottimizzata			*/
	/****************************************************************/

	/* Inizio il conteggio dei clock ticks				*/
	begin = clock();

	/* i deve esssere reinizializzato a 0				*/
	i = 0;

	/* finche' il numero e' piu piccolo del numero nel vettore e il */
	/* vettore non e' finito.. .. incrementa i			*/
	while( n_ricerca > v[i] && i < n)
		i++;

	/* Fermo il conteggio  dei  clock  ticks  e  Calcolo  il  tempo */
	/* impiegato							*/
	end = clock();
	tempo1 = 1000000.0 * ((double)(end - begin)) / CLOCKS_PER_SEC;

	/* Se  il   numero  e' uguale ad un valore nel  vettore  allora */
	/* il numero c'e' e si trova all' i-esima posizione, altrimenti */
	/* se i raggiunge la fine del  vettore  significa  che  non  e' */
	/* stato trovato.						*/
	cout << "Ott: Il numero " << n_ricerca;
	if(n_ricerca == v[i])
		cout << " è stato trovato nella posizione " << i;
	else
	{
		/* Evita che v[i] stampi un valore fuori dall'array	*/
		if (i == n) i = n - 1;

		cout << " non è stato trovato prima del numero " << v[i];
	}

	/* Stampo il tempo impiegato 					*/
	cout << ". Tempo impiegato: " << tempo1 << "us" << endl;

	/****************************************************************/
	/*			Ricerca Binaria				*/
	/****************************************************************/

	/* left  e'  il  primo  elemento  (a sx del vettore),  right e'	*/
	/* l' ultimo a destra, pos e' il valore sentinella. 		*/
	left = 0;
	right = n - 1;
	pos = -1;

	/* Inizio il conteggio dei clock ticks				*/
	begin = clock();

	/* 'do', diversamente da while, esegue almeno una volta 	*/
	/* l'iterazione.						*/
	do
	{
		/* mid si posiziona al centro del vettore		*/
		mid = (left + right)/2;

		/* se  il   valore   centrale  corrisponde  al   numero	*/
		/* ricercato pos assume il valore di mid e  la  ricerca	*/
		/* termina. YAY!					*/
		if(v[mid] == n_ricerca)
			pos = mid;

		/* Se il numero e'  maggiore di  v[mid]  la  ricerca si	*/
		/* spostera'  sulla   porzione   a   sinistra   di  mid	*/
		/* semplicemente impostando left '1a pos destra' di mid.*/
		else if (n_ricerca > v[mid])
			left = mid + 1;

		/* se  invece  il  numero  e'  piu  piccolo,  l'ultimo 	*/
		/* elemento a destra, sara impostato a '1a pos sinistra */
		/* di mid. 						*/
		else
			right = mid - 1;

	/* ripete finche il vettore non collassa o  il  numero  non  e'	*/
	/* stato trovato						*/
	} while(left <= right && pos == -1);	// ....

	/* Fermo il conteggio  dei  clock  ticks  e  Calcolo  il  tempo */
	/* impiegato							*/
	end = clock();
	tempo2 = 1000000.0 * ((double)(end - begin)) / CLOCKS_PER_SEC;

	/* stampo sullo stdout						*/
	cout << "Bin: Il numero " << n_ricerca;

	/* se pos e' stato modificato il numero e' stato trovato	*/
	if(pos != -1)
		cout << " è stato trovato nella posizione "<< pos;

	/* altrimenti non c'e'						*/
	else
		cout<<" non è stato trovato";

	/* Stampo il tempo impiegato 					*/
	cout << ". Tempo impiegato: " << tempo2 << "us" << endl;


	/****************************************************************/
	/*			Grafico	 :D Lol				*/
	/****************************************************************/

	cout << endl << "---- Grafico Brutto ---" << endl << "Seq: *";
	pos = (int)tempo * gScaleFactor;
	for(i = 0; i < pos; i++)
		cout << "*";
	cout << " " <<  tempo <<"us"<< endl;

	cout << "Ott: *";
	pos = (int)tempo1 * gScaleFactor;
	for(i = 0; i < pos; i++)
		cout << "*";
	cout << " " <<  tempo1 <<"us"<< endl;

	cout << "Bin: *";
	pos = (int)tempo2 * gScaleFactor;
	for(i = 0; i < pos; i++)
		cout << "*";
	cout << " " <<  tempo2 <<"us"<< endl;

	return 0;
}

// TODO
// A cosa serve using
// valore massimo della costante n e stack
// perche definire le variabili all' inizio del codice
// start -> stop, begin -> end
// casting e la rappresentazione dei dati in memoria.
// precompilatore, compilatore e linker
// strumenti di sviluppo makefile, editors 
