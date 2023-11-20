#include <stdio.h>

/*
    STRUCTS
        * Uma struct (ou registro ou record) é um "pacote" de variáveis que podem ter tipos diferentes.
        * Visa representar grupos de dados que resultem em algo mais concreto;
                -> ex: registro de alunos, automóveis, etc...
        * Cada variável é um campo do registro.
        * Em C, registros são conhecidos como structs (que vem de structure, do inglês). 
    
    struct [nome do registro]
    {
        tipo campo1;
        tipo campo2;
        ...
        tipo campoN;
    } [uma ou mais variáveis];

    maneira mais utilizada (e convenção do curso):
        typedef struct _aluno
        {
            char nome[100];
            int idade;
        } Aluno;

    ==> Alocação Estática de Structs -> Direto na stack, alocados de forma contígua!
        * Aluno ted = {.nome = "Ted", .idade = 10};
        OU
        * Aluno ted;
            strcpy(ted.nome, "Ted");
            ted.idade = 10;

    ==> Alocação Dinâmica de Structs -> heap
        * Aluno *ted = (Aluno*) calloc(1, sizeof(Aluno));
        * Para acessar os campos de uma struct partindo de um ponteiro, usamos o ->
        * strcpy(ted->nome, "Ted");
        * ted->idade = 10;



*/