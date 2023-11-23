# The Labyrinth
Il malefico  Ivangor ha rinchiuso con un potente maleficio la povera Nausicaa  in  un  intricato labirinto. Riuscirà la nostra paladina a fuggire con il solo aiuto del suo calcolatore?

Nausicaa ha la mappa del labirinto sul suo calcolatore . Lo scopo e' quello di trovare un algoritmo che decida (nel miglior modo possibile) quali direzioni prendere per uscire dal labirinto.

*v1.0 Ivan M. @23*


## Dati di input
E' fornito un file di testo ```labirinth_1.txt``` contenente un labirinto valido di dimensioni pari a  51 x 51.
## Dati di output
Una volta raggiunta la fine Sara' stampato automaticamente a schermo l'intero labirinto con il percorso completo (compresi eventuali tragitti cechi intrapresi).
## Implementazione
Viene fornito il file ```labirinth.c``` su cui lavorare.

Dovrai modificare la funzione ```escapeFromLabyrinth(labyrinth *)``` in modo da produrre gli spostamenti (0 su, 1 destra, 2 giu, 3, sinistra) che attraverso la funzione di appoggio ```move(&l, direction)``` portino alla salvezza!

Tra gli allegati un labirinto da 11x11 e uno da 199x199, rispettivamente ```labyrinth_11x11.txt e labyrinth_199x199.txt```

## Assunzioni
Il caratte '.' del labirinto e' attraversabile.

Il carattere '#' invece e' un muro. ```move()``` non lascera' oltrepassare il carattere '#' rendendo di  fatto ogni tentativo in tal senso vano.

Il carattere 'F' denota l'uscita dal labirinto, una volta raggiunta la funzione move terminera il programma stampando i percorsi fatti.

6 <= sizeof(lab.walls) <= 10000

## Spiegazione
Il programma inizia con una lunga parte dedicata all'apertura , la validazione e del file labirinto. Continua copiando il contenuto del file in un vettore di carattere (raggiungibile dalla struttura lab) e completando la struttura con dati importanti per lo svolgimento del programma, come la posizione di Nausicaa, le dimensioni dell'labirinto e le dimensioni del vettore.

Alla fine , dopo aver stampato a schermo il labirinto da percorrere ``` printlab(&lab); ``` , accede alla funzione ```escapefromlabyrinth(&lab);```
nella quale dovra essere svolto il compito principale del programma. **Fuggire!**


	###########
	#*#...#...#
	#*#.###.#.#
	#*******#.#
	#*#.###*#.#
	#*#...#*#.#
	#*#####*###
	#*****#***#
	###.#*#####
	#...#******
	#########FF
*Nell'esempio un labirinto di 11x11 completato*

## Nota Finale
La regola da seguire e' come al solito *less is more*. Non imballarti a fare lavori stratosferici, concentrati sul solo algoritmo e verificane la bonta' (e la belta') Tutti i fronzoli grafici e stilistici saranno lasciati per future versioni.

Lo studio e la comprensione del codice gia' scritto e' parte dell'esercizio ed e' fondamentale per chiarire tutti quei dettagli che non sono contenuti in questo documento.
