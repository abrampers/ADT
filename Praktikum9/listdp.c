/*

Nama	: Abram Perdanaputra
NIM 	: 13516083
Topik 	: ADT List Linier Double Pointer

*/

/* File : listdp.c */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "boolean.h"
#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return ((First(L) == Nil) && (Last(L) == Nil));
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}


/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
{
    address temp = (address) malloc(sizeof(ElmtList));
	if (temp != Nil) {
		Info(temp) = X;
		Next(temp) = Nil;
        Prev(temp) = Nil;
	}
	return temp;
}

/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
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
				} else if (P == Last(L)) {
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
			Next(temp) = Nil;
            Prev(temp) = Nil;
			First(*L) = temp;
            Last(*L) = temp;
		} else {
			Next(temp) = First(*L);
            Prev(First(*L)) = temp;
            Prev(temp) = Nil;
			First(*L) = temp;
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
		address P = Last(*L);
		Next(P) = Alokasi(X);
		if (Next(P) != Nil) {
			P = Next(P);
			Next(P) = Nil;
            Prev(P) = Last(*L);
            Last(*L) = P;
		}
	} else {
		InsVFirst(L, X);
	}
}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P = First(*L);

	*X = Info(P);
	if (Next(P) == Nil) {
	    First(*L) = Nil;
        Last(*L) = Nil;
	} else {
	    First(*L) = Next(P);
        address Q = Next(P);
        Prev(Q) = Nil;
	}
	Dealokasi(P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = Last(*L);
    *X = Info(P);
    if (Prev(P) != Nil) {
        address Q = Prev(P);
        Last(*L) = Q;
        Next(Q) = Nil;
        Dealokasi(P);
    } else {
        First(*L) = Nil;
        Last(*L) = Nil;
        Dealokasi(P);
    }
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    if (!IsEmpty(*L)) {
        Prev(First(*L)) = P;
	} else {
        Last(*L) = P;
	}
    First(*L) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (!IsEmpty(*L)) {
		address Q = Last(*L);
		Next(Q) = P;
		Next(P) = Nil;
        Prev(P) = Last(*L);
        Last(*L) = P;
	} else {
		InsertFirst(L, P);
	}
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    // CEK LAGI KAYANYA INI YANG BIKIN WA
    address Q = Next(Prec);
    Next(P) = Q;
    Prev(P) = Prec;
	Next(Prec) = P;
    if(Q != Nil) {
        Prev(Q) = P;
    } else {
        Last(*L) = P;
    }
}

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    address Q = Prev(Succ);
    Prev(P) = Q;
    Next(P) = Succ;
	Prev(Succ) = P;
    if(Q != Nil) {
        Next(Q) = P;
    } else {
        First(*L) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    address Q = First(*L);
	if (Next(Q) == Nil) {
		*P = First(*L);
		First(*L) = Nil;
        Last(*L) = Nil;
	} else {
		*P = First(*L);
		First(*L) = Next(*P);
        Prev(Next(*P)) = Nil;
	}
}


void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    address Q = Last(*L);
	if (Prev(Q) == Nil) {
		*P = Last(*L);
		Last(*L) = Nil;
        First(*L) = Nil;
	} else {
		*P = Last(*L);
		Last(*L) = Prev(*P);
        Next(Prev(*P)) = Nil;
	}
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address Q = Search(*L, X);
	address R = First(*L);

	if (Q != Nil) {
		if (Q == R) {
			First(*L) = Next(R);
            Prev(First(*L)) = Nil;
			Dealokasi(Q);
		} else {
			while (Next(R) != Q) {
				R = Next(R);
			}
			Next(R) = Next(Q);
            if (Next(Q) != Nil) {
                Prev(Next(Q)) = Prev(Q);
            } else {
                Last(*L) = R;
            }
			Dealokasi(Q);
		}
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if (Next(*Pdel) != Nil) {
        Next(Prec) = Next(*Pdel);
        Prev(Next(*Pdel)) = Prec;
    } else {
        Last(*L) = Prec;
        Next(Prec) = Nil;
    }
}

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Prev(Succ);
    if (Prev(*Pdel) != Nil) {
        Prev(Succ) = Prev(*Pdel);
        Next(Prev(*Pdel)) = Succ;
    } else {
        First(*L) = Succ;
        Prev(Succ) = Nil;
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P = First(L);
    if (!IsEmpty(L)) {
        printf("[");
        while(Next(P) != Nil) {
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

void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P = Last(L);
    if (!IsEmpty(L)) {
        printf("[");
        while(Prev(P) != Nil) {
            if (P != Last(L)) {
                printf(",");
            }
            printf("%d", Info(P));
            P = Prev(P);
        }
        if (P != Last(L)) {
            printf(",");
        }
        printf("%d", Info(P));
        printf("]");
    } else {
        printf("[]");
    }
}
