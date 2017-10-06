/*
 * Nama    	: Abram Perdanaputra
 * NIM     	: 13516083
 * Tanggal	: Kamis, 28 September 2017
 * Topik	: ADT Mesin Kata
*/

#include "mesintoken.h"
#include <stdio.h>

int main() {
	//KAMUS
	STARTTOKEN();
	if(EndToken) {
		printf("Ekspresi kosong\n");
	} else {
		while (!EndToken) {
			if(CToken.tkn == 'b') {
				printf("%d\n", CToken.val);
			} else {
				printf("%c\n", CToken.tkn);
			}
			ADVTOKEN();
		}
	}
	
	
	
	return 0;
}

