/*

Nama	: Abram Perdanaputra
NIM 	: 13516083
Topik 	: ADT List Linier Sirkuler

*/

#include "listsirkuler.h"
#include "boolean.h"
#include <stdio.h>

int TQ;

void DeleteRR (List *L, infotype TQ)
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
{
	if(!IsEmpty(*L)){
		address P = First(*L);
		while (Next(P) != First(*L)) {
			P = Next(P);
		}
		if(Info(P) > TQ) {
			printf("%d\n", TQ);
			Info(P) -= TQ;
			First(*L) = P;
		} else {
			DelLast(L, &P);
			printf("%d\n", Info(P));
			Dealokasi(P);
		}
	} else {
		printf("List kosong");
	}
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
	int jumlah = 0;
	long long sum = 0;
	
	address P = First(L);
	if(IsEmpty(L)) {
		return 0;
	} else {
		sum += Info(P);
		jumlah++;
		P = Next(P);
		while(P != First(L)) {
			sum += Info(P);
			jumlah++;
			P = Next(P);	
		}
		return (float) sum / jumlah;
	}
}

int main() {
	// KAMUS
	List L;
	int input;
	char operasi[1];
	address P;
	
	// INISIALISASI
	CreateEmpty(&L);
	
	// ALGORITMA
	scanf("%d", &TQ);
	while(TQ <= 0) {
		scanf("%d", &TQ);
	}
	
	
	while(true) {
		scanf("%s", &operasi);
		if(operasi[0] == 'F') {
			break;
		} else if(operasi[0] == 'A') {
			scanf("%d", &input);
			if(input > 0) {
				InsVFirst(&L, input);
			}
		} else if(operasi[0] == 'D') {
			if(!IsEmpty(L)) {
				DeleteRR(&L, TQ);
			} else {
				printf("List kosong\n");
			}
		} else {
			printf("Kode salah\n");
		}
	}
	
	
	
	if(IsEmpty(L)) {
		printf("Proses selesai\n");
	} else {
		printf("%.2f\n", Average(L));
	}
	
	return 0;
}
