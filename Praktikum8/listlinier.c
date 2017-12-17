/*

Nama	: Abram Perdanaputra
NIM 	: 13516083
Topik 	: ADT List Linier

*/

/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Nil NULL

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) (L).First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return (First(L) == Nil);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
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

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
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
				} else if (Next(P) == Nil) {
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
	// SALAH TC 8
	address temp = Alokasi(X);
	if (temp != Nil) {
		if (IsEmpty(*L)) {
			Next(temp) = Nil;
			First(*L) = temp;
		} else {
			Next(temp) = First(*L);
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
		address P = First(*L);
		while (Next(P) != Nil) {
			P = Next(P);
		}
		Next(P) = Alokasi(X);
		if (Next(P) != Nil) {
			P = Next(P);
			Next(P) = Nil;
		}
	} else {
		First(*L) = Alokasi(X);
		if (First(*L) != Nil) {
			address P = First(*L);
			Next(P) = Nil;
		}
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
	First(*L) = Next(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P = First(*L);
	address Q = Nil;

	while(Next(P) != Nil) {
		Q = P;
		P = Next(P);
	}
	*X = Info(P);
	if (Q == Nil) {
		First(*L) = Nil;
	} else {
		Dealokasi(&P);
		Next(Q) = Nil;
	}
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (!IsEmpty(*L)) {
		Next(P) = First(*L);
		First(*L) = P;
	} else {
		Next(P) = Nil;
		First(*L) = P;
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

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (!IsEmpty(*L)) {
		address Q = First(*L);
		while (Next(Q) != Nil) {
			Q = Next(Q);
		}
		Next(Q) = P;
		Next(P) = Nil;
	} else {
		InsertFirst(L, P);
	}
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(*P);
	Next(*P) = Nil;
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
			First(*L) = Next(Q);
			Dealokasi(&Q);
		} else {
			while (Next(R) != Q) {
				R = Next(R);
			}
			Next(R) = Next(Q);
			Dealokasi(&Q);
		}
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
	while (Next(R) != Nil) {
		Q = R;
		R = Next(R);
	}
	*P = R;
	if (Q == Nil) {
		First(*L) = Nil;
	} else {
		Next(Q) = Nil;
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
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	address P = First(L);
	int count = 0;
	while (P != Nil) {
		count++;
		P = Next(P);
	}

	return count;
}


/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	address P = First(L);
	infotype max = Info(P);

	while (P != Nil) {
		if (Info(P) > max) {
			max = Info(P);
		}
		P = Next(P);
	}
	return max;
}


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	if (IsEmpty(*L1) && IsEmpty(*L2)) {
		First(*L3) = Nil;
	} else if (IsEmpty(*L1) && !IsEmpty(*L2)) {
		First(*L3) = First(*L2);
	} else if (IsEmpty(*L2) && !IsEmpty(*L1)) {
		First(*L3) = First(*L1);
	} else {
		address P = First(*L1);
		while (Next(P) != Nil) {
			P = Next(P);
		}
		Next(P) = First(*L2);
		First(*L3) = First(*L1);
	}
	First(*L1) = Nil;
	First(*L2) = Nil;
}

// TAMBAHAN
boolean FSearch (List L, address P) {
	address Q = First(L);
	if(Q == Nil) {
		return false;
	} else if (Q == P) {
		return true;
	} else {
		while ((Next(Q) != Nil) && (Q != P)) {
			Q = Next (Q);
			if (Q == P) {
				return true;
			}
		}
		return false;
	}
}

address SearchPrec (List L, infotype X) {
	address P = Search(L,X);
	address Q = First(L);
	
	if(P == Nil) {
		return Nil;
	} else if(Q == Nil) {
		return Nil;
	} else if (Q == P) {
		return Nil;
	} else {
		while(Next(Q) != P) {
			Q = Next(Q);
		}
		return Q;
	}
}


//Pencarian Nilai Ekstrim dan Rata-Rata (prekondisi: list tidak kosong)

address AdrMax (List L) {
	infotype temp = Max(L);
	return Search(L, temp);
}

infotype Min (List L) {
	address P = First(L);
	infotype min = Info(P);

	while (P != Nil) {
		if (Info(P) < min) {
			min = Info(P);
		}
		P = Next(P);
	}
	return min;
}

address AdrMin (List L) {
	infotype temp = Min(L);
	return Search(L, temp);
}

float Average (List L) {
	infotype sum = 0;
	int jumlah = NbElmt(L);
	address Q = First(L);
	if(Q == Nil) {
		return 0;
	} else {
		while(Q != Nil) {
			sum += Info(Q);
			Q = Next(Q);
		}
		return (float) sum / jumlah;
	}
}


//Proses terhadap semua elemen list

void DelAll (List *L) {
	address P = Nil;
	while(!IsEmpty(*L)) {
		DelFirst(L, &P);
		Dealokasi(&P);
	}
}

void InversList (List *L) {
	List Ltemp = FCopyList(*L);
	First(*L) = Nil;
	address Q = First(Ltemp);
	while(Q != Nil) {
		infotype temp = Info(Q);
		address P = Alokasi (temp);
		if(P == Nil) {
			DelAll(L);
			CreateEmpty(L);
		} else {
			InsertFirst(L, P);
		}
		Q = Next(Q);
	}
}

List FInversList (List L) {
	List L2;
	CreateEmpty(&L2);
	address Q = First(L);
	while(Q != Nil) {
		infotype temp = Info(Q);
		address P = Alokasi (temp);
		if(P == Nil) {
			DelAll(&L2);
			CreateEmpty(&L2);
			return L2;
		} else {
			InsertFirst(&L2, P);
		}
		Q = Next(Q);
	}
	return L2;
} 

void CopyList (List *L1, List *L2) {
	First(*L2) = First(*L1);
}

List FCopyList (List L) {
	List L2;
	CreateEmpty(&L2);
	address Q = First(L);
	while(Q != Nil) {
		infotype temp = Info(Q);
		address P = Alokasi (temp);
		if(P == Nil) {
			DelAll(&L2);
			CreateEmpty(&L2);
			return L2;
		} else {
			InsertLast(&L2, P);
		}
		Q = Next(Q);
	}
	return L2;
}

void CpAlokList (List Lin, List *Lout) {
	CreateEmpty(Lout);
	address Q = First(Lin);
	while(Q != Nil) {
		infotype temp = Info(Q);
		address P = Alokasi (temp);
		if(P == Nil) {
			DelAll(Lout);
			CreateEmpty(Lout);
			return;
		} else {
			InsertLast(Lout, P);
		}
		Q = Next(Q);
	}
}

void Konkat (List L1, List L2, List * L3) {
	if (IsEmpty(L1) && IsEmpty(L2)) {
		First(*L3) = Nil;
	} else if (IsEmpty(L1) && !IsEmpty(L2)) {
		*L3 = FCopyList(L2);
	} else if (IsEmpty(L2) && !IsEmpty(L1)) {
		*L3 = FCopyList(L1);
	} else {
		List Ltemp;
		address Q;
		CreateEmpty(&Ltemp);
		
		*L3 = FCopyList(L1);
		Q = First(*L3);
		while(Next(Q) != Nil) {
			Q = Next(Q);
		}
		Ltemp = FCopyList(L2);
		Next(Q) = First(Ltemp);
		
	}
} 

void PecahList (List *L1, List *L2, List L) {
	*L1 = FCopyList(L);
	int currPos = 0;
	int separuh = NbElmt(L) / 2;
	address Q = First(*L1);
	while(currPos < separuh - 1) {
		Q = Next(Q);
		currPos++;
	}
	First(*L2) = Next(Q);
	Next(Q) = Nil;
}
