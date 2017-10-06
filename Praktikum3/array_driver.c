/*nama file : mtabel1.c*/
/*pemilik : miftahul mahfuzh [13513017]*/
#include <stdio.h>
#include "boolean.h"
#include "array.h"

int main()
{
 /*kamus*/
   int i,j,X;
   TabInt T1,T2,T3;
 /*algoritma*/
    printf("data tabel pertama \n");
   	BacaIsi(&T1);
   	printf("\n");
   	TulisIsi(T1);
   	printf("\n");
   	TulisIsiTab(T1);
   	printf("\n");
   	printf("data tabel kedua : \n");
   	BacaIsi(&T2);
   	printf("\n");
   	TulisIsi(T2);
   	printf("\n");
   	TulisIsiTab(T2);
   	printf("\n");

   	/*seleksi ukuran elemen*/
   	if(IsEQ(T1,T2))
   	   printf("kedua tabel sama\n");
   	 else
   	   if(IsLess(T1,T2))
   	      printf("T1 < T2\n");
   	     else
   	       printf("T1 > T2\n");
    printf("\n");

   	/*penjumlahan tabel*/
   	printf("hasil T1 + T2 : ");
   	TulisIsiTab(PlusTab(T1,T2));
   	printf("\n");
    printf("hasil T1 - T2 : ");
   	TulisIsiTab(MinusTab(T1,T2));
   	printf("\n");
   	printf("hasil T1 * 2 : ");
   	TulisIsiTab(KaliKons(T1,2));
   	printf("\n");

   	
    printf("isi T3\n");
    BacaIsi(&T3);
    printf("T3 : ");
    TulisIsiTab(T3);
    printf("\n");

    /*algoritma searching*/
    printf("//Searching angka 2 di T3//\n");
    printf("Tanpa boolean\n");
    printf("%d\n",Search1(T3,2));
    printf("Dengan boolean Found\n");
    printf("%d\n",Search2(T3,2));
    printf("Dengan boolean\n");
    printf("%d\n",SearchB(T3,2));
    printf("Dengan sentinel\n");
   	printf("%d\n",SearchSentinel(T3,2));
    printf("\n");

    /*nilai ekstrim*/
    printf("//nilai ekstrim di T1//\n");
    printf("nilai maksimum   : %d\n",ValMax(T1));
    printf("ada di indeks ke : %d\n",IdxMaxTab(T1));
    printf("nilai minimum    : %d\n",ValMin(T1));
    printf("ada di indeks ke : %d\n",IdxMinTab(T1));
    printf("\n");

    /*operasi lain
    printf("//operasi lain pada TabInt//\n");
    SetTab(T3,&T1);
    printf("nilai T1 yang berasal dari T3 lalu diinverse : ");
    TulisIsiTab(InverseTab(T1));*/
    if(IsSimetris(T1))
      printf("T1 adalah tabel simetris\n");
    else
      printf("T1 bukan tabel simetris\n");
    printf("\n");

    /*sorting terhadap T2*/
    printf("//sorting T2//\n");
    printf("dengan menggunakan MaxSortDesc\n");
    MaxSortDesc(&T2);
    printf("T2 : ");
    TulisIsiTab(T2);
    printf("dengan menggunakan InsSortAsc\n");
    InsSortAsc(&T2);
    printf("T2 : ");
    TulisIsiTab(T2);
    printf("\n");

    /*menambah dan menghapus elemen di T3*/
    printf("//add & delete T3//\n");
    printf("menambah elemen '3' di akhir T3 : ");
    AddAsLastEl(&T3,3);
    TulisIsiTab(T3);
    printf("menambah elemen '3' di akhir T3 (unik) : ");
    AddElUnik(&T3,3);
    TulisIsiTab(T3);
    printf("menghapus elemen terakhir T3 : ");
    DelLastEl(&T3,&X);
    TulisIsiTab(T3);
    printf("\n");

    /*T3 terurut*/
    InsSortAsc(&T3);
    printf("//T3 terurut//\n");
    printf("mencari '4' pada T3\n");
    printf("ada di indeks ke : %d\n",SearchUrut(T3,4));
    printf("nilai max T3 : %d\n", ValMax(T3));
    printf("nilai min T3 : %d\n", ValMin(T3));
    printf("mengisi nilai '4' pada indeks ditemukan pertama : \n");
    Add1Urut(&T3,4);
    TulisIsiTab(T3);
    printf("menghapus nilai '4' pada indeks ditemukan pertama : \n");
    Del1Urut(&T3,4);
    TulisIsiTab(T3);
    return 0;
}
