/*

	NAMA 	: ABRAM Perdanaputra
	NIM		: 13516083

*/

#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

int convertOpInt(char c) {
	if(c == '-') {
		return -1;
	} else if(c == '+') {
		return -2;
	} else if(c == '*') {
		return -3;
	} else if(c == '/') {
		return -4;
	} else if(c == '^') {
		return -5;
	} else if(c == '%') {
		return -6;
	} else {
		return (int)c - '0';
	}
}

char convertIntOp(int c) {
	if(c == -1) {
		return '-';
	} else if(c == -2) {
		return '+';
	} else if(c == -3) {
		return '*';
	} else if(c == -4) {
		return '/';
	} else if(c == -5) {
		return '^';
	} else if(c == -6) {
		return '%';
	} else {
		return (int)c - '0';
	}
}

boolean operator(char c) {
	return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^') || (c == '%');
}

void BuildTreeFromString (BinTree *T, char *st, int *idx)
/* Input dari string st */
/* I.S. st[*idx]==䇺(' */
/* F.S. T terdefinisi */
/* Proses : Membaca string st dan membangun pohon secara rekursif
*/
{ 
	/* Kamus Lokal */
	/* Algoritma */
	//(*idx)++; /* advance */
	if (!operator(st[*idx])) {
		*T = AlokNode(convertOpInt(st[*idx]));
		(*idx)++;
	} else { /* Rekurens */
		*T = AlokNode(convertOpInt(st[*idx]));
		(*idx)++; /* advance */
		BuildTreeFromString(&Left(*T),st,idx);
		BuildTreeFromString(&Right(*T),st,idx);
	}
	// (*idx)++; /* advance */
}

void PrintPostfix (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    if (IsTreeEmpty(P)) {

    } else if (IsTreeOneElmt(P)) {
        printf("%d", Akar(P));
    } else {
       PrintPostfix(Left(P));
       PrintPostfix(Right(P));
       printf("%c", convertIntOp(Akar(P)));
    }
}

int evaluate(BinTree P) {
	if(IsTreeOneElmt(P)) {
		return Akar(P);
	} else {
		if(Akar(P) == -1) {
			return evaluate(Left(P)) - evaluate(Right(P));
		} else if(Akar(P) == -2) {
			return evaluate(Left(P)) + evaluate(Right(P));
		} else if(Akar(P) == -3) {
			return evaluate(Left(P)) * evaluate(Right(P));
		} else if(Akar(P) == -4) {
			return evaluate(Left(P)) / evaluate(Right(P));
		} else if(Akar(P) == -5) {
			return pow(evaluate(Left(P)) ,evaluate(Right(P)));
		} else if(Akar(P) == -6) {
			return evaluate(Left(P)) % evaluate(Right(P));
		}
	}
}

int main() {
	// KAMUS
	BinTree binTree = Nil;
	char ekspresi[300];
	int i = 0, idx = 0;
	
	// ALGORITMA
	fgets(ekspresi, sizeof(ekspresi), stdin);
	
	if((ekspresi[0] == '\0') || (ekspresi[0] == '\n')) {
		printf("Ekspresi kosong\n");
	
	} else {
		BuildTreeFromString(&binTree, ekspresi, &idx);
		
		PrintPostfix(binTree);
		printf("\n");
	
		printf("=%d\n", evaluate(binTree));
		
	}
	
}
