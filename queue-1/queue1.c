#include "queue1.h"
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
        jumlah=TAIL(Q);
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
    free((*Q).T);                                                   //membuat dealokasikan memori yang dipesan
    MaxEl(*Q) = Nil;                                            // maxelnya di nilkan atau dibuat ke awalnya
}
void Add (Queue *Q, infotype X)
{
    if(IsEmpty(*Q))                                            //kalo queue masih kosong maka langsung diinputkan
    {
        HEAD(*Q)=1;TAIL(*Q)=1;                                  //index/address head dan tail di set ke 1
        InfoTail(*Q)=X;                                           //q.t[q.tail]/(q.t[1])index yang pertama diisi elemen X
    }else{                                                      //jika *q tidak kosong maka dicek apakah queuenya penuh.
        if(IsFull(*Q))
        {
            printf("\nQUEUEnya penuh...");
        }else {                                                  //jika tidak TAIL(Q)(q.tail) ditambah/diincrementkan
            TAIL(*Q)++;
            InfoTail(*Q)=X;                                  // setelah TAIL(Q) di incrementkan maka infotail(Q) diisikan elemen
        }
    }
}
void Del (Queue *Q, infotype *X)
{
    int i;
    if(IsEmpty(*Q))                         //jika kosong maka infokan ke user
   {
       printf("\nQUEUEnya Kosong...");
   }else{                                   //jika tidak maka infohead(q)/elemen pertama queue disimpan sementara ke variabel *X
        (*X)=InfoHead(*Q);                  //TAILnya dikkurangi/decrementkan
        TAIL(*Q)--;
        if(TAIL(*Q)==0)                     //jika setelah didecrementkan tailnya kosong maka headnya dibuat kosong juga
        {
            HEAD(*Q)=0;
        }else{                              //kl tidak maka isi queue dari head+1 sampai tail digeser ke kiri
                i=1;
                while(i<=TAIL(*Q))
                {
                    (*Q).T[i]=(*Q).T[i+1];
                    i++;
                }

        }
   }

}
