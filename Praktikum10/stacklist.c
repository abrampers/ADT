/*
    Nama    : Abram Perdanaputra
    NIM     : 13516083
*/

/* File : stacklist.c */

#include "boolean.h"
#include "stacklist.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (address) malloc(sizeof(ElmtStack));
	if (*P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}


/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
    return (Top(S) == Nil);
}

void CreateEmpty (Stack * S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
{
    Top(*S) = Nil;
}

void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
    address temp;
    Alokasi(&temp, X);
	if (temp != Nil) {
		if (IsEmpty(*S)) {
			Next(temp) = Nil;
			Top(*S) = temp;
		} else {
			Next(temp) = Top(*S);
			Top(*S) = temp;
		}
	}
}

void Pop (Stack * S, infotype * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
    address P = Top(*S);

	*X = Info(P);
	Top(*S) = Next(P);
	Dealokasi(P);
}
