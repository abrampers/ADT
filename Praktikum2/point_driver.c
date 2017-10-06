/* File: point.c*/
/* Tanggal: 28 Agustus 2016 */
/* *** Implementasi ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>

int main() {

    float x, y, sudut;
    POINT P, Q;
    /*I/O*/
    //INPUT
    printf("Masukkan Input Point : ");
    scanf("%f %f", &x, &y);
    P = MakePOINT(x,y);
    BacaPOINT(&Q);

    //OUTPUT
    printf("Point P : ");   TulisPOINT(P);
    printf("Point Q : ");   TulisPOINT(Q);

    /*OPERASI RELASIONAL*/
    if (EQ(P,Q))        { printf("Menurut fungsi EQ, P dan Q sama\n"); }

    if (NEQ(P,Q))       { printf("Menurut fungsi NEQ, P dan Q beda\n"); }

    if (IsOrigin(P))    { printf("Menurut fungsi IsOrigin, P adalah origin\n"); }

    if (IsOnSbX(P))     { printf("Menurut fungsi IsOnSbX, P ada di sumbu X\n"); }

    if (IsOnSbY(Q))     { printf("Menurut fungsi IsOnSbX, Q ada di sumbu Y\n"); }

    printf("Titik P berada di kuadran %d\n", Kuadran(P));
    printf("Titik Q berada di kuadran %d\n", Kuadran(Q));

    POINT temp;

    //OPERASI LAIN PADA POINT
    printf("NextX dari P adalah : ");
    TulisPOINT(NextX(P));
    printf("\n");

    printf("NextX dari Q adalah                 : ");           TulisPOINT(NextX(Q));           printf("\n");
    printf("NextY dari P adalah                 : ");           TulisPOINT(NextY(P));           printf("\n");
    printf("NextY dari Q adalah                 : ");           TulisPOINT(NextY(Q));           printf("\n");
    printf("Plus x : 3 dan y : 4 dari P adalah  : ");           TulisPOINT(PlusDelta(P,3,4));   printf("\n");
    printf("Mirror sbX dari P adalah            : ");           TulisPOINT(MirrorOf(P,true));   printf("\n");
    printf("Mirror sbY dari P adalah            : ");           TulisPOINT(MirrorOf(P,false));  printf("\n");
    printf("Mirror sbX dari Q adalah            : ");           TulisPOINT(MirrorOf(Q,true));   printf("\n");
    printf("Mirror sbY dari Q adalah            : ");           TulisPOINT(MirrorOf(Q,false));  printf("\n");
    printf("Jarak P dari origin adalah          : %f\n",          Jarak0(P));                     printf("\n");
    printf("Jarak P dari Q adalah               : %f\n",          Panjang(P,Q));                  printf("\n");
    printf("Jarak P dari origin adalah          : %f\n",          Jarak0(P));                     printf("\n");
    printf("Masukkan sudut yang hendak diputar  : ");           scanf("%f", &sudut);            printf("\n");
    printf("Titik P diputar %.2f derajat adalah : ", sudut);    Putar(&P,sudut);
    TulisPOINT(P);
    printf("\n");

    return 0;
}
