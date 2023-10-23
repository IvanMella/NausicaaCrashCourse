/************************************************************************
 * Unmistery code:							*
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "Nausicaa, guarisci presto!!! ;)";
	long l[4];

	long * l_ptr = (long*) str;

	for(int i = 0; i < 4; i++)
		printf("%li\n", *l_ptr++);
}
