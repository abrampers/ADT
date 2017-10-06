/*
 * NIM				: 13516083
 * Nama				: Abram Perdanaputra
 * Tanggal			: Kamis, 14 September 2017
 * Topik praktikum	: Data Collection
 * Deskripsi		: ADT Matriks
 * */
 
 #include <stdio.h>
 #include "matriks.h"
 
 int main() {
	/*Kamus*/
	int nb, nk, i, j;
	MATRIKS M;
	
	/*Algoritma*/
	scanf("%d", &nb);
	scanf("%d", &nk);
	
	BacaMATRIKS(&M, nb, nk);
	
	printf("STATISTIK PER MAHASISWA\n");
	
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		TulisStatistikMhs(M, i);
		printf("\n");
	}
	
	printf("STATISTIK PER MATA KULIAH\n");
	for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		TulisStatistikMK(M, j);
		printf("\n");
	}
	
	
	
 }
