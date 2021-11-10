#include "commandwordmachine.h"

boolean endCommand;
Command currentCommand;

void copyCommand() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
	/* Kamus Lokal */
    int i=0;
    /* Algoritma */
    while(currentCommandChar!=MARKCOMMAND && i<CAPACITYCOMMAND) {
        currentCommand.contents[i] = currentCommandChar;
        advCommandChar();
        i +=1;
    }
    while(currentCommandChar!=MARKCOMMAND) {
        advCommandChar();
    }
    currentCommand.length =i;
};

void ignoreBlankCommand() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
	/* Algoritma */
    while(currentCommandChar == BLANKCOMMAND) {
        advCommandChar();
    }
};

void advCommand() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
	/* Algoritma */
    if(currentCommandChar==MARKCOMMAND) {
        endCommand=true;
    } else {
        copyCommand();
        /*if(currentChar==MARK) {
            endWord=true;
        }*/
    }
    // if(currentChar==MARK) endWord=true;
};

void startCommand() {
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
	/* Algoritma */
    startCommandChar();
    if(currentCommandChar==MARKCOMMAND) {
        endCommand = true;
    } else {
        endCommand=false;
        copyCommand();
        /*if(currentChar==MARK) {
            endWord=true;
        }*/
    }
};

boolean isEqualCommand(Command a, Command b) {
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