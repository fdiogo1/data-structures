#include "hashtable.h"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    Hash *table = loadTable("Names");
    insert(table, "Diogo");
    insert(table, "Dario");
    insert(table, "Diana");
    insert(table, "Aissa");
    insert(table, "Tata");
    insert(table, "Tata2");
    insert(table, "Carol");
    insert(table, "Zacharias");
    printTable(table);
    find(table, "Zika");
    find(table, "Diogo");
    find(table, "tata");
    unloadTable(&table);
}