#include "queue3.h"
boolean IsEmpty (Queue Q)
{
    if(HEAD(Q)==Nil&&TAIL(Q)==Nil)
    {
        return true;
    }else{
        return false;
    }
}
boolean IsFull (Queue Q)
{
    if(NBElmt(Q)==MaxEl(Q))
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
        if(TAIL(Q)>HEAD(Q))
        {

             jumlah=TAIL(Q)-HEAD(Q)+1;
        }else{

                jumlah=HEAD(Q)-TAIL(Q)+1;
        }
    }
    return jumlah;
}
void CreateEmpty (Queue *Q, int Max)
{
    (*Q).T=(infotype *)malloc((Max+1)*sizeof(infotype *));          //mengalokasikan memori untuk q.t sebanyak max+1
    if ((*Q).T != NULL)                                                 //jika berhasil maka maxel di isi maxnya head&tail dibuat nil
	{
        MaxEl(*Q) = Max;
        HEAD(*Q)=Nil;
        TAIL(*Q)=Nil;
    }else{                                                                //kalo gagal maxel dibuat kosong/nil
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
         InfoTail(*Q)=X;
    }else{
        if (IsFull(*Q))
		{
		     printf("QueueNYA    penuh");
		}else{
			if(TAIL(*Q)==MaxEl(*Q))
			{
				TAIL(*Q)=1;
				InfoTail(*Q)=X;
			}else{
				TAIL(*Q)++;
				InfoTail(*Q)=X;
			}
		}
    }
}
void Del (Queue *Q, infotype *X)
{
   if(IsEmpty(*Q))
		printf("QueueNYA kosong");
	else
	{
		if(HEAD(*Q)==MaxEl(*Q)+1)
		{
			(*X)=InfoHead(*Q);
			HEAD(*Q)=1;
		}
		else
		{
			if(NBElmt(*Q)==1)
			{
				(*X)=InfoHead(*Q);
				HEAD(*Q)=0;
				TAIL(*Q)=0;
			}
			else
			{
				(*X)=InfoHead(*Q);
				HEAD(*Q)++;
			}
		}
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


