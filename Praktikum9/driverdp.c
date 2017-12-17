#include "listdp.h"
#include <stdio.h>

int main() {
    //Kamus
    List L1, L2, L3;
    int n, a;

    //Algoritma
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&L3);

    printf("Masukkan jumlah input L1 : ");      scanf("%d", &n);

    printf("Masukkan input L1 \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        InsVLast(&L1, a);
    }

    printf("L1          : ");       PrintForward(L1);       printf("\n");

    printf("L1 Inverted : ");       PrintBackward(L1);       printf("\n\n");

    printf("DelVFirst   : ");       DelVFirst(&L1, &a);     PrintForward(L1);  printf("\n%d\n", a);

    printf("DelVLast    : ");       DelVLast(&L1, &a);      PrintForward(L1);  printf("\n%d\n", a);

    printf("DelP        : ");       DelP(&L1, 10);          PrintForward(L1);  printf("\n\n");

    printf("Masukkan jumlah input L2 : ");      scanf("%d", &n);

    printf("Masukkan input L2 \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        InsVLast(&L2, a);
    }

    printf("L2          : ");       PrintForward(L2);       printf("\n");

    printf("L2 Inverted : ");       PrintBackward(L2);       printf("\n\n");

    printf("DelVFirst   : ");       DelVFirst(&L2, &a);     PrintForward(L2);  printf("\n%d\n", a);

    printf("DelVLast    : ");       DelVLast(&L2, &a);      PrintForward(L2);  printf("\n%d\n", a);

    printf("DelP        : ");       DelP(&L2, 10);          PrintForward(L2);  printf("\n");


    printf("\n\n");

    return 0;
}
