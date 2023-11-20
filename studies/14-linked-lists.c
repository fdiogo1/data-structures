#include <stdio.h>
#include <string.h>

/*
    "1º mandamento: Sempre desenhar a estrutura de dados antes de implementá-la, você deve."

    Existem problemas em vetores/arrays:
        * espaço limitado; uma vez declarado, dificulta p/ aumentar/inserir novos elementos
            -> Solução 1: realloc (não indicado)
            -> Solução 2: novo vetor, com uma posição a mais, e copiar os valores do vetor antigo, adicionando o novo.
                - obs: o problema dessa: a cada novo elemento, alocar um novo vetor;
                - copiar dados de um vetor a outro = ineficiente
            -> Solução 3: criar um vetor muito grande, de modo que sempre teremos espaço para inserir um novo aluno;
    
    Solução 4: Listas Encadeadas
        * Uma lista encadeada (ligada) é uma representação  de uma sequência de elementos/objetos na memória
        * Os elementos, nós da lista, são armazenados em posições quaisquer da memória e são ligados por ponteiros
            -> logo, elementos consecutivos da lista não ficam necessariamente em posições consecutivas na memória.
        * Cada nó contem um elemento/objeto de determinado tipo e um ponteiro para o próximo elemento da lista -> Lista Encadeada Simples
        * No caso do último nó, este ponteiro aponta para NULL.
        * Tipos de listas:
            -> lista circulares (o último nó aponta p/ o primeiro, e não p/ NULL);
            -> lista duplamente encadeada (cada nó aponta para o próximo elemento e p/ o anterior)
            -> lista circular duplamente encadeada
                - o primeiro nó aponta para o último nó; o último nó aponta para o primeiro.



                        ARRAY                                       x                            LISTAS ENCADEADAS
                                                                               
    -> Vantagens: acesso direto (v[i]): rápido                                  -> Vantagens: tamanho é flexível; 
                  Dados contíguos na memória
                  Percorrer os elementos do array é rápido.

    -> Desvantagens:                                                            -> Desvantagens: acesso de um elemento é sequencial;
                  Tamanho do array é fixado (não é flexível).                                        -> é necessário comparar elemento por elemento -> O(n)
                                                                                                 Dados não contíguos na memória
                                                                                                 Percorrer a lista inteira é lento!







    * DUPLAMENTE ENCADEADA: variação de lista encadeada simples; agora o nó também aponta para seu antecessor; o nó anterior do primeiro nó é NULL;
    
    * DUPLAMENTE ENCADEADA CIRCULAR: enquanto na duplamente encadeada o nó anterior do primeiro elemento da lista era NULL, agora ele irá apontar para o último
elemento da lista. O nó posterior do último elemento será o primeiro.


*/
