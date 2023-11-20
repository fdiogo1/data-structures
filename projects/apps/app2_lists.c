#include <stdio.h>
#include "double_linked_list.h"

int main(void)
{
    List *L = createDualList();


    for (int i = 0; i < 10; i++)
    {
        addLastList(L, i+1);
    }
    puts("LISTA 1:");
    printList(L);


    List *test = createDualList();
    for (int i = 11; i <= 20; i++)
    {
        addLastList(test, i);
    }
    puts("LISTA 2:");
    printList(test);

    puts("NOVA LISTA:");
    List *nova = mergeLists(L, test);
    printList(nova);

    printf("L == NULL? %d\n", L == NULL);
    printf("test == NULL? %d\n", test == NULL);
    printf("nova == NULL? %d\n", nova == NULL);

    puts("");

    destroyList(&L);
    destroyList(&test);
    destroyList(&nova);

    printf("L == NULL? %d\n", L == NULL);
    printf("test == NULL? %d\n", test == NULL);
    printf("nova == NULL? %d\n", nova == NULL);
}