#include <stdio.h>

/*
    Funções: estruturas que agrupam um bloco de comandos, que retornam UM ÚNICO valor ao final de sua execução
        tipo(funcao tipo param1, tipo param2, ..., tipo paramN)
        {
            comandos...

            return valor_de_retorno;
        }

        * Toda função deve ter um tipo. Esse tipo determina qual será o tipo de seu valor de retorno.
        * Uma função pode não ter parâmetros, basta não informá-los.
        * Funções não podem ser declaradas dentro de outras funções
        
        * Passagem de parâmetros

            -> PASSAGEM POR VALOR: int soma(int x, int y) -> é feito uma CÓPIA do argumento/valor (ou variável), que pode ser usada e alterada dentro
        da função sem afetar a variável da qual ela foi gerada. Ou seja, ao chamar a função com soma(a, b), em outra região de memória as variáveis
        , outras variáveis x e y são declaradas na memórias, com os valores de a e b, respectivamente, mas são variáveis diferentes, e independentes.
        São regiões de memória diferentes.
            Ao final da função soma, as regiões de memória das variáveis x e y são liberadas -> VARIÁVEIS LOCAIS
        
            -> PASSAGEM POR REFERÊNCIA: é passado a referencia de uma variável (o endereço -> ponteiro) para a função, possibilitando alterar uma variável
        que é externa a uma função. Utilizado quando se tem 2 ou mais retornos na mesma função. -> void soma_e_sub(int x, int y, int *soma, int *sub);

        -> Ponteiros Read Only: podemos evitar uma alteração acidental do seu valor dentro da função apenas adicionando a palavra reservada: const;

*/

int soma(int x, int y);
void somae2(int x, int y, int *z);
void troca(int *x, int *y);

int main(void)
{
    int a = 10;
    int b = 20;
    int c;

    puts("### ANTES DE CHAMAR A FUNCAO"); 
    printf("&a = %p, a = %i\n", &a, a);
    printf("&b = %p, b = %i\n", &b, b);
    printf("&c = %p, c = %i\n\n", &c, c);

    somae2(a, b, &c);

    puts("### DEPOIS DE CHAMAR A FUNCAO");
    printf("&a = %p, a = %i\n", &a, a);
    printf("&b = %p, b = %i\n", &b, b);
    printf("&c = %p, c = %i\n\n", &c, c);

    puts("### ANTES DA TROCA");
    printf("&a = %p, a = %i\n", &a, a);
    printf("&b = %p, b = %i\n\n", &b, b);

    troca(&a, &b);

    puts("### DEPOIS DA TROCA");
    printf("&a = %p, a = %i\n", &a, a);
    printf("&b = %p, b = %i\n\n", &b, b);

}

// PASSAGEM POR VALOR
int soma(int x, int y)
{
    int z = x + y;
    
    puts("==> FUNCAO"); 
    printf("&x = %p, x = %i\n", &x, x);
    printf("&y = %p, y = %i\n", &y, y);
    printf("&z = %p, z = %i\n\n", &z, z);
    
    return z;
}

// PASSAGEM POR REFERÊNCIA
void somae2 (int x, int y, int *z)
{
    *z = x + y; // o conteúdo do local de memória onde z está apontando, passa a ser x + y.

    puts("==> FUNCAO"); 
    printf("&x = %p, x = %i\n", &x, x);
    printf("&y = %p, y = %i\n", &y, y);
    printf("&z = %p, z = %i\n\n", &z, *z);
    
    // não retorna, pois a alteração já está sendo feita através do ponteiro z.
}

void troca(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}