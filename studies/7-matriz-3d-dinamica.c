#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // a ideia é criar um cubo -> uma matriz tridimensional
    // m[deep][nrows][ncols]

    int deep = 2; // profundidade
    int nrows = 2; // linhas 
    int ncols = 3; // colunas

    // alocação dinamica - 2 fatias, 2 linhas, 2 colunas

    /*************** ALOCAÇÃO DINÂMICA DE MATRIZES ***************/
    int ***md = (int***) calloc(deep, sizeof(int**));

    // para cada fatia
    for(int k = 0; k < deep; k++)
    {
        md[k] = (int**) calloc(nrows, sizeof(int*));

        // para cada linha
        for(int i = 0; i < ncols; i++)
        {
            md[k][i] = (int*) calloc(ncols, sizeof(int));
            
        }
    }

    /************************************************************/

    int count = 0;

    printf("&md = %p, md = %p\n\n", &md, md);
    // para cada fatia
    for(int k = 0; k < deep; k++)
    {
        printf("&md[%d] = %p, md[%d] = %p\n", k, &md[k], k, md[k]);
        // para cada linha
        for(int i = 0; i < nrows; i++)
        {
            printf("&md[%d][%d] = %p, md[%d][%d] = %p\n", k, i, &md[k][i], k, i, md[k][i]);
            // para cada coluna
            for(int j = 0; j < ncols; j++)
            {
                md[k][i][j] = count++;
                printf("&md[%d][%d][%d] = %p, md[%d][%d][%d] = %d\n", k, i, j, &md[k][i][j], k, i, j, md[k][i][j]);
            }
            puts("");
        }
        puts("");
    }

    /********************** DESALOCANDO MATRIZ 3D DINAMICA **********************/
    for(int k = 0; k < deep; k++) 
    {
        for(int i = 0; i < nrows; i++)
        {
            free(md[k][i]);
        }
        free(md[k]);
    }
    free(md);
    md = NULL;
    /****************************************************************************/
}    