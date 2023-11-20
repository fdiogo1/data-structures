#include <stdio.h>
#include <stdlib.h>

int** create_int_matrix(size_t nrows, size_t ncols); // size_t = um número muito grande, sem sinal -> basicamente um "unsigned long"
void print_int_matrix(const int **m, int nrows, int ncols);
void add_scalar_int_matrix(int **m, int nrows, int ncols, int scalar);
void destroy_int_matrix(int ***mat, int nrows, int ncols);

int main(int argc, char *argv[]) // arg = argumento; argc = contador de argumentos (quantos argumentos vou passar); argv = value; vetor de valores de argumentos
{
    if(argc != 4)
    {
        printf("ERROR\n%s nrow ncols scalar\n", argv[0]);
        exit(-1); // encerra a execução,
    }

    // o arv[0] sempre será o nome do app (ex: ./hello Diogo Ferreira -> o ./hello é o arg[0])
    int nrows = atoi(argv[1]); // atoi = ASCII to integer; converte uma string para um inteiro
    int ncols = atoi(argv[2]);
    int scalar = atoi(argv[3]);


    // alocação da matriz
    int **m = create_int_matrix(nrows, ncols);

    // atribuição de alguns valores p/ matriz
    int count = 0;
    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncols; j++)
        {
            m[i][j] = count++;
        }
    }
    
    // imprime a matriz
    print_int_matrix((const int**) m, nrows, ncols);
    
    // adiciona escalar
    add_scalar_int_matrix(m, nrows, ncols, scalar);

    // imprime novamente
    print_int_matrix((const int**) m, nrows, ncols); // p/ remover o warning

    destroy_int_matrix(&m, nrows, ncols);

    printf("m is NULL? %d\n", m == NULL);

}

int** create_int_matrix(size_t nrows, size_t ncols)
{
    int **m = (int**) calloc(nrows, sizeof(int*));
    for(int i = 0; i < nrows; i++)
    {
        m[i] = (int*) calloc(ncols, sizeof(int));
    }
    return m;
}

void print_int_matrix(const int **m, int nrows, int ncols)
{
    printf("&m = %p, m = %p\n\n", &m, m);
    for(int i = 0; i < nrows; i++)
    {
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
        for(int j = 0; j < ncols; j++)
        {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }
}

void add_scalar_int_matrix(int **m, int nrows, int ncols, int scalar)
{
    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncols; j++)
        {
            m[i][j] += scalar;
        }
    }
}

void destroy_int_matrix(int ***mat, int nrows, int ncols)
{
    int **aux = *mat;
    for(int i = 0; i < nrows; i++)
    {
        free(aux[i]);
    }
    free(aux);
    *mat = NULL;
}