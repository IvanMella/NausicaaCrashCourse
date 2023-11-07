
// rappresentazione dei dati in memoria

#include <stdio.h>
#include <string.h>
#include "../hexdump/hexdump.h"

int main ()
{
	// union mydata
	// {
	// 	char str[8];
	// 	long l;
	// 	double d;
	// };
	//
	// union mydata md;
	//
	// memcpy(md.str, "Nausica", 8);
	//
	// printf("Stringa di testo: %s\n", md.str);
	// printf("%s sei solo un numero!: %d\n", md.str, md.l);
	// printf("%s sei solo un numero!: %f\n", md.str, md.d);

	char str[] = {'N','a','u','s','i','c','a','a'};
	long l = 7016998998979731790;
	double d;

	void * d_Ptr = &l;

	printf("size: %d Stringa di testo: %s\n", sizeof(str), (char *) d_Ptr);
	printf("size: %d come long.. : %li\n", sizeof(l), *(long *) d_Ptr);
	printf("size: %d come double.. : %lf\n", sizeof(d), *(double *) d_Ptr);

	for (int i; i < 8; i++)
		printf("%x ",* (char *) (d_Ptr + i));
	printf("\n");

	hexdump("char str[]", d_Ptr, 8);
	hexdump("long l", str, 8);

	return 0;
}
