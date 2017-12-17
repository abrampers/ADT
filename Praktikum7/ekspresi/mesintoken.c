/*
 * Nama    	: Abram Perdanaputra
 * NIM     	: 13516083
 * Tanggal	: Kamis, 28 September 2017
 * Topik	: ADT Mesin Kata
*/

/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */

#include "boolean.h"
#include "mesintoken.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '


/* State Mesin Kata */
boolean EndToken;
Token CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}

void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
	START();
    IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else {
        EndToken = false;
        SalinToken();
    }
}     

void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else {
        SalinToken();
    }
}

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	IgnoreBlank();
	CToken.val = 0;
    int i = 1;
    for (;;) {
        if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^')) {
			CToken.tkn = CC;
			CToken.val = -1;
		} else {
			int j, temp;
			CToken.tkn = 'b';
			
			if (CC == '0') {
				CToken.val += 0;
			} else if (CC == '1') {
				CToken.val += 1;
			} else if (CC == '2') {
				CToken.val += 2;
			} else if (CC == '3') {
				CToken.val += 3;
			} else if (CC == '4') {
				CToken.val += 4;
			} else if (CC == '5') {
				CToken.val += 5;
			} else if (CC == '6') {
				CToken.val += 6;
			} else if (CC == '7') {
				CToken.val += 7;
			} else if (CC == '8') {
				CToken.val += 8;
			} else if (CC == '9') {
				CToken.val += 9;
			}
			
			
			
		}
		
        ADV();
        if ((CC == MARK) || (CC == BLANK) || (i >= NMax)) {
            break;
        } else {
            i++;
            CToken.val *= 10;
        }
    }
    IgnoreBlank();
}


