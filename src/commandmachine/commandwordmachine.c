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

Command StringtoCommand(char x[100], int length){
    Command X;
    for (int i = 0; i < length; i++)
    {
        X.contents[i] = x[i];
    }
    X.length = length;
    return X;
};

int CommandToInt(Command K) {
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
        val = 10*val+((int)currentCommand.contents[i]-48);
    }
    return val;
    }
