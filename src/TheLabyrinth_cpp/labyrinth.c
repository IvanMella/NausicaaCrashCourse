/* The Labyrinth.							*
 * Il malefico  Ivangor ha rinchiuso con un potente maleficio la povera *
 * Nausicaa  in  un  intricato labirinto. Riuscirà la nostra paladina a	*
 * fuggire con il solo aiuto del suo calcolatore? 			*
 * Ivan M. @23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


/* Struttura del gioco							*/
typedef struct thelabyrinth {
	char *walls;
	int nauX;
	int nauY;
	int width;
	int height;
	unsigned long size;
} labyrinth;

/* Converte le coordinate nella posizione sul vettore			*/
int xytolab (int x, int y, int width)
{
	return x + (y * (width + 1));
}

/* Converte la posizione sul vettore in coordinate			*/
int labtoxy (labyrinth *l, int pos)
{
	l->nauY = pos / (l->width + 1);
	l->nauX = pos % (l->width + 1);
}

/* Stampa il labirinto							*/
void printlab(labyrinth *l)
{
	for(unsigned long i = 0; i < l->size; i++ )
		printf("%c", l->walls[i]);
}


/* funzione di appoggio move:						*
 * Aggiorna la posizione di nausicaa nel labirinto modificando le 	*
 * coordinate in modo corrispondente 0 = su, 1 = dx, 2 = giu, 3 =sx	*
 * restituisce 0 se la mossa e' stata fatta oppure -1 se la mossa e' 	*
 * impossibile.								*
 * Se la mossa e' stata fatta lascia un '*' nella cella precedente	*
 * Termina il gioco se si e' raggiunta la fine del labirinto		*
 * (labirinto, mossa, x , y, larghezza)					*/
int move(labyrinth *l, int m)
{
	int x = l->nauX;
	int y = l->nauY;

	switch (m)
	{
		case 0:
			y--;
			break;
		case 1:
			x++;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
	}

	int pos = xytolab(x, y, l->width);

	if (l->walls[pos] == '#')
	{
		l->nauX = x;
		l->nauY = y;
		return -1;
	}
	if (l->walls[pos] == 'F')
	{
		printf("Ce l'hai fatta! Sei riuscita a fuggire!!\n");

		printlab(l);
		exit(0);
	}

	l->walls[pos] == '*';
	return 0;
}

int escapefromlabyrinth(labyrinth *l)
{
	/****************************************************************
	 * qui dentro il tuo codice..					*
	 * **************************************************************/

	// vado di qui.

	// vado di li..

	// torno indietro....

	// move(&l, direction);

	return 0;
}


int main ()
{
	labyrinth lab;
	lab.nauX = 1;
	lab.nauY = 1;
	lab.width = 0;
	lab.height = 0;

	struct stat info;
	const char *filename = "labyrinth_1.txt";

	printf("* * * NAUSICAA'S ESCAPE! * * *\n");


	if (stat(filename, &info) != 0)
	{
		printf("Impossibile trovare il file\n");
		return -1;
	}

	lab.size = (unsigned long)info.st_size;
	printf("FILE SIZE: %lu\n", lab.size);

	lab.walls = malloc(info.st_size);
	if (lab.walls == NULL)
	{
		printf("Impossibile allocare la memoria\n");
		return -1;
	}

	FILE *fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("Impossibile aprire il file\n");
		return -1;
	}

	/* Legge il file in un colpo */
	size_t blocks_read = fread(lab.walls, info.st_size, 1, fp);
	if (blocks_read != 1)
	{
		printf("Lettura del file fallita\n");
		return -1;

	}
	fclose(fp);

	// verifica la labirinticita' del file :)
	if (lab.walls[1] != 0x2e && lab.walls[2] != 0x23 )
	{
		printf("Non e' un labirinto valido!\n");
		return -1;
	}


	/*
	* If nothing went wrong, content now contains the
	* data read from the file.
	*/
	//printf("DATA LENGTH: %lu\n", (unsigned long)info.st_size);


	// Trova la larghezza
	char *s = lab.walls;
	while (*s != 0x0a)
	{
		lab.width++;
		s++;
	}

	//calcola l'altezza
	lab.height = lab.size / (lab.width + 1);

	printf("Larghezza %d, Altezza %d\n", lab.width, lab.height);

	printlab(&lab);

	escapefromlabyrinth(&lab);

	return 0;
}
