/*
 * Nama    	: Abram Perdanaputra
 * NIM     	: 13516083
 * Tanggal	: Kamis, 28 September 2017
 * Topik	: ADT Mesin Kata
*/

#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"

boolean IsKataSama(Kata K1, Kata K2) {
	int i;
	
	if(K1.Length == K2.Length) {
		for(i = 1; i <= K1.Length; i++) {
			if(K1.TabKata[i] != K2.TabKata[i]) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

int main() {
	//KAMUS
	Kata KOMA, TITIK;
	int i, countKata = 0, countKataPendek = 0, countKataPanjang = 0;
	long long tarif;
	
	//INISIALISASI
	KOMA.Length = 4;
	KOMA.TabKata[1] = 'K';
	KOMA.TabKata[2] = 'O';
	KOMA.TabKata[3] = 'M';
	KOMA.TabKata[4] = 'A';
	
	TITIK.Length = 5;
	TITIK.TabKata[1] = 'T';
	TITIK.TabKata[2] = 'I';
	TITIK.TabKata[3] = 'T';
	TITIK.TabKata[4] = 'I';
	TITIK.TabKata[5] = 'K';
	
	
	//ALGORITMA
	STARTKATA();
	while (!EndKata) {
		//menentukan print spasi atau tidak
		if((countKata != 0) && (!IsKataSama(CKata, KOMA)) && (!IsKataSama(CKata, TITIK))) {
			printf(" ");
		}
		
		if( (!IsKataSama(CKata, KOMA)) && (!IsKataSama(CKata, TITIK))) {
			for(i = 1; i <= CKata.Length; i++) {
				printf("%c", CKata.TabKata[i]);
			}
			countKata++;
			
			if(CKata.Length >= 10) {
				countKataPanjang++;
			} else {
				countKataPendek++;
			}
			
		} else if (IsKataSama(CKata, KOMA)) {
			printf(",");
			countKata++;
		} else if (IsKataSama(CKata, TITIK)) {
			printf(".");
			countKata++;
		}
		ADVKATA();
	}
	
	printf("\n");
	
	printf("%d\n", countKataPendek);
	
	printf("%d\n", countKataPanjang);
	
	tarif = (countKataPendek * 1000) + (countKataPanjang * 1500);
	
	if (countKata >= 10) {
		tarif *= 0.9; 
	}
	
	printf("%d\n", tarif);
	
	return 0;
}
