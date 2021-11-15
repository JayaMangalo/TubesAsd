/* File: charmachine.c */
/* Implementasi Character Engine */

#include "commandcharmachine.h"
#include <stdio.h>

char currentCommandChar;
boolean command_eot;

static FILE * command;
static int command_retval;

void startCommandChar() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	command = stdin;
	advCommandChar();
}

void advCommandChar() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	command_retval = fscanf(command,"%c",&currentCommandChar);
	command_eot = (currentCommandChar == MARKCOMMAND);
	/*if (command_eot) {
       fclose(command);
 	}
       */
}