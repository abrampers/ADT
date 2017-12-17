/*
 * Nama    	: Abram Perdanaputra
 * NIM     	: 13516083
 * Tanggal	: Kamis, 19 Oktober 2017
 * Topik	: ADT Stack
*/

#include <stdio.h>
#include "stackt.h"
#include "boolean.h"

int main() {
	//KAMUS
	Stack S1;
	Stack S2;
	Stack Result;
	int op1, op2, i, j, temp, temp1, temp2;
	char string1[100];
	char string2[100];
	
	
	//INISIALISASI
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	CreateEmpty(&Result);
	i = 0;
	j = 0;
	temp = 0;
	
	//ALGORITMA
	scanf("%s", string1);
	scanf("%s", string2);
	
	while(string1[i] != '#') {
		temp1 = (int) string1[i] - '0';
		Push(&S1, temp1);
		i++;
	}
	
	while(string2[j] != '#') {
		temp2 = (int) string2[j] - '0';
		Push(&S2, temp2);
		j++;
	}
	
	while(!IsEmpty(S1) && !IsEmpty(S2)) {
		Pop(&S1, &op1);
		Pop(&S2, &op2);
		op1 += op2 + temp;
		Push(&Result, op1 % 10);
		temp = op1 / 10;
	}
	
	if(IsEmpty(S1)) {
		while(!IsEmpty(S2)) {
			Pop(&S2, &op2);
			op2 += temp;
			Push(&Result, op2 % 10);
			temp = op2 / 10;
		}
	} else {
		while(!IsEmpty(S1)) {
			Pop(&S1, &op1);
			op1 += temp;
			Push(&Result, op1 % 10);
			temp = op1 / 10;
		}
	}
	
	if(temp != 0) {
		printf("%d", temp);
	}
	
	while(!IsEmpty(Result)) {
		Pop(&Result, &op1);
		printf("%d", op1);
	}
	
	printf("\n");
	
	
	
	return 0;
}
