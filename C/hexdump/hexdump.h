#ifndef HEXDUMP_H
#define HEXDUMP_H

/* void hexdump (char * Titolo, void * Indirizzo, int Lunghezza)
 * Stampa i bytes di memoria su tre colonne.  A sinistra l'indirizzo relativo
 * in  esadecimale,  al  centro i bytes  in  esadecimale a destra i caratteri 
 * ASCII. Titolo  e'  un  etichetta  che  viene stampata prima di ogni  dump.
 * Lunghezza  e' il numero di caratteri da stampare dall'inizio della stringa 
 */


void hexdump (char*, void *, int);


#endif
