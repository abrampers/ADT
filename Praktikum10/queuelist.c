/*
    Nama    : Abram Perdanaputra
    NIM     : 13516083
*/

/*
 File : queuelist.c */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#include "boolean.h"
#include "queuelist.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	*P = (address) malloc(sizeof(ElmtQueue));
	if (*P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}

boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	address P = Head(Q);
	int count = 0;
	while (P != Nil) {
		count++;
		P = Next(P);
	}

	return count;
}

/*** Kreator ***/
void CreateEmpty(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
{
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

void Add (Queue * Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
	if (!IsEmpty(*Q)) {
		address P = Tail(*Q);

		Alokasi(&(Next(P)), X);
		if(Next(P) != Nil) {
			Tail(*Q) = Next(P);
		}

	} else {
		Alokasi(&(Head(*Q)), X);
		if (Head(*Q) != Nil) {
			address P = Head(*Q);
			Next(P) = Nil;
			Tail(*Q) = P;
		}
	}
}

void Del(Queue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
	address P = Head(*Q);

	*X = Info(P);
	Head(*Q) = Next(P);
	if (Next(P) == Nil) {
		Tail(*Q) = Nil;
	}
	Dealokasi(P);
}
