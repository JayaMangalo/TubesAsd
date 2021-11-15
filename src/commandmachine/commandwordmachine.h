/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef COMMANDWORDMACHINE_ENGINE_H
#define COMMANDWORDMACHINE_ENGINE_H

#include "..\boolean\boolean.h"
#include "commandcharmachine.h"

#define CAPACITYCOMMAND 50
#define BLANKCOMMAND ' '

typedef struct {
   char contents[CAPACITYCOMMAND]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Command;

/* Word Engine State */
extern boolean endCommand;
extern Command currentCommand;

void ignoreBlankCommand();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startCommand();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advCommand();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyCommand();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

boolean isEqualCommand(Command a, Command b);

Command StringtoCommand(char x[100], int length);
#endif
