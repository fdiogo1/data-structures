#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef char* string;

/***************************** INTERFACE PÚBLICA *****************************/

typedef struct _hash Hash;
Hash *loadTable(string name);
void unloadTable(Hash **);
int hash(const char *);
void insert(Hash *, char *);
void find(const Hash *, string);
void printTable(const Hash *);

/*****************************************************************************/

#endif