#include <stdio.h>

/* void hexdump (char * Titolo, void * Indirizzo, int Lunghezza)
 * Stampa i bytes di memoria su tre colonne.  A sinistra l'indirizzo relativo
 * in  esadecimale,  al  centro i bytes  in  esadecimale a destra i caratteri 
 * ASCII. Titolo  e'  un  etichetta  che  viene stampata prima di ogni  dump.
 * Lunghezza  e' il numero di caratteri da stampare dall'inizio della stringa 
 * stessa..
 */
void hexdump (char *title, void *v, int len)
{

	long addr = (long) v;
	char *s = (char *) v;
	int i, l;
	int block = len - len % 0x10 ;
	printf("\n%s, %d bytes, Ind:0x%lX.\n", title, len, addr);
	
	for(i = 0; i < block; i+= 0x10)
	{
		printf("%08X  ",i);
		
		for (l = i; l < 0x10 + i ; l++)
			printf("%02X ",(unsigned char) s[l]);
			
		printf(" |");
		
		for (l = i; l < 0x10 + i; l++)
			if (s[l] < 0x20 || s[l] > 0x7e)
				printf(".");
			else 
				printf("%c",  s[l]);
		printf("|\n");
	}
	printf("%08X  ",i);
	
		for (l = i; l < len ; l++)
		printf("%02X ",(unsigned char) s[l]);

	for (; l < i + 0x10 ; l++)
		printf("   ");
		
	printf(" |");
	
	for (l = i; l < len; l++)
		if (s[l] < 0x20 || s[l] > 0x7e)
			printf(".");
		else 
			printf("%c",  s[l]);
	printf("|\n");
}
