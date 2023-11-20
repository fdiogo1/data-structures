#include <stdio.h>
#include "circular_lists.h"

int main(void)
{
    CircList *L = create_list();
    
    puts("adding from 1 to 15\n");
    for (int i = 1; i <= 15; i++) addCircLast(L, i);

    printCircList(L);
    reversePrintCircList(L);
    puts("");
    printf("First element: %d\n", firstCircElement(L));
    printf("Last element: %d\n", lastCircElement(L));
    printf("Actual size: %d\n", sizeCircList(L));

    puts("\nremoving the first element\n");
    removeCircList(L, 1);
    printCircList(L);
    reversePrintCircList(L);
    puts("");
    printf("First element: %d\n", firstCircElement(L));
    printf("Last element: %d\n", lastCircElement(L));
    printf("Actual size: %d\n", sizeCircList(L));

    puts("\nremoving the last element\n");
    removeCircList(L, 15);
    printCircList(L);
    reversePrintCircList(L);
    puts("");
    printf("First element: %d\n", firstCircElement(L));
    printf("Last element: %d\n", lastCircElement(L));
    printf("Actual size: %d\n", sizeCircList(L));

    puts("\nremoving the element '8'\n");
    removeCircList(L, 8);
    printCircList(L);
    reversePrintCircList(L);
    puts("");
    printf("First element: %d\n", firstCircElement(L));
    printf("Last element: %d\n", lastCircElement(L));
    printf("Actual size: %d\n", sizeCircList(L));

    destroyCircList(&L);
    printf("\nL == NULL? %d\n", L == NULL);
}