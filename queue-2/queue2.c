#include "queue2.h"

boolean IsEmpty (Queue Q)
{
    if(HEAD(Q)==Nil&&TAIL(Q)==Nil)
    {
        return true;
    }else
    {
        return false;
    }
}

boolean IsFull (Queue Q)
{
    if(HEAD(Q)==1&&TAIL(Q)==MaxEl(Q))
       {
           return true;
       }else{
            return false;
       }
}

int NBElmt (Queue Q)
{
    int jumlah;
    if(IsEmpty(Q))
    {
        jumlah=0;
    }else{
        jumlah=TAIL(Q)-HEAD(Q)+1;

    }
    return jumlah;
}

void CreateEmpty (Queue *Q, int Max)
{
    (*Q).T=(infotype *)malloc((Max+1)*sizeof(infotype *));
    if ((*Q).T != NULL)
	{
        MaxEl(*Q) = Max;
        HEAD(*Q)=Nil;
        TAIL(*Q)=Nil;
    }else{
        MaxEl(*Q) = Nil;
    }
}

void DeAlokasi (Queue *Q)
{
    free((*Q).T);
    MaxEl(*Q) = Nil;
}

void Add (Queue *Q, infotype X)
{
    address i,j;
    if(IsEmpty(*Q))
    {
        HEAD(*Q)=1;TAIL(*Q)=1;
    }else{
        if(TAIL(*Q)==MaxEl(*Q))
        {
            i=HEAD(*Q);j=1;
            while(i<=TAIL(*Q))
            {
                *((*Q).T+j) = *((*Q).T+i);
                i++;j++;
            }
            HEAD(*Q)=1; TAIL(*Q) = j-1;
        }else{
            TAIL(*Q)++;
        }
    }
     InfoTail(*Q)=X;
}

void Del (Queue *Q, infotype *X)
{
    *X=InfoHead(*Q);
    if(HEAD(*Q)==TAIL(*Q))
    {
        HEAD(*Q)=0;TAIL(*Q)=0;
    }else{
        HEAD(*Q)++;
    }
}


void Tampil(Queue *Q)
{
    int i;
    int j=1;

    if(IsEmpty(*Q)==1)
    {
        printf("Stack Kosong.");
    }
    else
    {

        for(i=(*Q).HEAD;i<=(*Q).TAIL;i++)
        {
            printf("[%d] : %d\n",j,(*Q).T[i]);
            j++;
        }
    }
}


