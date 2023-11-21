/* The Labyrinth.							*
 * Il malefico  Ivangor ha rinchiuso con un potente maleficio la povera *
 * Nausicaa  in  un  intricato labirinto. Riuscirà la nostra paladina a	*
 * fuggire con il solo aiuto del suo calcolatore? 			*
 * Ivan M. @23
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// converte le coordinate nella posizione sul vettore
int xytolab (int x, int y, int width)
{
	return x + y * (width + 1);
}

// converte la posizione sul vettore in coordinate
void labtoxy (int l, int *x, int* y, int width)
{
	*y = l / (width + 1);
	*x = l % (width + 1);
}


/* funzione di appoggio move:						*
 * Aggiorna la posizione di nausicaa nel labirinto modificando le 	*
 * coordinate in modo corrispondente 0 = su, 1 = dx, 2 = giu, 3 =sx	*
 * restituisce 0 se la mossa e' stata fatta oppure -1 se la mossa e' 	*
 * impossibile.								*
 * Se la mossa e' stata fatta lascia un '*' nella cella precedente	*
 * Termina il gioco se si e' raggiunta la fine del labirinto		*
 * (labirinto, mossa, x , y, larghezza)					*
 */
int move(std::vector<char>* lab, int m, int *x, int *y, int width)
{
	int xtmp = *x;
	int ytmp = *y;

	switch (m)
	{
		case 0:
			*y--;
			break;
		case 1:
			*x++;
			break;
		case 2:
			*y++;
			break;
		case 3:
			*x--;
	}
	int pos = xytolab(*x, *y, width);
	if (pos == '#')
	{
		*x = xtmp;
		*y = ytmp;
		return -1;
	}
	if (pos == 'F')
	{
		std::cout << "Ce l'hai fatta! Sei riuscita a fuggire!!" << std::endl;

		// Stampa il labirinto;
		for(auto i : *lab)
			std::cout << i;
		exit(0);
	}
	*lab = '*';
	return 0;
}

int escapefromlabyrinth(std::vector<char> *lab, int width)
{
	// qui dentro il tuo codice..
	int x = 1, y = 1, mossa;


	move(lab, mossa, &x, &y, width);

	return 0;
}


int main ()
{
	std::ifstream file("labyrinth_1.txt", std::ios::binary | std::ios::ate);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<char> buffer(size);

	if (!file.read(buffer.data(), size)) return -1;

	auto width = 0, height = 0;

	// verifica la labirinticita' del file :)
	if (buffer[1] != 0x2e && buffer[2] != 0x23 )
	{
		std::cout << "Non e' un labirinto valido!" << std::endl;
		return -1;
	}

	// Trova la larghezza
	for(auto i : buffer)
	{
		if (i == 0x0a) break;
		width++;
	}

	//calcola l'altezza
	height = size / width;

	std::cout << width << std::endl;
	std::cout << size / width << std::endl;

	escapefromlabyrinth(&buffer, width);

	return 0;
}
