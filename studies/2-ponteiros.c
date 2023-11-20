#include <stdio.h>
#include <stdlib.h>

/*
ponteiro = tipo de dado. ao invés de armazenar uma variável, ele guarda ENDEREÇOS DE MEMÓRIA
um ponteiro APONTA para uma região de memória. ele está apontando para uma região de memória.
todo ponteiro, i.e, endereços de memória, ocupam 8 bytes na memória
*/

int main()
{
    int a = 10;
    int *p1 = NULL;
    int *p2 = NULL;
    int **t;

    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p\n", &p1, p1);
    printf("&p2 = %p, p2 = %p\n\n", &p2, p2);

    p1 = &a;
    p2 = p1; // p2 aponta para onde p1 está apontando, no caso, a.
    *p2 = 4; // o conteúdo do local onde p2 aponta passa a ser 4. O valor de "a" foi alterado, sem "a" ser citado.

    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
    printf("&p2 = %p, p2 = %p, *p2 = %d\n\n", &p2, p2, *p2);

    // é possível um ponteiro apontar para outro ponteiro.
    // ex:
    //    int *p1;
    //    int **p2;
    //    p2 = &p1;

    t = &p2;

    printf("&p2 = %p, t = %p, &t = %p, **t = %d\n", &p2, t, &t, **t); // **t é o conteudo final. É possível alterar o valor também.
    printf("&t = %p, t = %p, *t = %p, **t = %d\n\n", &t, t, *t, **t);
}