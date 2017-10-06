/* File : prioqueue.c */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#include "boolean.h"
#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>



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
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{	
	if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    } else {
		if(Prio(X) == 1) {
			if (Tail(*Q) == MaxEl(*Q)) {
				Tail(*Q) = 1;
			} else {
				Tail(*Q)++;
			}
			InfoTail(*Q) = X;
		} else {
			if(Prio(X) < Prio(InfoHead(*Q))) {
				infotype temp1;
				Del(Q, &temp1);
				Add(Q, X);
			} else {
				if (Head(*Q) == 1) {
					Head(*Q) = MaxEl(*Q);
					InfoHead(*Q) = X;
				} else {
					Head(*Q)--;
					InfoHead(*Q) = X;
				}
			}
		}
	} 
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

/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	infotype temp;
	
	while(!IsEmpty(Q)) {
		Del(&Q, &temp);
		printf("%d %d\n", temp.prio, temp.info);
	}
	
	printf("#\n");
}


