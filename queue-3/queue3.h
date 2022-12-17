#ifndef QUEUE3_H_INCLUDED
#define QUEUE3_H_INCLUDED
#include "boolean.h"
#define Nil 0

typedef int infotype;
typedef int address;

typedef struct
{
    infotype *T;
    address HEAD;
    address TAIL;
    int MaxEl;
}Queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T.[(Q).HEAD]
#define InfoTail(Q) (Q).T.[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

boolean IsEmpty (Queue Q);
boolean IsFull (Queue Q);
boolean NBElmt (Queue Q);
void CreateEmpty (Queue *Q,int Max);
void Add (Queue *Q,infotype X);
void Del (Queue *Q,infotype *X);
void DeAlokasi (Queue *Q);
void Tampil(Queue *Q);



#endif // QUEUE3_H_INCLUDED

