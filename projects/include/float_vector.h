#ifndef FLOAT_VECTOR_H// include-guard -> evita termos multiplos includes/definições
#define FLOAT_VECTOR_H


/***************************** INTERFACE PÚBLICA *****************************/

typedef struct _float_vector FloatVector; // main struct

FloatVector* createFloatVector(int capacity); // nas especificações, posso colocar apenas o tipo de parametro que irá receber, e dar o nome apenas nas implementações
void destroyFloatVector(FloatVector **vec_ref);
int sizeFloatVector(const FloatVector *vec);
int capacityFloatVector(const FloatVector *vec);
float atFloatVector(const FloatVector *vec, int index);
float getFloatVector(const FloatVector *vec, int index);
void appendFloatVector(FloatVector *vec, float val);
void setFloatVector(FloatVector *vec, int index, float val);
void printFloatVector(const FloatVector *vec);

/*****************************************************************************/

#endif
