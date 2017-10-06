#include "jam.h"
#include "boolean.h"
#include <stdio.h>

boolean IsJAMValid (int H, int M, int S) {
    if (H >= 0 && H < 24 && M >= 0 && M < 60 && S >= 0 && S < 60)
        return true;
    else return false;
}

//BAHAYA
JAM MakeJAM (int HH, int MM, int SS) {
    JAM J;
    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS;
    return J;
}


void BacaJAM (JAM * J) {
    printf("Masukkan input JAM : ");
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    printf("\n");
    while (!IsJAMValid(h,m,s)) {
        printf("ERROR INPUT SALAH\n");
        printf("Masukkan input JAM : ");
        scanf("%d %d %d", &h, &m, &s);
        printf("\n");
    }

    Hour(*J) = h;
    Minute(*J) = m;
    Second(*J) = s;
}


void TulisJAM (JAM J) {
    printf("%02d:%02d:%02d\n", Hour(J), Minute(J), Second(J));
}


long JAMToDetik (JAM J) {
    return (3600 * Hour(J) + 60 * Minute(J) + Second(J));
}


JAM DetikToJAM (long N) {
    JAM J;
    if (N >= 86400) {
        long N1 = N % 86400;
        Hour(J) = N1 / 3600;
        Minute(J) = (N1 % 3600) / 60;
        Second(J) = (N1 % 3600) % 60;
    } else {
        Hour(J) = N / 3600;
        Minute(J) = (N % 3600) / 60;
        Second(J) = (N % 3600) % 60;
    }
    return J;
}


boolean JEQ (JAM J1, JAM J2) {
    if (Hour(J1) == Hour(J2)) {
        if (Minute(J1) == Minute(J2)) {
            if (Second(J1) == Second(J2)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}


boolean JNEQ (JAM J1, JAM J2) {
    if(JEQ(J1,J2))
        return false;
    else return true;
}


boolean JLT (JAM J1, JAM J2) {
    if (JAMToDetik(J1) < JAMToDetik(J2))
        return true;
    else return false;
}


boolean JGT (JAM J1, JAM J2) {
    if (JAMToDetik(J1) > JAMToDetik(J2))
        return true;
    else return false;
}

JAM NextDetik (JAM J) {
    long detik = JAMToDetik(J);
    detik = detik + 1;
    return DetikToJAM(detik);
}


JAM NextNDetik (JAM J, int N) {
    long detik = JAMToDetik(J);
    detik = detik + N;
    return DetikToJAM(detik);
}


JAM PrevDetik (JAM J) {
    long detik = JAMToDetik(J);
    detik = detik - 1;
    return DetikToJAM(detik);
}


JAM PrevNDetik (JAM J, int N) {
    long detik = JAMToDetik(J);
    detik = detik - N;
    return DetikToJAM(detik);
}


long Durasi (JAM JAw, JAM JAkh) {
    long detikAwal = JAMToDetik(JAw);
    long detikAkhir = JAMToDetik(JAkh);
    if (detikAwal < detikAkhir)
        return detikAkhir - detikAwal;
    else {
        return (86400 - (detikAkhir - detikAwal));
    }
}
