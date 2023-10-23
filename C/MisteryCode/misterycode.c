/************************************************************************
 * Mistery code:							*
 * 									*
 * Cosa fa questo codice ??						*
 *									*
 * Cerca di descrivere il funzionamento di ogni singola istruzione..	*
 * Difficile? Forse non molto.						*
 *									*
 * VIETATO COMPILARE ED ESEGUIRE EH! ;)					*
 * (vabbe' dai solo in caso di estrema necessita)			*
 *							       		*
 *@2023 Ivan Mella.							*
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main ()
{
	long l[4] = {7016998998979731790,8316303949823418412,
		8391162072903215459,11605483225948527};

	char * s_ptr = (char *) &l;
	// long * s_ptr = &l;

	/* Printf:  L'equivalente  C  di  cout.  Anche  se  un  po  piu	*
	 * croccantino,  permette di stampare nello stdout (lo schermo)	*
	 * valori numerici e stringhe  con  un formato specificato. Nel	*
	 * caso qui di seguito '%s' e' lo  "specifier" (identificatore)	*
	 * che  viene sostituito dal contenuto di una variabile  mentre *
	 * '\n' e' l' endl (line feed). 's_ptr in fine e' la variablile *
	 * da stampare							*/
	printf("%s\n", s_ptr);
}
