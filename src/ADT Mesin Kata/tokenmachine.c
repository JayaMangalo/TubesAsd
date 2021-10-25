/* NIM: 13520009 */
/* Nama: Ahmad Romy Zahran */
/* Tanggal : 30 September 2021 */
/* Topik Praktikum : ADT Mesin Kata */
/* File : tokenmachine.c */
/* Berisi implementasi Token Machine */

#include "tokenmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* Algoritma */
    while(currentChar==BLANK) {
        adv();
    }
};

void startToken() {
/* I.S. : currentChar sembarang 
   F.S. : endToken = true, dan currentChar = MARK; 
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */
    /* Algoritma */
    start();
    ignoreBlank();
    if(currentChar==MARK) {
        endToken = true;
    } else {
        endToken = false;
        salinToken();
    }
};

void advToken() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true		  
   Proses : Akuisisi kata menggunakan procedure salinToken */
    /* Algoritma */
    ignoreBlank();
    if(currentChar==MARK) {
        endToken = true;
    } else {
        salinToken();
    }
    ignoreBlank();
};

void salinToken() {
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
    /* Kamus Lokal */
    int i=0;
    /* Algoritma */
    if(currentChar=='+' || currentChar=='-' || currentChar=='*' || currentChar=='/' || currentChar=='^') {
        currentToken.tkn = currentChar;
        currentToken.val = -1;
        adv();
    } else {
        currentToken.val=0;
        currentToken.tkn='b';
        while(currentChar!=MARK && currentChar!=BLANK && i<CAPACITY) {
            currentToken.val = 10*currentToken.val+(currentChar-'0');
            adv();
            i +=1;
        }
        while(currentChar!=MARK && currentChar!=BLANK) {
            adv();
        }
    }
};