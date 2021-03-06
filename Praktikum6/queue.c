/*

Nama    : Abram Perdanaputra
NIM     : 13516083

*/

/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "boolean.h"
#include "queue.h"
#include <stdlib.h>

#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */


/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == 0 && Tail(Q) == 0);
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (Head(Q) - Tail(Q) == 1) || (Head(Q) == 1 && Tail(Q) == MaxEl(Q));
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    int jml;

    if (IsEmpty(Q)) {
        return 0;
    }
    jml = Tail(Q) - Head(Q) + 1;

    if (jml <= 0) {
        jml += MaxEl(Q);
    }
    return jml;
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc(Max * sizeof(infotype));
    MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}


/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free((*Q).T);
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    } else if (Tail(*Q) == MaxEl(*Q)) {
        Tail(*Q) = 1;
    } else {
        Tail(*Q)++;
    }
    InfoTail(*Q) = X;
}

void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    } else if (Head(*Q) == MaxEl(*Q)) {
        Head(*Q) = 1;
    } else {
        Head(*Q)++;
    }
}
