#include <stdio.h>
#include <stdlib.h>

/*
    PILHA = lista linear na qual as operações de inserção e remoção são efetuadas sempre num mesmo extremo, denominado TOPO DA PILHA
        comportamento LI-FO -> last-in, first-out -> "último a entrar, primeiro a sair"
        push - empilha no topo
        pop - remove do topo


    Aplicações:
        - avaliação de expressões
        - casamento de parênteses
        - conversão de expressões
            infix: a + b
            prefix: + b a
            postfix: a b +
        - gerenciamento de memória
        - backtracking problems
            ex: ctrl z


    TIPOS DE PILHAS:
        Estáticas: implementadas com vetores
            * nao necessariamente vetor estático, ele pode ser alocado dinamicamente
            * tem uma capacidade maxima 
            * variável 'top' que guarda o indice do ultimo elemento a ser inserido na pilha, e é utilizado para empilhar um novo elemento (top+1)
            * parte ocupada da pilha: S[0...top]
            * a pilha está vazia se top == -1
            * a pilha está cheia se top == n-1
            * | empilhar (push) um elemento y -> S[++top] = y
            * | consultar (peek) um elemento que está no topo da pilha -> S[top]
            * | desempilhar (pop) um elemento da pilha -> x = S[top--]

        Dinâmicas
            * listas encadeadas
            * nao tem um tamanho maximo
            * o crescimento e diminuição serao feitos dinamicamente

*/

int main(void)
{
    int *i = (int*) calloc(5, sizeof(int));

    *(i+2) = 45;
    printf("i[2] is '%d'\n", *(i+2));

    i[2] = 56;
    printf("i[2] is '%d'\n", *(i+2));

    free(i);
    i = NULL;
}