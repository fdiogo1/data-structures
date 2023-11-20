#include "mlibs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/******************************* [INTERFACE PRIVADA] *******************************/

#define key(A) A 
#define less(A, B) if(key(A) < key(B))
#define exch(A, B) {int t = A; A = B; B = t;}
#define cmpExch(A, B) if(less(A, B)) {exch(A,B)}

/***********************************************************************************/
void printIntVector(const int *v, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d -> ", v[i]);
        if (i+1 == size) puts("");
    }
}

void selectionSort(int *v, int l, int r)
{
    int menor;
    
    for (int i = l; i <= r; i++)
    {
        menor = i;
        for (int j = i+1; j <= r; j++)
        {
            if (v[j] < v[menor]) menor = j;
        }
        if (v[i] != v[menor]) exch(v[i], v[menor]);
    }
}

void bubbleSort(int *v, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        for (int j = r; j > i; j--)
        {
            if (v[j] < v[j-1]) exch(v[j], v[j-1]);
        }
    }
}

int compareStrings(char *text1, char *text2)
{
    char *aux1 = (char*) calloc(strlen(text1)+1, sizeof(char));
    char *aux2 = (char*) calloc(strlen(text2)+1, sizeof(char));
    
    int answer;

    for (int i = 0; i <= strlen(text1); i++)
    {
        aux1[i] = tolower(text1[i]);
    }

    for (int i = 0; i <= strlen(text2); i++)
    {
        aux2[i] = tolower(text2[i]);
    }

    if (strcmp(aux1, aux2) == 0) answer = 0;
    else answer = 1;

    free(aux1);
    free(aux2);

    return answer;
}