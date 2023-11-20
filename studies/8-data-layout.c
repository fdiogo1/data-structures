#include <stdio.h>
#include <stdblib.h>
/*
    Layout de dados:
        -> são estratégias p/ armazenar arrays multidimensionais de forma linear na memória RAM -> layout e dados
        -> é importante saber o layout dos dados usado para passar corretamente arrays entre programas escritos em diferentes linguagens de programação
        -> é também importante por questões de desempenho/performance
            * CPUs processam dados sequenciais mais eficientemente do que dados não sequenciais -> CPU caching
            * Cache da CPU: memória de acesso extremamente rápido pro consumo da CPU; é pequena
            * O C/C++ utiliza o layout "Row-Major Order".
        
        -> O que muda pro Row-Major pro Column-Major? -> a ordem para percorrer, está relacionado com a memória cache
        -> A cache vai na memória RAM e cria uma cópia de dados contíguos àquele que pedimos, então ela já vai possuir a próxima informação que pedirmos, 
        acesso mais rápido.
        -> Se alterarmos o caminho para percorrer, não vai adiantar essa cópia. Basicamente isso.


        Alocação Dinâmica: Vetor como Matriz -> evitar buracos na memória -> espaços contíguos na heap
            -> para garantir uma matriz dinâmica com elementos contíguos na memória RAM, podemos tratar um vetor como matriz:
                        int *m = (int*) calloc(nrows*ncols, sizeof(int));

                        Não é mais possível acessar os elementos pelos índices de linha e coluna
                        Então, como acessar [i][j]?
                            * [i][j] ---> [p]
                            * p será = (i*ncols) + j
                              


*/
int** create_int_matrix(size_t nrows, size_t ncols);

int main(void)
{
    int nrows = 10;
    int ncols = 10;
    int **m = create_int_matrix(nrows, ncols);

    for(int i = 0; i < nrows; i++)
    {
        for(int j = 0; j < ncols; j++)
        {
            m[i][j] = (i + j) % 2; // resto da divisão por 2;
        }
    }
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