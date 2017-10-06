/*
 * NIM				: 13516083
 * Nama				: Abram Perdanaputra
 * Tanggal			: Kamis, 14 September 2017
 * Topik praktikum	: Data Collection
 * Deskripsi		: ADT Matriks
 * */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}


/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M)));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M, i, i);
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    int i = GetFirstIdxBrs(MIn);
    int j = GetFirstIdxKol(MIn);

    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);

    while (i <= GetLastIdxBrs(MIn)) {
        while (j <= GetLastIdxKol(MIn)) {
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
            j++;
        }
        j = GetFirstIdxKol(MIn);
        i++;
    }

}


/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    MakeMATRIKS(NB, NK, M);
    int i = GetFirstIdxBrs(*M);
    int j = GetFirstIdxKol(*M);

    while (i <= NBrsEff(*M)) {
        while (j <= NKolEff(*M)) {
            scanf("%d", &Elmt(*M, i, j));
            j++;
        }
        j = GetFirstIdxKol(*M);
        i++;
    }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    int i, j;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            printf("%d", Elmt(M, i, j));
            if (j != GetLastIdxKol(M)) { printf(" "); }
        }
        if (i != GetLastIdxBrs(M)) {
            printf("\n");
        }
    }
}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    int i, j;

    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            Elmt(M1, i, j) += Elmt(M2, i, j);
        }
    }
    return M1;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    int i, j;

    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            Elmt(M1, i, j) -= Elmt(M2, i, j);
        }
    }
    return M1;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    int i, j, k;
    MATRIKS M;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);

    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++) {
            Elmt(M, i, j) = 0;
            for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
                Elmt(M, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
            }
        }
    }
    return M;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    int i, j;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            Elmt(M, i, j) *= X;
        }
    }
    return M;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    int i, j;

    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M, i, j) *= K;
        }
    }
}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    boolean same = true;
    int i = GetFirstIdxBrs(M1);
    int j = GetFirstIdxKol(M1);

    if (EQSize(M1, M2)) {
        while ((i <= GetLastIdxBrs(M1)) && same) {
            while ((j <= GetLastIdxKol(M1)) && same) {
                if (Elmt(M1, i, j) != Elmt(M2, i, j)) {
                    same = false;
                } else {
                    j++;
                }
            }
            j = GetFirstIdxKol(M1);
            if (same) { i++; }

        }
        return same;
    } else return false;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !EQ(M1, M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}


/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return NBrsEff(M) * NKolEff(M);
}


