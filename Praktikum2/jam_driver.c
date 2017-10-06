#include "boolean.h"
#include "jam.h"
#include <stdio.h>

int main() {

    int HH, MM, SS;
    JAM K, J;

    //BACA TULIS
    printf("Masukkan Input Jam  : ");
    scanf("%d %d %d", &HH, &MM, &SS);
    printf("\n");

    J = MakeJAM(HH,MM,SS);
    printf("Jam J adalah ");    TulisJAM(J);    printf("\n");
    BacaJAM(&K);
    printf("Jam K adalah ");    TulisJAM(K);    printf("\n");

    //KONVERSI TERHADAP TYPE
    long l = JAMToDetik(K);
    printf("Dalam detik         : %ld\n", l);

    //OPERASI TERHADAP TYPE
    //OPERATOR RELASIONAL
    if (JEQ(K,J))   { printf("Menurut fungsi JEQ, Jamnya sama\n"); }    printf("\n");
    if (JNEQ(K,J))  { printf("Menurut fungsi JNEQ, Jamnya beda\n"); }   printf("\n");
    if (JLT(K,J))   { printf("Menurut fungsi JLT, K < J\n"); }          printf("\n");
    if (JGT(K,J))   { printf("Menurut fungsi JGT, K > J\n"); }          printf("\n");

    //OPERATOR ARITMATIKA JAM
    printf("Next detik K adalah "); TulisJAM(NextDetik(K));     printf("\n");
    printf("Durasi antara K dan J adalah %ld\n", Durasi(K,J));  printf("\n");

    return 0;
}
