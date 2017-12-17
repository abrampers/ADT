/*

Nama	: Abram Perdanaputra
NIM 	: 13516083
Topik 	: ADT List Linier Sirkuler

*/

/* File : listsirkuler.c */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "boolean.h"
#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (First(L) == Nil);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L)  = Nil;
}


/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address temp = (address) malloc(sizeof(ElmtList));
	if (temp != Nil) {
		Info(temp) = X;
		Next(temp) = Nil;
	}
	return temp;
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
	// CEK LAGI
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (!IsEmpty(L)) {
		address P = First(L);

		if (Info(P) == X) {
			return P;
		} else {
			for (;;) {
				if (Info(P) == X) {
					break;
				} else if (Next(P) == First(L)) {
					break;
				}
				P = Next(P);
			}
			if (Info(P) ==  X) {
				return P;
			} else {
				return Nil;
			}
		}
	} else {
		return Nil;
	}
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address temp = Alokasi(X);
	if (temp != Nil) {
		if (IsEmpty(*L)) {
			Next(temp) = temp;
			First(*L) = temp;
		} else {
			address P = First(*L);
			while (Next(P) != First(*L)) {
				P = Next(P);
			}
			Next(temp) = First(*L);
			First(*L) = temp;
			Next(P) = First(*L);
		}
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	if (!IsEmpty(*L)) {
		address P = First(*L);
		while (Next(P) != First(*L)) {
			P = Next(P);
		}
		Next(P) = Alokasi(X);
		if (Next(P) != Nil) {
			P = Next(P);
			Next(P) = First(*L);
		}
	} else {
		InsVFirst(L, X);
	}

}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P = First(*L);
	address Q = First(*L);

	if (Next(P) == First(*L)) {
		*X = Info(P);
		First(*L) = Nil;
		Dealokasi(P);
	} else {
		while (Next(Q) != First(*L)) {
			Q = Next(Q);
		}

		*X = Info(P);
		First(*L) = Next(P);
		Next(Q) = First(*L);
		Dealokasi(P);
	}
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P = First(*L);
	address Q = Nil;

	while(Next(P) != First(*L)) {
		Q = P;
		P = Next(P);
	}
	*X = Info(P);
	if (Q == Nil) {
		First(*L) = Nil;
	} else {
		Dealokasi(P);
		Next(Q) = First(*L);
	}
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (!IsEmpty(*L)) {
		address Q = First(*L);
		while(Next(Q) != First(*L)) {
			Q = Next(Q);
		}

		Next(P) = First(*L);
		First(*L) = P;
		Next(Q) = P;
	} else {
		Next(P) = P;
		First(*L) = P;
	}
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (!IsEmpty(*L)) {
		address Q = First(*L);
		while (Next(Q) != First(*L)) {
			Q = Next(Q);
		}
		Next(Q) = P;
		Next(P) = First(*L);
	} else {
		InsertFirst(L, P);
	}
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	address Q = First(*L);
	if (Next(Q) == First(*L)) {
		*P = First(*L);
		First(*L) = Nil;
	} else {
		while (Next(Q) != First(*L)) {
			Q = Next(Q);
		}
		*P = First(*L);
		First(*L) = Next(*P);
		Next(Q) = First(*L);
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	address R = First(*L);
	address Q = Nil;
	while (Next(R) != First(*L)) {
		Q = R;
		R = Next(R);
	}
	*P = R;
	if (Q == Nil) {
		First(*L) = Nil;
	} else {
		Next(Q) = First(*L);
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	address P = Next(Prec);
	Next(Prec) = Next(P);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address Q = Search(*L, X);
	address R = First(*L);

	if (Q != Nil) {
		if (Q == R) {
			address T = First(*L);
			while (Next(T) != First(*L)) {
				T = Next(T);
			}
			First(*L) = Next(Q);
			Next(T) = First(*L);
			Dealokasi(Q);
		} else {
			while (Next(R) != Q) {
				R = Next(R);
			}
			Next(R) = Next(Q);
			Dealokasi(Q);
		}
	}
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = First(L);
	if (!IsEmpty(L)) {
		printf("[");
		while(Next(P) != First(L)) {
			if (P != First(L)) {
				printf(",");
			}
			printf("%d", Info(P));
			P = Next(P);
		}
		if (P != First(L)) {
			printf(",");
		}
		printf("%d", Info(P));
		printf("]");
	} else {
		printf("[]");
	}
}
