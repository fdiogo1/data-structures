#include <stdio.h>
#include <stdlib.h>

void destroyVector(int **v);
/*
    Vetores = a forma mais simples de estruturarmos uma lista de elementos é por meio de vetores/arrays;

    int v[10]
        -> Um vetor de inteiros dimensionado com 10 elementos;
        -> Reservamos um espaço de memória CONTÍNUO p/ armazenar 10 valores inteiros;
        -> Se cada int ocupa 4 bytes, a declaração reserva um espaço de memória de 40 bytes
        -> Vai de v[0] até v[9] -> ATENÇÃO: v[10] invade outra região de memória 

        -> O símbolo v é uma consta que representa o endereço inicial do vetor.
        -> Logo, sem indexação, v aponta (guarda a referência) para o primeiro elemento do vetor
            * &v = v = &v[0]
        -> v[1] = v+1 = *(v+1) -> a partir do endereço v, desloque 1* a quantidade de bytes desse tipo, no caso 1*4
        -> v[3] = *(v+3) = endereço base v + 3*4 (bytes)
        -> v é quase um ponteiro, mas não é. Para ser, ele precisaria ter um endereço próprio, e ele na verdade compartilha o endereço com a 1ª posição, v[0].
*/

int main(void)
{
    int v[] = {0, 1, 2, 3, 4};

    int *p = (int*) calloc(4, sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        p[i] = 2*i;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("&v[%i] = %p, v[%i] = %i\n", i, &v[i], i, v[i]);
    }
    printf("&v[6] = %p, v[6] = %i\n", &v[6], v[6]);

    puts("TESTE ->\n");


    printf("*(v+0) =  v[0] = %i\n", *(v+0));
    printf("*(v+1) =  v[1] = %i\n", *(v+1));
    printf("*(v+2) =  v[2] = %i\n", *(v+2));
    printf("*(v+3) =  v[3] = %i\n", *(v+3));
   
    puts("");
   
    printf("*(p+0) = p[0] = %i\n", *(p+0));
    printf("*(p+1) = p[1] = %i\n", *(p+1));
    printf("*(p+2) = p[2] = %i\n", *(p+2));
    printf("*(p+3) = p[3] = %i\n", *(p+3));

    destroyVector(&p);
    p = NULL;
    puts("end");
}

void destroyVector(int **v)
{
    int *aux = *v;
    free(aux);
    *v = NULL;
    puts("destroyed.");
}