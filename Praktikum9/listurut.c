/*

Nama	: Abram Perdanaputra
NIM 	: 13516083
Topik 	: ADT List Linier Sirkuler

*/

#include "listdp.h"
#include "boolean.h"
#include <stdio.h>

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya>=X */
/* Mencari apakah ada elemen list dengan Info(P)>=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)>=X pertama. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
{
	if (!IsEmpty(L)) {
		address P = First(L);

		if (Info(P) >= X) {
			return Nil;
		} else {
			for (;;) {
				if (Info(P) >= X) {
					break;
				} else if (P == Last(L)) {
					break;
				}
				P = Next(P);
			}
			if (Info(P) >= X) {
				return Prev(P);
			} else {
				return Nil;
			}
		}
	} else {
		return Nil;
	}
}

void InsertUrut (List *L, infotype X)
/* Menambahkan elemen pada list L tanpa mengganggu keterurutan L.
Manfaatkan fungsi SearchPrec. */
/* I.S. X terdefinisi. L terdefinisi, mungkin kosong.
Jika tidak kosong, L terurut membesar. */
/* F.S. X dialokasi. Jika alokasi berhasil, maka X dimasukkan sebagai salah
satu elemen L tanpa mengganggu keterurutan L. Insert elemen baru
dapat dilakukan di awal, di tengah, maupun di akhir.
Jika alokasi gagal, L tetap. */
{
	address P = Alokasi(X), Q = SearchPrec(*L, X);
	if(P != Nil) {
		if(IsEmpty(*L)) {
			InsertFirst(L, P);
		} else {
			if (Q == Nil) {
				if(X <= Info(First(*L))) {
					InsertFirst(L, P);
				} else {
					InsertLast(L, P);
				}
			} else {
				InsertAfter(L, P, Q);
			}
		}
	}
}

infotype Max (List L)
/* Menghasilkan nilai terbesar dari elemen list L. L tidak kosong. */
{
	return Info(Last(L));
}

infotype Min (List L)
/* Menghasilkan nilai terkecil dari elemen list L. L tidak kosong. */
{
	return Info(First(L));
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
	int jumlah = 0;
	long long sum = 0;
	
	address P = First(L);
	if(IsEmpty(L)) {
		return 0;
	} else {
		while(P != Nil) {
			sum += Info(P);
			jumlah++;
			P = Next(P);
		}
		return (float) sum / jumlah;
	}
}

int main() {
	// KAMUS
	List L;
	int input;
	
	// INISIALISASI
	CreateEmpty(&L);
	
	// ALGORITMA
	while(true) {
		scanf("%d", &input);
		if(input == -9999) {
			break;
		}
		InsertUrut(&L, input);
	}
	if(!IsEmpty(L)) {
		printf("%d\n%d\n%.2f\n", Max(L), Min(L), Average(L));
		PrintForward(L);
		printf("\n");
		PrintBackward(L);
		printf("\n");
	} else {
		printf("[]\n");
	}
	return 0;
}
