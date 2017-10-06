#include "matriks.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    //Kamus
    MATRIKS M1, M2, M3;
    int nb, nk;

    //Algoritma
    printf("Masukkan jumlah baris M1     : ");   scanf("%d", &nb);
    printf("Masukkan jumlah kolom M1     : ");   scanf("%d", &nk);

    MakeMATRIKS(nb, nk, &M1);

    printf("Masukkan Input M1 \n");
    BacaMATRIKS(&M1, NBrsEff(M1), NKolEff(M1));                     printf("\n");

    TulisMATRIKS(M1);                                               printf("\n\n");

    printf("Masukkan jumlah baris M2     : ");   scanf("%d", &nb);
    printf("Masukkan jumlah kolom M2     : ");   scanf("%d", &nk);

    MakeMATRIKS(nb, nk, &M2);

    printf("Masukkan Input M2 \n");
    BacaMATRIKS(&M2, NBrsEff(M2), NKolEff(M2));                     printf("\n");

    TulisMATRIKS(M2);                                               printf("\n\n");

    printf("Proses pengopian M2 ke M3......\n");
    CopyMATRIKS(M2, &M3);                                           printf("\n");

    TulisMATRIKS(M3);                                               printf("\n\n");

    /* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
    printf("M1 + M2 : \n");TulisMATRIKS(TambahMATRIKS(M1, M2));     printf("\n\n");

    printf("M1 - M2 : \n");TulisMATRIKS(KurangMATRIKS(M1, M2));     printf("\n\n");

    printf("M1 * M2 : \n");TulisMATRIKS(KaliMATRIKS(M1, M2));       printf("\n\n");

    printf("M1 * 2 : \n");TulisMATRIKS(KaliKons(M1, 2));            printf("\n\n");

    /* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
    if(EQ(M1, M2))  { printf("M1 == M2"); }
    else            { printf("M1 != M2"); }                         printf("\n\n");


    if(EQSize(M1, M2))  { printf("M1 seukuran M2"); }
    else                { printf("M1 tidak seukuran M2"); }                     printf("\n\n");

    /* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
    if(IsBujurSangkar(M1))  { printf("M1 adalah Bujur Sangkar"); }
    else                    { printf("M1 bukan Bujur Sangkar" ); }  printf("\n\n");

    if(IsSimetri(M1))  { printf("M1 adalah Simetris"); }
    else               { printf("M1 bukan Simetris" ); }            printf("\n\n");

    if(IsSatuan(M1))  { printf("M1 adalah Matriks Satuan"); }
    else              { printf("M1 bukan Matriks Satuan" ); }       printf("\n\n");

    if(IsSparse(M1))  { printf("M1 adalah Sparse"); }
    else              { printf("M1 bukan Sparse" ); }               printf("\n\n");

    printf("Invers dari M1      : \n");TulisMATRIKS(Inverse1(M1));  printf("\n\n");

    printf("Determinan dari M1  : %.2f", Determinan(M1));             printf("\n\n");

    Transpose(&M1);

    printf("Transpose dari M1   : \n");TulisMATRIKS(M1);        printf("\n\n");

    return 0;
}
