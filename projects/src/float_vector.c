#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*********************************** INTERFACE PRIVADA ***********************************/
// O que está aqui, não está disponível para usuários/programas, ou outros arquivos que usam o float_vector.h

struct _float_vector
{
    int capacity; // num max de elementos
    int size; // qtd de elementos armazenados atualmente
    float *data; // vetor de floats
};

bool _isFullFloatVector (FloatVector *vec)
{
    return vec->size == vec->capacity;
}



/*****************************************************************************************/


/*********************************** INTERFACE PÚBLICA ***********************************/
// O que está definido aqui, os usuários terão acesso em seus apps.

FloatVector* createFloatVector(int capacity)
{
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));
    return vec;
}

void destroyFloatVector(FloatVector **vec_ref)
{
    FloatVector *aux = *vec_ref;
    free(aux->data);
    free(aux);
    *vec_ref = NULL;
}

void appendFloatVector(FloatVector *vec, float val)
{
    if (_isFullFloatVector(vec))
    {
        puts("ERROR in 'append'");
        puts("Vector is full!");
        exit(EXIT_FAILURE);
    }
    vec->data[vec->size++] = val;
}

void printFloatVector(const FloatVector *vec)
{
    if (vec != NULL)
    {
        puts("========================");
        printf("Size: %d\n", vec->size);
        printf("Capacity: %d\n", vec->capacity);
        puts("-----------");
        for (int i = 0; i < vec->capacity; i++)
        {
            printf("[%d] = %.2f\n", i, vec->data[i]);
        }
        puts("========================");
    }
    else puts("This vector doesn't exist.\n");    
}

int sizeFloatVector(const FloatVector *vec)
{
    return vec->size;
}

int capacityFloatVector(const FloatVector *vec)
{
    return vec->capacity;
}

float atFloatVector(const FloatVector *vec, int index)
{
    if (index < 0 || index >= vec->size) // check if the index is valid
    {
        puts("ERROR in 'at'");
        printf("Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }

    return vec->data[index];
}

float getFloatVector(const FloatVector *vec, int index)
{
    return vec->data[index];
}

void setFloatVector(FloatVector *vec, int index, float val)
{
    if(index < 0 || index >= vec->size)
    {
        fprintf(stderr, "ERROR in 'set'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
    }

    vec->data[index] = val;
}

/*****************************************************************************************/