#include <stdio.h>
#include <string.h>
#include "lists.h"
#include <windows.h>

int main(void)
{
    system("cls");
    char cmd[12];

    List *L = createList();

    puts("Command: ");
    fflush(stdin);
    scanf("%s", cmd);

    // a função strcmp retorna 0 se as strings forem iguais, e 1 se forem diferentes.
    while (strcmp(cmd, "para") != 0)
    {
        // se o cmd for 'add'
        if (strcmp(cmd, "add") == 0)
        {
            int serial;
            char name[64];
            float price;
            
            scanf("%d %s %f", &serial, name, &price);
            add(L, serial, name, price);

        // se o cmd for 'acessa'
        }
        else if (strcmp(cmd, "imprime") == 0)
        {
            printList(L);
            system("pause");
        } 
        else if (strcmp(cmd, "acessa") == 0)
        {
            int serial;
            //printf("Prompt the serial: ");
            scanf("%d", &serial);

            // impressão do produto acessado
            const Product *found = access(L, serial);
            if (found != NULL)
            {    
                printProduct(found);
            }
            else
            {
                fprintf(stderr, "ERROR in 'access'\n");
                fprintf(stderr, "Product with serial '%03d' wasn't found.\n", serial);
            }
        }
        puts("Command: ");
        scanf("%s", cmd);
    }

    // impressão final da lista
    printSerialList(L);
    // desalocar
    deleteList(&L);

    printf("L == NULL? %d\n", L == NULL);
    system("pause");
    system("cls");

}