/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return NBrsEff(M) == NKolEff(M);
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    int i = GetFirstIdxBrs(M);
    int j = GetFirstIdxKol(M);
    boolean same = true;

    if (!IsBujurSangkar(M)) {
        return false;
    } else {
        while (i <= GetLastIdxBrs(M) && same) {
            while (j <= GetLastIdxKol(M) && same) {
                if (Elmt(M, i, j) != Elmt(M, j, i))
                    same = false;
                else j++;
            }
            if (same) { i++; }
        }
    }
    return same;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    int i = GetFirstIdxBrs(M);
    int j = GetFirstIdxKol(M);
    boolean satuan = true;

    if (!IsBujurSangkar(M)) {
        return false;
    } else {
        while (i <= GetLastIdxBrs(M) && satuan) {
            while (j <= GetLastIdxKol(M) && satuan) {
                if (i == j && Elmt(M, i, j) != 1)
                    satuan = false;
                else if (i != j && Elmt(M, i, j) != 0)
                    satuan = false;
                else j++;
            }
            if (satuan) { i++; }
        }
    }
    return satuan;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int i, j;
    int count = 0;
    double n = NBElmt(M) * 0.05;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (Elmt(M, i, j) != 0)
                count++;
        }
    }

    return count <= n;
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    int i, j;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            Elmt(M, i, j) *= -1;
        }
    }
    return M;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    float hasil = 0;
    float dt;
    MATRIKS temp;
    int c, i, j, a, b, nb, nk;

    if ((NBrsEff(M) == 1) && (NKolEff(M) == 1)) {
        hasil += Elmt(M, 1, 1);
    } else if (NBrsEff(M) == 2 && NKolEff(M) == 2) {
        hasil += Elmt(M, 1, 1) * Elmt(M, 2, 2) - Elmt(M, 1, 2) * Elmt(M, 2, 1);
    } else {
        i = GetFirstIdxBrs(M);
        MakeMATRIKS(NBrsEff(M) - 1, NKolEff(M) - 1, &temp);

        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if ((i + j) % 2 == 0) {
                c = 1;
            } else {
                c = -1;
            }
            
            nb = 1;
            nk = 1;
            for (a = GetFirstIdxBrs(M); a <= GetLastIdxBrs(M); a++) {
                nk = 1;
                for (b = GetFirstIdxKol(M); b <= GetLastIdxKol(M); b++) {
                    if (a != i && b != j) {
                        Elmt(temp, nb, nk) = Elmt(M, a, b);
                        nk++;
                    }

                }
                if (a != 1) {
                    nb++;
                }
            }
            dt = Determinan(temp);
            hasil += dt * c * Elmt(M, i, j);
        }
    }
    return hasil;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    int i, j;

    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M, i, j) *= -1;
        }
    }
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    int i, j;
    MATRIKS M1;

    CopyMATRIKS(*M, &M1);

    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M, i, j) = Elmt(M1, j, i);
        }
    }
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
	int j;
	float sum = 0;
	
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		sum += Elmt(M, i, j);
	}
	
	return (sum / NKolEff(M));
	
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	int i;
	float sum = 0;
	
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		sum += Elmt(M, i, j);
	}
	
	return (sum / NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	int j;
	*max = Elmt(M, i, GetFirstIdxKol(M));
	*min = Elmt(M, i, GetFirstIdxKol(M));
	
	for (j = GetFirstIdxKol(M) + 1; j <= GetLastIdxKol(M); j++) {
		if (*max < Elmt(M, i, j)) 	{ *max = Elmt(M, i, j); }
		if (*min > Elmt(M, i, j)) 	{ *min = Elmt(M, i, j); }
	}
	
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	int i;
	*max = Elmt(M, GetFirstIdxBrs(M), j);
	*min = Elmt(M, GetFirstIdxBrs(M), j);
	
	for (i = GetFirstIdxBrs(M) + 1; i <= GetLastIdxBrs(M); i++) {
		if (*max < Elmt(M, i, j)) 	{ *max = Elmt(M, i, j); }
		if (*min > Elmt(M, i, j)) 	{ *min = Elmt(M, i, j); }
	}
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	int j;
	int count = 0;
	
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
		if (Elmt(M, i, j) == X) 	{ count++; }
	}
	
	return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	int i;
	int count = 0;
	
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		if (Elmt(M, i, j) == X) 	{ count++; }
	}
	
	return count;
}

void TulisNilaiX (MATRIKS M, int j, ElType X)
/*
	{ Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
	{ Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
	{ Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
	{ I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
	{ F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
	Jika tidak ada elemen dengan nilai = X, menuliskan [] z
	{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
	1 3 3
	2 5 6
	7 3 9
	maka jika j = 2 dan X = 3, akan tercetak: [1,3]
	}
*/
{
	int i;
	int count = 0;
	int countMax = CountXKol(M, j, X);
	
	printf("[");
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		if (Elmt(M, i, j) == X) { 
			printf("%d", i); 
			count++;
			if ((count < countMax)) { printf(","); }
		}
	}
	printf("]");
}

void TulisStatistikMhs (MATRIKS M, int i)
/* 
	{ Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
	{ Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
	{ Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
	{ I.S. M terdefinisi, i adalah indeks baris efektif M }
	{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
	[i] <rata-rata> <nilai max> <nilai min> }
	{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
	100 83 83
	72 55 60
	77 93 90
	maka jika i = 2 akan tercetak:
	[2] 62.33 72 55
	}
*/
{
	int max, min;
	
	MaxMinBrs(M, i, &max, &min);
	printf("[%d] %.2f %d %d", i, RataBrs(M, i), max, min);
}

void TulisStatistikMK (MATRIKS M, int j)
/* 	{ Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
	{ Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
	{ Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
	{ I.S. M terdefinisi, j adalah indeks kolom efektif M }
	{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
	[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
	{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
	100 83 83
	72 55 60
	77 93 90
	maka jika j = 2 akan tercetak:
	[2] 77.00 [93 1 [3]] [55 1 [2]]
	}
*/
{
	int max, min;
	
	MaxMinKol(M, j, &max, &min);
	printf("[%d] %.2f [%d %d ", j, RataKol(M, j), max, CountXKol(M, j, max)); 
	TulisNilaiX(M, j, max);
	printf("] [%d %d ", min, CountXKol(M, j, min));
	TulisNilaiX(M, j, min);
	printf("]");
}
