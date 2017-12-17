/*
 * Nama 	: Abram Perdanaputra
 * NIM		: 13516083
 * */

#include<stdio.h>
#include "listlinier.h"
#include "boolean.h"

int main() {
	// KAMUS
	int a;
	List L, Linvers, Lcopy, L1, L2;
	
	// INISIALISASI
	CreateEmpty(&L);
	CreateEmpty(&Linvers);
	CreateEmpty(&Lcopy);
	CreateEmpty(&L1);
	CreateEmpty(&L2);
	
	// ALGORITMA
	while(true) {
		scanf("%d", &a);
		if((a > 100) || (a < 0)) {
			break;
		} else {
			InsVLast(&L, a);
		}
	}
	
	while(true) {
		scanf("%d", &a);
		if((a > 100) || (a < 0)) {
			break;
		} else {
			InsVLast(&L1, a);
		}
	}
	
	if(IsEmpty(L) && IsEmpty(L1)) {
		printf("Daftar nilai kosong\n");
	} else {
		printf("%d\n%d\n%d\n%.2f\n", NbElmt(L), Max(L), Min(L), Average(L));
	
		Linvers = FInversList(L);
		PrintInfo(Linvers);
		printf("\n");
		PrintInfo(L);
		printf("\n");
		Lcopy = FCopyList(L);
		PrintInfo(Lcopy);
		printf("\n");
		Konkat(L, L1, &L2);
		PrintInfo(L2);
		printf("\n");
		CreateEmpty(&Linvers);
		CreateEmpty(&Lcopy);
		PecahList(&Linvers, &Lcopy, L);
		PrintInfo(Linvers);
		printf("\n");
		PrintInfo(Lcopy);
		printf("\n");
	}
	
	return 0;
}
