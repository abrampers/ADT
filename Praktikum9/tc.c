#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdp.h"

int main() {
  List L;
  int input;
  infotype elmt, elmtx, output;
  address P, Prec;

  CreateEmpty(&L);
  printf("Pilih Fungsi :\n");
  printf("1. Search\n");
  printf("2. InsVFirst\n");
  printf("3. InsVLast\n");
  printf("4. DelVFirst\n");
  printf("5. DelVLast\n");
  printf("6. InsertFirst\n");
  printf("7. InsertLast\n");
  printf("8. InsertAfter\n");
  printf("9. InsertBefore\n");
  printf("10. DelFirst\n");
  printf("11. DelLast\n");
  printf("12. DelP\n");
  printf("13. DelAfter\n");
  printf("14. DelBefore\n");
  printf("Masukan input : ");
  scanf("%d", &input);
  while (input > 0 && input < 15) {
    if (input == 1) {
      printf("Masukan angka : ");
      scanf("%d", &elmt);
      P = Search(L, elmt);
      if (P != Nil) {
        printf("Ditemukan\n");
      } else {
        printf("Tidak ditemukan\n");
      }
    } else if (input == 2) {
      printf("Masukan angka : ");
      scanf("%d", &elmt);
      InsVFirst(&L, elmt);
    } else if (input == 3) {
      printf("Masukan angka : ");
      scanf("%d", &elmt);
      InsVLast(&L, elmt);
    } else if (input == 4) {
      DelVFirst(&L, &output);
      printf("Angka yang dihapus : %d\n", output);
    } else if (input == 5) {
      DelVLast(&L, &output);
      printf("Angka yang dihapus : %d\n", output);
    } else if (input == 6) {
      printf("Masukan angka : ");
      scanf("%d", &elmt);
      P = Alokasi(elmt);
      InsertFirst(&L, P);
    } else if (input == 7) {
      printf("Masukan angka : ");
      scanf("%d", &elmt);
      P = Alokasi(elmt);
      InsertLast(&L, P);
    } else if (input == 8) {
      printf("Masukan angka (P): ");
      scanf("%d", &elmt);
      printf("Masukan angka (Prec): ");
      scanf("%d", &elmtx);
      P = Alokasi(elmt);
      Prec = Search(L, elmtx);
      InsertAfter(&L, P, Prec);
    } else if (input == 9) {
      printf("Masukan angka (P): ");
      scanf("%d", &elmt);
      printf("Masukan angka (Succ): ");
      scanf("%d", &elmtx);
      P = Alokasi(elmt);
      Prec = Search(L, elmtx);
      InsertBefore(&L, P, Prec);
    } else if (input == 10) {
      DelFirst(&L, &P);
      printf("Angka yang dihapus : %d\n", Info(P));
    } else if (input == 11) {
      DelLast(&L, &P);
      printf("Angka yang dihapus : %d\n", Info(P));
    } else if (input == 12) {
      printf("Angka yang dihapus : ");
      scanf("%d", &output);
      DelP(&L, output);
    } else if (input == 13) {
      printf("Masukan angka : ");
      scanf("%d", &elmt);
      Prec = Search(L, elmt);
      DelAfter(&L, &P, Prec);
      printf("Angka yang dihapus : %d\n", Info(P));
    } else if (input == 14) {
      printf("Masukan angka : ");
      scanf("%d", &elmt);
      Prec = Search(L, elmt);
      DelBefore(&L, &P, Prec);
      printf("Angka yang dihapus : %d\n", Info(P));
    }
    PrintForward(L);
    printf("\n");
    PrintBackward(L);
    printf("\n");

    printf("Masukan input : ");
    scanf("%d", &input);
  }

  return 0;
}
