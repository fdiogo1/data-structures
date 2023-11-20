#include <stdio.h>

/*  
    TAD - Tipos abstratos de Dados
        * Conceito que visa dividir nos códigos as ESPECIFICAÇÕES das IMPLEMENTAÇÕES
        * Visa desvincular o tipo de dado (estrutura de dados e operações que as manipulam) de sua implementação
        * Quandi definimos um TAD, estamos preocupados com o que ele faz, e não como ele faz.
        * Ideia parecida com Encapsulamento em Orientação a Objetos
            -> escondemos os dados e detalhes do usuário, fornecendo apenas uma interface pública (método/operações) p/ manipulá-los

        * VANTAGENS:
            -> reutilização: abstração de detalhes da implementação
            -> facilidade de manutenção: mudanças na implementação do TAD não afetam o código fonte dos programas que o utilizam (ocultamento de informação)
            -> corretude: códigos testados em diferentes contextos.

        * TAD em C:
            -> separamos a especificação do tipo em um arquivo de cabeçalho (.h) e sua implementação em um arquivo fonte .c.
                * seu_tad.h -> especificação da TAD
                * seu_tad.c -> implementação da TAD
                
            -> Os programas ou outras TADs que utilizam seu_tad, devem inclur sua especificação:
                #include "seu_tad.h"
*/