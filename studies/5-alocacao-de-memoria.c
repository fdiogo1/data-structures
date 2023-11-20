#include <stdio.h>
#include <stdlib.h> // biblioteca necessária p/ fazer as alocações dinâmicas

/*
    MEMÓRIA RAM -> basicamente, pode ser divida em 2 partes: stack e heap

                                                                     ________________                
                                                                    |                |   
                                                                    |                |     A heap é bem maior que a stack
                                                                    |      HEAP      |
                                                                    |________________|
                                                                    |                |
                                                                    |     STACK      |
                                                                    |________________|                

        Alocação estática: (STACK)
            * O espaço p/ variáveis é reservado no início da execução
            * Cada variável tem seu endereço fixado na memória ocupada por ela se mantém constante durante toda a execução
            * São alocadas na STACK da memória RAM.
            * Liberação de memória feita automaticamente pelo compilador. (ao final da execução)
            * TODA variável que declaramos é alocada na memória STACK.
        
        Alocação dinâmica: (HEAP/free store)
            * O espaço para as variáveis é alocado dinamicamente durante a execução do programa.
            * Pode ser criada ou eliminada durante a execução do programa, ocupando espaço na memória apenas enquanto está sendo utilizado.
            * São alocadas na heap (free store)
            * Liberação de memória feita manualmente pelo programador... PERIGO!
            
                int *a = (int *) malloc(10*sizeof(int))
                float *b = (float *) calloc(5, sizeof(float));
                free(a);
                free(b);
            
            * Por que usar?
                -> A alocação dinâmica é o processo que aloca memória em tempo de execução
                -> Ela é utilizada quando não se sabe ao certo quanto de memória será necessário para o armazenamento dos elementos
                -> Assim, o tamanho de memória necessário é determinado conforme necessidade
                -> Dessa forma evita-se o desperdício de memória
                -> size(heap) >> size(stack)

            * malloc
                -> memory allocation
                -> aloca um bloco de bytes consecutivos na memória heap e devolve o endereço desse bloco

                    tipo *v = (tipo *) malloc(n * sizeof(tipo));
                                opc.        tam. total
                
                -> retorna o endereço de memória base da região da heap (bloco)
                obs: o *v é alocado na stack, e aponta p/ o endereço alocado na heap.

            * calloc
                -> aloca um bloco de bytes consecutivos na memória heap e INICIALIZA todos os valores com o 0 (NULL para ponteiros) - diferença pro malloc
                
                    tipo *v = (tipo *) calloc(n, sizeof(tipo));
                                opc.        2 parametros
                                      num de elementos e o tamanho

                        obs: o *v é alocado na stack, e aponta p/ o endereço alocado na heap.
                            ele é um ponteiro de fato, diferente da alocação estática, onde ele "comapartilha" o endereço com o v[0].

                -> também retorna o endereço base da região alocada



*/

int main(void)
{
    // alocação de um vetor estático (memória stack)
    int vs[5] = {0, 10, 20, 30, 40};

    puts("vs é um pseudo-ponteiro");
    printf("&vs = %p, vs = %p\n\n", &vs, vs);
    puts("##### VETOR ESTATICO");
    for(int i = 0; i < 5; i++)
    {
        printf("&vs[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
    }
    puts("");


    puts("##### VETOR DINAMICO COM MALLOC");
    // alocação de um vetor dinâmico usando malloc (memória heap)

    int *vh_mal = (int*) malloc(5*sizeof(int)); // todos os elementos possuem lixo de memória (nao sao inicializados)

    printf("&vh_mal = %p, vh_mal = %p\n\n", &vh_mal, vh_mal);
    for(int i = 0; i < 5; i++)
    {
        printf("&vh_mal[%d] = %p, vh_mal[%d] = %d\n", i, &vh_mal[i], i, vh_mal[i]);
    }
    puts("");

    puts("##### VETOR DINAMICO COM CALLOC");
    // alocação de um vetor dinâmico usando calloc (memória heap)
    // todo o bloco alocado possui bits 0, isto é
    // garante que todos os elementos alocados do vetor terão valor 0 (ou NULL);

    int *vh_cal = (int*) calloc(5, sizeof(int));

    printf("&vh_cal = %p, vh_cal = %p\n\n", &vh_cal, vh_cal);
    for(int i = 0; i < 5; i++)
    {
        printf("&vh_cal[%d] = %p, vh_cal[%d] = %d\n", i, &vh_cal[i], i, vh_cal[i]);
    }
    puts("");

    // não estamos desalocando os vetores dinâmicos
}