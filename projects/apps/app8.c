#include <stdio.h>
#include "mlibs.h"

#define swap2(A, B) {int t = A; A = B; B = t;}
void swap(int *a, int *b);


int main(void)
{
    int a = 100, b = 150;
    printf("antes: %d %d\n", a, b);
    swap2(a, b);
    printf("depois: %d %d\n", a, b);
    swap(&a, &b);   
    printf("depois de novo: %d %d\n", a, b);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}