//NIM				: 13516083
//Nama				: Abram Perdanaputra
//Tanggal			: 7 September 2017
//Topik praktikum	: Array
//Deskripsi			:

/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#ifndef ARRAYPOS_H
#define ARRAYPOS_H

#include "boolean.h"
#include <stdio.h>

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define ValUndef 0
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct {
  ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Indeks ke-0 tidak digunakan */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T[i] untuk mengakses elemen ke-i */
/* Definisi :
   Tabel kosong: semua elemen bernilai ValUndef
   Definisi elemen pertama : T[i] dengan i=1 */

/* ********** SELEKTOR ********** */
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	IdxType i;

	for (i = IdxMin; i <= IdxMax; i++) {
		Elmt(*T,i) = ValUndef;
	}
}



/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    //MARK: BEDA
	IdxType i;
	int count = 0;

	for (i = IdxMin; i <= IdxMax; i++) {
		if (Elmt(T,i) != ValUndef) { count++; }
        else break;
	}
	return count;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return (IdxMax - IdxMin + 1);
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
	return NbElmt(T) + IdxMin - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    //MARK: BEDA
	IdxType i = IdxMin;
	boolean kosong = true;

	while (i <= IdxMax && kosong) {
		if (Elmt(T,i) != 0) { kosong = false; }
		else i++;
	}
	return kosong;
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    //MARK: BEDA
	IdxType i = IdxMin;
	boolean full = true;

	while (i <= IdxMax && full) {
		if (Elmt(T,i) == 0) { full = false; }
		else i++;
	}
	return full;
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
	//MARK: bisa salah
	int n, x;
    IdxType i;

    MakeEmpty(T);

    do {
        scanf("%d", &n);
    } while ((n < 0) || (n > MaxNbEl(*T)));

    for (i = IdxMin; i <= n; i++) {
        scanf("%d", &Elmt(*T,i));
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
    IdxType i;

	if (NbElmt(T) == 0) {
        printf("[]");
    } else {
        printf("[%d", Elmt(T, 1));
        for (i = 2; i <= NbElmt(T); i ++) {
            printf(",%d", Elmt(T, i));
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	TabInt T;
    IdxType i;
    MakeEmpty(&T);

    for (i = 1; i <= NbElmt(T1); i++) {

        if (plus)           { Elmt(T, i) = Elmt(T1, i) + Elmt(T2, i); }
        else /* !plus */    { Elmt(T, i) = Elmt(T1, i) - Elmt(T2, i); }

    }

    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    boolean match = true;
    IdxType i;

	if (NbElmt(T1) == NbElmt(T2)) {
        for (i = GetFirstIdx(T1); i <= NbElmt(T1); i ++) {
            if (Elmt(T1, i) != Elmt(T2, i)) {
                match = false;
                break;
            }
        }
        return match;

    } else {
        return false;
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	boolean found = false;
    IdxType i = GetFirstIdx(T);

    while (IsIdxEff(T, i) && !found) {
        if (Elmt(T, i) == X) {
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

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    //MARK: BEDA
	boolean found = false;
    IdxType i = GetFirstIdx(T);

    while (i <= GetLastIdx(T) && !found) {
        if (Elmt(T, i) == X) {
            found = true;
        } else {
			i++;
		}
    }

    return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	//Pencarian Max
	*Max = Elmt(T, GetFirstIdx(T));
    *Min = Elmt(T, GetFirstIdx(T));
    IdxType i;

    for (i = (GetFirstIdx(T) + 1); i <= GetLastIdx(T); i++) {
        if (Elmt(T, i) > *Max) {
            *Max = Elmt(T, i);
        }
        if (Elmt(T, i) < *Min) {
            *Min = Elmt(T, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    //MARK: BEDA
    IdxType i;
    ElType sum = 0;

	if (IsEmpty(T)) { return 0; }
	else {
		for(i = GetFirstIdx(T);i <= GetLastIdx(T); i++) {
			sum += Elmt(T,i);
		}
		return sum;
	}
}

int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    //MARK: BEDA
    IdxType i;
    int count = 0;

	if (IsEmpty(T)) { return 0; }
	else {
		for(i = GetFirstIdx(T);i <= GetLastIdx(T); i++) {
			if (Elmt(T, i) == X) { count++; }
		}
		return count;
	}
}

boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
	boolean allGenap = true;
	IdxType i = GetFirstIdx(T);

	while (i <= GetLastIdx(T) && allGenap) {
		if (Elmt(T,i) % 2 != 0) { allGenap = false; }
		else i++;
	}
    return allGenap;
}

//Tambahan
void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    //Neff(*T) += 1;

    int j;
    for (j = GetLastIdx(*T); j > i; j--) {
        Elmt(*T, j) = Elmt(*T, (j - 1));
    }

    Elmt(*T, i) = X;
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
    *X = Elmt(*T, i);

    int j;
    for (j = i; j <= (GetLastIdx(*T) - 1); j++) {
        Elmt(*T, j) = Elmt(*T, (j + 1));
    }
    Elmt(*T, i) = 0;


    //Neff(*T) -= 1;
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    //MARK: BEDA
	if (asc) {
		int i, j;
        for (i = (GetFirstIdx(*T) + 1); i <= GetLastIdx(*T); i++) {

            int x = Elmt(*T, i);
            for (j = GetFirstIdx(*T); j < i; j++) {
                if (x < Elmt(*T, j)) {

                    DelEli(T, i, &x);
                    AddEli(T, x, j);
                    break;

                }
            }

        }
	} else {
		int i, j;
        for (i = GetFirstIdx(*T); i < GetLastIdx(*T); i++) {

            int maxIdx = i;
            for (j = i + 1; j <= GetLastIdx(*T); j++) {
                if (Elmt(*T, j) > Elmt(*T, maxIdx)) {
                    maxIdx = j;
                }
            }

            int temp = Elmt(*T, i);
            Elmt(*T, i) = Elmt(*T, maxIdx);
            Elmt(*T, maxIdx) = temp;

        }
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	Elmt(*T, NbElmt(*T) + 1) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	*X = Elmt(*T, GetLastIdx(*T));
	Elmt(*T, GetLastIdx(*T)) = ValUndef;
}



#endif
