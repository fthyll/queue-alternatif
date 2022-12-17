#include "queue1.h"

int main()
{
    int max,i,x,y,j;
    Queue F;

    printf("======================================\n");
    printf("===== Program Queue Alternatif 1 =====\n");
    printf("======================================\n\n");

    printf("Input Max element dari queue F : "); scanf("%d",&max);
    CreateEmpty(&F,max);

    printf("IsFull? %d\n",IsFull(F));
    printf("IsEmpty? %d\n\n",IsEmpty(F));

    printf("Inputkan jumlah elemen yang akan dimasukkan : ");
    scanf("%d",&j);
    for(i=1;i<=j;i++){
        printf("Input nilai [%d] : ",i); scanf("%d",&x);
        Add(&F,x);
    }
    printf("\nIsi F: \n");

    printf("\nCek posisi HEAD : %d\n",F.Head);
    printf("Cek posisi TAIL : %d\n",F.Tail);
    printf("Cek jumlah elemen : %d\n",NBElmt(F));
    printf("IsFull? %d\n",IsFull(F));
    printf("IsEmpty? %d\n",IsEmpty(F));

    printf("\nElemen pertama keluar (First In First Out)....\n");
    Del(&F,&y);
    printf("Nilai yang keluar adalah : %d\n",y);
    printf("\nIsi F: \n");

    printf("\nCek posisi HEAD : %d\n",F.Head);
    printf("Cek posisi TAIL : %d\n",F.Tail);
    printf("IsFull? %d\n",IsFull(F));
    printf("IsEmpty? %d\n",IsEmpty(F));
    printf("Cek jumlah elemen : %d\n",NBElmt(F));
    DeAlokasi(&F);

    return 0;
}
