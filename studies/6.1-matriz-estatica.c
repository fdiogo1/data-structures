#include <stdio.h>

/*
    Matrizes
        -> Alocação estática (quando alocamos na stack)
            int m[2][3]; linhas x colunas; m também é um "pseudo-ponteiro" -> divide endereço com o m[0][0]
            int m[2][3] = {{0, 1, 2}, {3, 4, 5}};
                            linha 0  - linha 1


*/

int main(void)
{
    int n_rows = 2; // numero de linhas
    int n_cols = 3; // numero de colunas

    int m[2][3] = { {0, 1, 2}, 
                    {3, 4, 5} }; // também pode pular a linha também (puro estilo)

    printf("&m = %p, m = %p\n\n", &m, m); 

    for(int i = 0; i < n_rows; i++) // percorrendo as linhas
    {
        for(int j = 0; j < n_cols; j++) // percorrendo as colunas
        {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
            puts("");
        }
    }



}