#include "listlinier.h"
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

    printf("L1 : ");    PrintInfo(L1);      printf("\n\n");

    printf("DelVFirst : ");     DelVFirst(&L1, &a);     PrintInfo(L1);  printf("\n%d\n", a);

    printf("DelVLast : ");      DelVLast(&L1, &a);      PrintInfo(L1);  printf("\n%d\n", a);

    printf("DelP : ");          DelP(&L1, 10);          PrintInfo(L1);  printf("\n");

    printf("NBElmt L1 : %d\n\n", NbElmt(L1));

    printf("Masukkan jumlah input L2 : ");      scanf("%d", &n);

    printf("Masukkan input L2 \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        InsVLast(&L2, a);
    }

    printf("L2 : ");    PrintInfo(L2);      printf("\n\n");

    printf("DelVFirst : ");     DelVFirst(&L2, &a);     PrintInfo(L2);  printf("\n%d\n", a);

    printf("DelVLast : ");      DelVLast(&L2, &a);      PrintInfo(L2);  printf("\n%d\n", a);

    printf("DelP : ");          DelP(&L2, 10);          PrintInfo(L2);  printf("\n");

    printf("NBElmt L2 : %d\n\n", NbElmt(L2));

    printf("Proses konkat L1 dan L2 ke L3......\n");
    Konkat1(&L1, &L2, &L3);     PrintInfo(L3);      printf("\n");

    printf("NBElmt L3 : %d\n\n", NbElmt(L3));

    printf("Max L1 = %d\n", Max(L1));
    printf("Max L2 = %d\n", Max(L2));
    printf("Max L3 = %d\n", Max(L3));

    printf("\n\n");

    return 0;
}
