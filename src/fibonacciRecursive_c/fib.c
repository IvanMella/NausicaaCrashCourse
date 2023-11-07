/******************************************************************************

Implementa la serie di fibonacci in modo ricorsivo.

*******************************************************************************/
#include <stdio.h>
int fibonacci (int n);
int main()
{
    printf("fibonacci: %d", fibonacci(500));

    return 0;
}
int fibonacci (int n)
{
    if(n == 1)
        return 1;

    if(n == 0)
        return 0;

    return (fibonacci(n - 1) + fibonacci(n - 2));
}
