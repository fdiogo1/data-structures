#include <stdio.h> // h = header;
#include <stdlib.h>

/* 
int = 4 bytes = 32 bits (1 byte = 8 bits)
& = representa um endereço de memória
int a {&a = 3024 (ocupa o 3024, 3025, 3026, 3027)}
// int b {&b = 3028 (endereço BASE)}
*/


int main()
{
    int a = 10;
    int b, c;

    printf("&a = %p, a = %d\n", &a, a); // %p = flag para imprimir ENDEREÇO
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);

    b = 20;
    c = a + b;

    printf("&a = %p, a = %d\n", &a, a); // %p = flag para imprimir ENDEREÇO
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n\n", &c, c);

    return 0;
}