#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "boolean.h"

int main(){
	TabInt T1, T2, T3;
	int idx1, idx2, idx3, idxMin, idxMax, N;

	printf("ASSIGN ARRAY\n");

	//PEMBACAAN ARRAY T1
	printf("masukan ukuran array T1 yang diinginkan : ");
	scanf("%d", &N);
	MakeEmpty(&T1, N);
	BacaIsi(&T1, N);

	printf("\n");
	//menuliskan array T1
	printf("Array 1 sebagai berikut : ");
	TulisIsiTab(T1);
	printf("\n");

	//PEMBACAAN ARRAY T2
	printf("masukan ukuran array T2 yang diinginkan : ");
	scanf("%d", &N);
	MakeEmpty(&T2, N);
	BacaIsi(&T2, N);

	printf("\n");
	//menuliskan array T2
	printf("Array 2 sebagai berikut : ");
	TulisIsiTab(T2);
	printf("\n");


	printf("\n");
	printf("\n");

	printf("OPERASI ARRAY\n");

	printf("PENJUMLAHAN\n");
	MakeEmpty(&T3, NbElmt(T1));
	T3 = PlusTab(T1, T2);
	//menuliskan hasil penjumlahan T1 dan T2
	printf("Hasil penjumlahan T1 dan T2 sebagai berikut : ");
	TulisIsiTab(T3);
	printf("\n");

	printf("PENGURANGAN\n");
	T3 = MinusTab(T1, T2);
	//menuliskan hasil pengurangan T1 dan T2
	printf("Hasil pengurangan T1 dan T2 sebagai berikut : ");
	TulisIsiTab(T3);
	printf("\n");

	printf("PERKALIAN\n");
	T3 = KaliTab(T1, T2);
	//menuliskan hasil perkalian T1 dan T2
	printf("Hasil perkalian T1 dan T2 sebagai berikut : ");
	TulisIsiTab(T3);
	printf("\n");

	printf("PERKALIAN T1 Dengan C\n");
	printf("masukan konstanta : ");
	int C;
	scanf("%d", &C);
	T3 = KaliKons(T1, C);
	//menuliskan hasil perkalian T1 dengan konstanta C
	printf("Hasil perkalian T1 dengan konstanta C berikut : ");
	TulisIsiTab(T3);
	printf("\n");

	printf("\n");
	printf("\n");

	printf("OPERASI RELASIONAL\n");
	printf("Apakah T1 dan T2 sama ?\n");

	if(IsEQ(T1, T2)){
		printf(">> T1 dan T2 adalah equal\n");
	}else{
		printf(">> T1 dan T2 adalah berbeda\n");
	}

	printf("Apakah T1 lebih kecil dari T2 ?\n");
	if(IsLess(T1, T2)){
		printf(">> Ya, T1 < T2\n");
	}else if(IsEQ(T1, T2)){
		printf("Tidak, T1 equal T2");
	}else{
		printf(">> Tidak, T1 > T2\n");
	}

	printf("\n");
	printf("\n");
	printf("SEARCHING\n");
	printf("masukan X yang ingin dicari di dalam T1 : ");
	int X;
	scanf("%d", &X);
	printf("\n");

	if(SearchB(T1, X)){
		printf("Ya, %d terdapat di dalam array T1\n", X);
		printf("%d terdapat di indeks %d \n", X, Search1(T1, X));
	}else{
		printf("Maaf, %d tidak terdapat di dalam array T1\n", X);
	}

	printf("\n");
	printf("\n");

	printf("NILAI EKSTREM\n");
	printf("\n");
	printf("Elemen maksimum T1 adalah : %d (terletak di indeks ke-%d)\n", ValMax(T1), IdxMaxTab(T1));
	printf("\n");
	printf("Elemen minimum T1 adalah : %d (terletak di indeks ke-%d)\n", ValMin(T1), IdxMinTab(T1));

	printf("\n");
	printf("\n");

	printf("OPERASI LAIN\n");

	printf("\n");

	printf("mengopi T1 ke T3\n");
	CopyTab(T1, &T3);
	printf("Hasil pengopian T1 ke T3 sebagai berikut : ");
	TulisIsiTab(T3);
	printf("\n");

	printf("inverse dari T1 adalah : ");
	T3 = InverseTab(T1);
	TulisIsiTab(T3);
	printf("\n");

	printf("Apakah T1 Simetris? \n");
	if(IsSimetris(T1)){
		printf("Ya, T1 simetris\n");
	}else{
		printf("Tidak, T1 tidak simetris\n");
	}

	printf("\n");
	printf("\n");

	printf("SORTING\n");

	printf("\n");

	printf("Hasil sorting secara menurun T1 sebagai berikut : ");
	MaxSortDesc(&T1);
	TulisIsiTab(T1);
	printf("\n");

	printf("Hasil sorting secara menaik T1 sebagai berikut : ");
	InsSortAsc(&T1);
	TulisIsiTab(T1);

	printf("\n");
	printf("\n");

	printf("MENAMBAH DAN MENGURANGI ELEMEN\n");

	printf("\n");

	printf("masukan elemen yang ingin di tambahkan ke array T1 : ");
	int el;
	printf("\n");
	scanf("%d", &el);
	printf("masukan elemen ke indeks : ");
	scanf("%d", &idx1);
	printf("\n");

	if(idx1 != 1){
		if(IsIdxEff(T1, idx1 - 1)){
			printf("Hasil penambahan elemen %d di indeks %d T1 sebagai berikut : ", el, idx1);
			AddEli(&T1, el, idx1);
			TulisIsiTab(T1);
		}else{
			printf("masukan indeks tidak valid\n");
		}

		printf("\n");
		printf("\n");
	}else{
		if(IsIdxEff(T1, idx1)){
			printf("Hasil penambahan elemen %d di indeks %d T1 sebagai berikut : ", el, idx1);
			AddEli(&T1, el, idx1);
			TulisIsiTab(T1);
		}else{
			printf("masukan indeks tidak valid\n");
		}
		printf("\n");
		printf("\n");
	}

	printf("masukan indeks elemen yang ingin di hapus dari array T1  : ");
	scanf("%d", &idx1);
	printf("\n");

	printf("Hasil penghapusan elemen %d di indeks %d T1 sebagai berikut : ", el, idx1);
	DelEli(&T1, idx1, &el);
	TulisIsiTab(T1);

	printf("\n");
	printf("\n");

	printf("masukan elemen unik yang ingin di tambahkan di akhir array T1 : ");
	printf("\n");
	scanf("%d", &el);
	printf("\n");

	AddElUnik(&T1, el);
	printf("Hasil penambahan elemen %d T1 sebagai berikut : ", el);
	TulisIsiTab(T1);

	printf("\n");
	printf("\n");

	printf("masukan elemen yang ingin disisipkan di akhir array T1 terurut membesar : ");
	printf("\n");
	scanf("%d", &el);
	printf("\n");

	Add1Urut(&T1, el);
	printf("Hasil penambahan elemen %d T1 sebagai berikut : ", el);
	TulisIsiTab(T1);

	printf("\n");
	printf("\n");

	printf("masukan elemen yang ingin dihapus dari T1 (penghapusan akan terjadi pada indeks terkecil elemen tersebut) : ");
	printf("\n");
	scanf("%d", &el);
	printf("\n");

	Del1Urut(&T1, el);
	printf("Hasil penghapusan elemen %d T1 sebagai berikut : ", el);
	TulisIsiTab(T1);

	printf("\n");
	printf("\n");
}
