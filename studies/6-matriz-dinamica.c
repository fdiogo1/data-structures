#include <stdio.h>
#include <stdlib.h>

/*
    Matrizes
        Alocação dinâmica -> aloca uma matriz na memória Heap;
        Queremos um Vetor de Vetores/Array de Arrays
*/

int main(void)
{
    int nrows = 2, ncols = 3;

    /*************** ALOCAÇÃO DINÂMICA DE MATRIZES ***************/
    int **m = (int**) calloc(nrows, sizeof(int*));

    // p/ cada linha da matriz...
    for(int i = 0; i < nrows; i++)
    {
        m[i] = (int*) calloc(ncols, sizeof(int)); 
    }
    /************************************************************/

    int count = 0;

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int i = 0; i < nrows; i++)
    {
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
        for(int j = 0; j < ncols; j++)
        {
            m[i][j] = count++;
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }

    /********************** DESALOCANDO MATRIZ DINAMICA **********************/
    for(int i = 0; i < nrows; i++) free(m[i]);

    free(m);
    m = NULL; // -> boa prática
    /*************************************************************************/
}