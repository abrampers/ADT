#include "point.h"
#include "boolean.h"
#include <math.h>
#include <stdio.h>

POINT MakePOINT (float X, float Y) {
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}


void BacaPOINT (POINT * P) {
    printf("Masukkan input POINT : ");
    float x,y;
    scanf("%f %f", &Absis(*P), &Ordinat(*P));
}


void TulisPOINT (POINT P) {
    printf("(%.2f,%.2f)\n", Absis(P), Ordinat(P));
}


boolean EQ (POINT P1, POINT P2) {
    if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2))
        return true;
    else return false;
}


boolean NEQ (POINT P1, POINT P2) {
    if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2))
        return false;
    else return true;
}


boolean IsOrigin (POINT P) {
    if (Absis(P) == 0 && Ordinat(P) == 0)
        return true;
    else return false;
}


boolean IsOnSbX (POINT P) {
    if (Ordinat(P) == 0)
        return true;
    else return false;
}


boolean IsOnSbY (POINT P) {
    if (Absis(P) == 0)
        return true;
    else return false;
}


int Kuadran (POINT P) {
    if (Absis(P) > 0) {
        if (Ordinat(P) > 0)
            return 1;
        else //if (Ordinat(P) < 0)
            return 4;
    } else /*if (Absis(P) < 0) */{
        if (Ordinat(P) > 0)
            return 2;
        else //if (Ordinat(P) < 0)
            return 3;
    }
}


POINT NextX (POINT P) {
    POINT Q;
    Absis(Q) = Absis(P) + 1;
    Ordinat(Q) = Ordinat(P);
    return Q;
}


POINT NextY (POINT P) {
    POINT Q;
    Absis(Q) = Absis(P);
    Ordinat(Q) = Ordinat(P) + 1;
    return Q;
}


POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    POINT Q;
    Absis(Q) = Absis(P) + deltaX;
    Ordinat(Q) = Ordinat(P) + deltaY;
    return Q;
}


POINT MirrorOf (POINT P, boolean SbX) {
    POINT Q;

    if (SbX) {
        Absis(Q) = Absis(P);
        Ordinat(Q) = Ordinat(P) * -1;
    } else {
        Absis(Q) = Absis(P) * -1;
        Ordinat(Q) = Ordinat(P);
    }

    return Q;

}


float Jarak0 (POINT P) {
    return sqrt((Absis(P) * Absis(P)) + (Ordinat(P) * Ordinat(P)));
}


float Panjang (POINT P1, POINT P2) {
    return sqrt((Absis(P2) - Absis(P1)) * (Absis(P2) - Absis(P1)) + (Ordinat(P2) - Ordinat(P1)) * (Ordinat(P2) - Ordinat(P1)));
}


void Geser (POINT *P, float deltaX, float deltaY) {
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}


void GeserKeSbX (POINT *P) {
    Absis(*P) = 0;
}


void GeserKeSbY (POINT *P) {
    Ordinat(*P) = 0;
}


void Mirror (POINT *P, boolean SbX) {
    if (SbX) {
        Ordinat(*P) = Ordinat(*P) * -1;
    } else {
        Absis(*P) = Absis(*P) * -1;
    }
}

void Putar (POINT *P, float Sudut) {
    float sudutAwal = atan(Ordinat(*P)/Absis(*P));

    float panjang = Jarak0(*P);

    float xnew = panjang * cos(sudutAwal + (Sudut * 3.14159 / 180.0));
    float ynew = panjang * sin(sudutAwal + (Sudut * 3.14159 / 180.0));

    Absis(*P) = xnew;
    Ordinat(*P) = ynew;
}
