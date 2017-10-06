/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "array.h"
#include <stdio.h>

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define INT_MIN -99999

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct {
	ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax - IdxMin + 1; // NANTI KERJAIN
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return IdxMin + Neff(T) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	//REVISI
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == IdxMax - IdxMin + 1);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	IdxType i;
	int x;
    do {
        scanf("%d", &x);
    } while(x < 0 || x > MaxNbEl(*T));

	Neff(*T) = x;

    for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        scanf("%d", &Elmt(*T,i));
    }

}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
	//REVISI
    int x;
    int i = GetFirstIdx(*T);
    scanf("%d", &x);
	Neff(*T) = 0;

    while (x != -9999 && i <= IdxMax) {
        Elmt(*T,i) = x;
        i++;
        Neff(*T)++;
        scanf("%d", &x);
    }
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
	//REVISI
	IdxType i;
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            printf("[%d]%d\n", i, Elmt(T,i));
        }
    }

}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	//REVISI Pake enter 33 34 wa
	IdxType i;
    if (IsEmpty(T)) {
        printf("[]");
    } else {
        printf("[");
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {

            if (i > GetFirstIdx(T)) {
                printf(",");
            }

            printf("%d", Elmt(T,i));

        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
	IdxType i;
    TabInt H;
    Neff(H) = Neff(T1);

    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        Elmt(H,i) = Elmt(T1,i) + Elmt(T2,i);
    }
    return H;
}


TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt H;
	IdxType i;
    Neff(H) = Neff(T1);

    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        Elmt(H,i) = Elmt(T1,i) - Elmt(T2,i);
    }
    return H;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    TabInt H;
	IdxType i;
    Neff(H) = Neff(T1);

    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        Elmt(H,i) = Elmt(T1,i) * Elmt(T2,i);
    }
    return H;
}

TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    TabInt H;
	IdxType i;
    Neff(H) = Neff(Tin);

    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
        Elmt(H,i) = Elmt(Tin,i) * c;
    }
    return H;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	IdxType i;
    if (Neff(T1) != Neff(T2)) { return false; }
    else {

        for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
            if (Elmt(T1,i) != Elmt(T2,i)) return false;
        }

        return true;
    }
}

boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
	//MARK: BISA SALAH
	IdxType i;
    if (Neff(T1) < Neff(T2)) {

    	boolean less = false;
		boolean same = true;
		i = GetFirstIdx(T1);

		while(i <= GetLastIdx(T1) && same) {
			if (Elmt(T1, i) < Elmt(T2, i)) {
				less = true;
				same = false;
			} else if (Elmt(T1,i) > Elmt(T2,i)){
				less = false;
				same = false;
			} else {
				i++;
			}
		}

		if (same) { less = true; }

		return less;

    } else {

		boolean less = false;
		boolean same = true;
		i = GetFirstIdx(T1);

		while(i <= GetLastIdx(T2) && same) {
			if (Elmt(T1, i) < Elmt(T2, i)) {
				less = true;
				same = false;
			} else if (Elmt(T1,i) > Elmt(T2,i)){
				less = false;
				same = false;
			} else {
				i++;
			}
		}

		if (same) { less = false; }

		return less;

    }

}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    if (IsEmpty(T) == true) {
        return IdxUndef;
    } else {

        int i = GetFirstIdx(T);

        while (Elmt(T,i) != X && i < GetLastIdx(T)) {
            i++;
        }
        //Pengecekan terakhir
        if (Elmt(T,i) == X) {
            return i;
        } else {
            return IdxUndef;
        }

    }
}

IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    if (IsEmpty(T)) {
        return IdxUndef;
    } else {

        int i = GetFirstIdx(T);
        boolean found = false;

        while (i <= GetLastIdx(T) && !found) {
            if (Elmt(T,i) == X) {
                found = true;
            } else {
                i++;
            }
        }

        if (found) {
            return i;
        } else {
            return IdxUndef;
        }

    }
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    if (IsEmpty(T)) {
        return false;
    } else {

        int i = GetFirstIdx(T);

        while (i <= GetLastIdx(T)) {
            if (Elmt(T,i) == X) {
                return true;
            } else {
                i++;
            }
        }
        //Pengecekan terakhir
        return false;

    }
}

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
	Elmt(T,0) = X;
	int i;

	for (i = GetLastIdx(T); i >= GetFirstIdx(T); i--) {
		if (Elmt(T,i) == X) {
			break;
		}
	}

	if (i != 0) { return true; }
	else { return false; }

}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
	ElType max = Elmt(T,GetFirstIdx(T));
	IdxType i;

	for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
		if (max < Elmt(T,i)) { max = Elmt(T,i); }
	}

	return max;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
	ElType min = Elmt(T,GetFirstIdx(T));
	IdxType i;

	for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
		if (min > Elmt(T,i)) { min = Elmt(T,i); }
	}

	return min;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
	ElType max = Elmt(T,GetFirstIdx(T));
	IdxType indeksMax = GetFirstIdx(T);
	IdxType i;

	for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
		if (max < Elmt(T,i)) {
			max = Elmt(T,i);
			indeksMax = i;
		}
	}

	return indeksMax;
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
	ElType min = Elmt(T,GetFirstIdx(T));
	IdxType indeksMin = GetFirstIdx(T);
	IdxType i;

	for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
		if (min > Elmt(T,i)) {
			min = Elmt(T,i);
			indeksMin = i;
		}
	}

	return indeksMin;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
	Neff(*Tout) = Neff(Tin);
	IdxType i;

	for (i = GetFirstIdx(*Tout); i <= GetLastIdx(*Tout); i++) {
		Elmt(*Tout,i) = Elmt(Tin,i);
	}
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
	TabInt U;
	Neff(U) = Neff(T);
	IdxType i, j;
	i = GetFirstIdx(U);
	j = GetLastIdx(U);

	while (i <= GetLastIdx(U)) {
		Elmt(U,i) = Elmt(T,j);
		i++;
		j--;
	}

	return U;

}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
	if (IsEmpty(T)) {
		return true;
	} else {

		IdxType i, j;
		i = GetFirstIdx(T);
		j = GetLastIdx(T);

		while (i < j) {
			if (Elmt(T,i) != Elmt(T,j)) {
				return false;
			} else {
				i++;
				j--;
			}
		}

		return true;
	}
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
	//MARK: BISA SALAH
	IdxType i ;
	for (i = GetFirstIdx(*T); i < GetLastIdx(*T); i++) {

		IdxType maxIdx = 0;
		IdxType j;
		ElType max = INT_MIN;
		for (j = GetFirstIdx(*T) + i - 1; j <= GetLastIdx(*T); j++) {

			if (Elmt(*T, j) > max) {
				max = Elmt(*T, j);
				maxIdx = j;
			}

		}

		ElType temp = Elmt(*T, maxIdx);
		Elmt(*T, maxIdx) = Elmt(*T, i);
		Elmt(*T, i) = temp;

	}

}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
	//MARK: BISA SALAH
	IdxType i,  j;
	for (i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++) {

		IdxType j = i - 1;
		ElType temp = Elmt(*T, i);

		for (; j >= GetFirstIdx(*T) && Elmt(*T, j) > temp; j--) {
			Elmt(*T, j + 1) = Elmt(*T, j);
		}

		Elmt(*T, j + 1) = temp;

	}

}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	if (!IsFull(*T)) {
		Elmt(*T,GetLastIdx(*T) + 1) = X;
		Neff(*T)++;
	}
}

void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
	//REVISI IsIdxValid
	if (!IsFull(*T) && !IsEmpty(*T) && IsIdxEff(*T, i)) {

		IdxType j;
		Neff(*T)++;
		for (j = GetLastIdx(*T); j > i; j--) {
			Elmt(*T, j) = Elmt(*T, j - 1);
		}

		Elmt(*T,i) = X;


	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	//REVISI SALAH
	*X = Elmt(*T,GetLastIdx(*T));
	Neff(*T)--;
}

void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	//REVISI SALAH
	*X = Elmt(*T,i);
	IdxType j;

	for (j = i; j <= (GetLastIdx(*T) - 1); j++) {
		Elmt(*T, j) = Elmt(*T, j + 1);
	}

	Neff(*T)--;
}


/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
	if (!SearchSentinel(*T,X)) {
		AddAsLastEl(T,X);
	} else {
		printf("nilai sudah ada\n");
	}
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
	//MARK: RAGU
	/*IdxType i = GetFirstIdx(T);
	IdxType j = GetLastIdx(T);
	boolean found = false;

	while (i <= j && !found) {
		if (Elmt(T,i) == X) {
			found = true;
		} else {
			i++;
		}
	}*/

	return Search2(T, X);
}

ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
	return Elmt(T, GetLastIdx(T));
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
	return Elmt(T, GetFirstIdx(T));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
	if (IsFull(*T)) {}
	else {
		AddAsLastEl(T, X);
		InsSortAsc(T);
	}
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
	if(Search2(*T,X) != IdxUndef) {
		IdxType i = Search2(*T,X);
		IdxType j;

		for (j = i; j <= GetLastIdx(*T); j++) {
			Elmt(*T, j) = Elmt(*T, j + 1);
		}

		Neff(*T)--;

	}
}

#endif
