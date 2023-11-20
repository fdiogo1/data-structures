#include "float_vector.h"
#include "double_linked_list.h"
#include <stdio.h>

int main(void)
{
    List *L = createDualList();

    addFirstList(L, 15);
    printList(L);

    FloatVector *vec = createFloatVector(1);

    // printFloatVector(vec);

    // appendFloatVector(vec, 5.0);
    // printFloatVector(vec);
    // appendFloatVector(vec, 2.25);

    // printFloatVector(vec);
    destroyList(&L);
    destroyFloatVector(&vec);
}