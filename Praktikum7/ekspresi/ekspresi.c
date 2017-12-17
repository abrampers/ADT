/*
 * Nama    	: Abram Perdanaputra
 * NIM     	: 13516083
 * Tanggal	: Kamis, 19 Oktober 2017
 * Topik	: ADT Stack
*/

#include <stdio.h>
#include "mesintoken.h"
#include "stackt.h"
#include "boolean.h"
#include <math.h>

int main() {
	//KAMUS
	Stack S;
	int op1, op2, i;
	
	
	//INISIALISASI
	CreateEmpty(&S);
	
	//ALGORITMA
	STARTTOKEN();
	while (!EndToken) {
		//PROSES TOKEN
		if(CToken.val < 0) {
			Pop(&S, &op2);
			Pop(&S, &op1);
			
			printf("%d %c %d\n", op1, CToken.tkn, op2);
			
			if(CToken.tkn == '+'){
				op1 += op2;
			} else if(CToken.tkn == '-'){
				op1 -= op2;
			} else if(CToken.tkn == '*'){
				op1 *= op2;
			} else if(CToken.tkn == '/'){
				op1 /= op2;
			} else if(CToken.tkn == '^'){
				op1 = (int) pow(op1, op2);
			}
			printf("%d\n", op1);
			Push(&S, op1);
		} else {
			Push(&S, CToken.val);
			printf("%d\n", CToken.val);
		}
		
		ADVTOKEN();
		i++;
	}
	
	if(i == 0) {
		printf("Ekspresi kosong\n");
	} else {
		Pop(&S, &op1);
		printf("Hasil=%d\n",op1);
	}
	
	
	
	return 0;
}
