#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // a ideia é criar um cubo -> uma matriz tridimensional
    // m[deep][nrows][ncols]

    int deep = 2; // profundidade
    int nrows = 2; // linhas 
    int ncols = 3; // colunas

    // alocação estática - 2 fatias, 2 linhas, 2 colunas
    int me[2][2][3] = 
    {
        {
        // fatia [0]
            {0, 1, 2}, // linhas [0]
            {3, 4, 5} // linha [1]
        },
        // fatia [1]
        {
            {6, 7, 8}, // linha [0]
            {9, 10, 11} // linha [1]
        }
    };
    
    printf("&me = %p, me = %p\n\n", &me, me);

    // para cada fatia
    for(int k = 0; k < deep; k++)
    {
        // para cada linha
        for(int i = 0; i < nrows; i++)
        {
            // para cada coluna
            for(int j = 0; j < ncols; j++)
            {
                printf("&me[%d][%d][%d] = %p, me[%d][%d][%d] = %d\n", k, i, j, &me[k][i][j], k, i, j, me[k][i][j]);
            }
        }
    }
}