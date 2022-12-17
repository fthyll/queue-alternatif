#ifndef QUEUE1_H_INCLUDED
#define QUEUE1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil 0

typedef int infotype;
typedef int address;

typedef struct{
    infotype *T;
    address Head;
    address Tail;
    int MaxEl;
}Queue;

/********** AKSES (Selektor) **********/
/* Jika Q adalah Queue, maka akses elemen : */
#define HEAD(Q) (Q).Head
#define TAIL(Q) (Q).Tail
#define InfoHead(Q) (Q).T[(Q).Head]
#define InfoTail(Q) (Q).T[(Q).Tail]
#define MaxEl(Q) (Q).MaxEl

boolean IsEmpty (Queue Q);
boolean IsFull (Queue Q);
int NBElmt (Queue Q);
void CreateEmpty (Queue *Q, int Max);
void DeAlokasi (Queue *Q);
void Add (Queue *Q, infotype X);
void Del (Queue *Q, infotype *X);

#endif // QUEUE1_H_INCLUDED
