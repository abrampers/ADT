//NIM				: 13516083
//Nama				: Abram Perdanaputra
//Tanggal			: 7 September 2017
//Topik praktikum	: Array
//Deskripsi			:

#include <stdio.h>
#include "array.h"
//#include "arraypos.h"

int main() {
	
	//Kamus
	TabInt T;
	ElType x, max, min, med;
	IdxType idx, idxMed, i;
	int count = 0;
	
	
	//Algoritma
	//Membaca Tabel T
	BacaIsi(&T);
	
	//Membaca input yang akan dicari jmlah kemunculan, 
	//indeks pertama, dan median atau tidak
	scanf("%d", &x);
	
	//Menulis array T
	TulisIsiTab(T);
	printf("\n");
	
	//Mencari kemunculan x dlm array
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
		
		if (Elmt(T, i) == x) { count++; }
		
	}
	
	printf("%d\n", count);
	
	
	//Mencari indeks pertama di dalam array, kalo gaada tulis "X tidak ada"
	idx = Search1(T, x);
	
	if (idx == IdxUndef) { printf("%d tidak ada\n", x); }
	else { printf("%d\n", idx); }
	
	
	//Mencari apakah x nilai min, max, atau median
	max = ValMax(T);
	min = ValMin(T);
	
	//Mencari apakah Panjang T ganjil atau genap
	if (Neff(T) % 2 == 0) { idxMed = Neff(T) / 2; }
	else { idxMed = (Neff(T) / 2) + 1; }
	InsSortAsc(&T);
	med = Elmt(T, idxMed);
	
	if (x == max) { printf("maksimum\n"); }
	if (x == min) { printf("minimum\n"); }
	if (x == med) { printf("median\n"); }
	
	
	
}

