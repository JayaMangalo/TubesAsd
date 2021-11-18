/* Topik Praktikum : ADT Mesin Kata */
/* File : wordmachine.c */
/* Berisi implementasi word engine */

#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
	/* Algoritma */
    while(currentChar==BLANK1 || currentChar==BLANK2) {
        adv();
    }
};

void startWord() {
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
	/* Algoritma */
    start();
    ignoreBlank();
    if(currentChar==MARK) {
        endWord = true;
    } else {
        endWord=false;
        copyWord();
        /*if(currentChar==MARK) {
            endWord=true;
        }*/
    }
};

void advWord() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
	/* Algoritma */
    ignoreBlank();
    if(currentChar==MARK) {
        endWord=true;
    } else {
        copyWord();
        /*if(currentChar==MARK) {
            endWord=true;
        }*/
    }
    // ignoreBlank();
    // if(currentChar==MARK) endWord=true;
};

void copyWord() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
	/* Kamus Lokal */
    int i=0;
    /* Algoritma */
    while(currentChar!=MARK && currentChar!=BLANK1 && currentChar!=BLANK2 && i<WORDCAPACITY) {
        currentWord.contents[i] = currentChar;
        adv();
        i +=1;
    }
    while(currentChar!=MARK && currentChar!=BLANK1 && currentChar!=BLANK2) {
        adv();
    }
    currentWord.length =i;
};

boolean isEqual(Word a, Word b) {
    boolean equal = true;
    if(a.length != b.length) {
        equal = false;
    } else {
        int i = 0;
        while ((i < a.length) && equal) {
            if(a.contents[i] != b.contents[i]) {
                equal = false;
            } else {
                i++;
            }
        }
    }
    return equal;
};


int WordToInt(Word K) {
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
    /* Algoritma */
    int i = 0;
    int val = 0;
    for (int i = 0; i < K.length; i++)
    {
        val = 10*val+((int)currentWord.contents[i]-48);
    }
    return val;
    }


