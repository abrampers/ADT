/*
 * Nama		: Abram Perdanaputra
 * NIM		: 13516083
 * Tanggal	: 5 Oktober 2017
 * NamaFile	: antrianbank.c
 * Topik 	: ADT Queue
 * 
 * */

#include <stdio.h>
#include "queue.h"
#include "boolean.h"

float AvgElmt (Queue Q) {
	int sum = 0;
	int temp;
	int num = NBElmt(Q);
	while (!IsEmpty(Q)) {
		Del(&Q, &temp);
		sum += temp;
	}
	
	return (float) sum / num;
}

int main() {
	//KAMUS
	int cap, input, temp;
	Queue Q;
	boolean jalan = true;
	
	
	//ALGORITMA
	scanf("%d", &cap);
	
	CreateEmpty(&Q, cap);
	
	while (jalan) {
		scanf("%d", &input);
		
		if (input == 0) {
			jalan = false;
		} else if (input == 1) {
			scanf("%d", &temp);
			if (NBElmt(Q) == cap) {
				printf("Queue penuh\n");
			} else {
				Add(&Q, temp);
			}
		} else if (input == 2) {
			if (IsEmpty(Q)) {
				printf("Queue kosong\n");
			} else {
				Del(&Q, &temp);
			}
		}
		
	}
	
	printf("%d\n", NBElmt(Q));
	
	if (IsEmpty(Q)) {
		printf("Tidak bisa dihitung\n");
	} else {
		printf("%.2f\n", AvgElmt(Q));
	}
}
