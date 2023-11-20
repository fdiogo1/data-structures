#include <stdio.h>
#include <stdlib.h>

void soma_vetor_com_escalar(int *v, int size, int k);
void imprime(const double v[], int size);
void desalocar(int **v);
double* alocar1(int size);
void alocar2(double **v, int size);

int main(void)
{
    //puts("==> VETOR ESTATICO");
    //int vs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //imprime(vs, 10);

    //soma_vetor_com_escalar(vs, 10, 5);
    //imprime(vs, 10);

    //puts("==> VETOR DINAMICO");
    //int *vh = (int*) calloc(5, sizeof(int)); // um array (já inicializado) com 5 inteiros.
    //imprime(vh, 5);
    //soma_vetor_com_escalar(vh, 5, 3);
    //imprime(vh, 5);

    //puts("==> ANTES DA FUNCAO DE DESALOCAR VETOR DINAMICO");
    //printf("&vh = %p, vh = %p\n", &vh, vh);

    // desalocando o vetor dinâmico
    //desaloca_vetor(&vh);
    //puts("==> DEPOIS DA FUNCAO DE DESALOCAR VETOR DINAMICO");
    //printf("&vh = %p, vh = %p\n", &vh, vh);

    int N;
    puts("Digite o tamanho: ");
    scanf("%d", &N);
    double *teste;

    // teste = alocar1(N); // alocando por passagem de valor
    alocar2(&teste, 5); // alocando por passagem de referência

    imprime(teste, N);

    free(teste);
    teste = NULL;

}

// passando vetores como parâmetros

void soma_vetor_com_escalar(int *v, int size, int k)
{
    for(int i = 0; i < size; i++)
    {
        *(v+i) += k; // ou v[i] mesmo.
    }
}

void imprime(const double v[], int size) // ou *v; o const previne, pra deixar somente em leitura
{
    for(int i = 0; i < size; i++)
    {
        printf("v[%d] = %d\n", i, *(v+i));
    }
}

void desalocar(int **v)
{
    int *aux = *v;
    free(aux);
    *v = NULL;
}

double* alocar1(int size) // double*, pois irá retornar um ponteiro de um double
{   
    double *v;
    v = (double*) calloc(size, sizeof(double));

    puts("Alocado com sucesso, pela passagem de valor.");
    return v; // retorna o ponteiro, o endereço base do início na heap.
}

void alocar2(double **v, int size)
{
    *v = (double*) calloc(size, sizeof(double)); // acessa o conteúdo por referência.
    puts("Alocado com sucesso, por referência");
}