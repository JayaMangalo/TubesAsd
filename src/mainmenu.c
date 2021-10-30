#include <stdio.h>
#include <stdlib.h>
#include "../src/ADT Mesin Kata/wordmachine.h"

void mainmenu() { 
    boolean new_game = false;  
    boolean load_game = false;
    boolean exit = false;

    /* kata NEW */
    Word NEW;
    NEW.contents[0] = 'N';
    NEW.contents[1] = 'E';
    NEW.contents[2] = 'W';
    NEW.length = 3;

    /* kata LOAD */
    Word LOAD;
    LOAD.contents[0] = 'L';
    LOAD.contents[1] = 'O';
    LOAD.contents[2] = 'A';
    LOAD.contents[3] = 'D';
    LOAD.length = 4;

    /* kata EXIT */
    Word EXIT;
    EXIT.contents[0] = 'E';
    EXIT.contents[1] = 'X';
    EXIT.contents[2] = 'I';
    EXIT.contents[3] = 'T';
    EXIT.length = 4;

    printf("MAIN MENU\n");
    printf("ENTER COMMAND: ");

    startWord();

    while(!endWord){
        if(isEqual(currentWord,NEW)) {
            new_game = true;
        } else if(isEqual(currentWord,LOAD)) {
            load_game = true;
        } else if(isEqual(currentWord,EXIT)){
            exit = true;
        } 
        advWord();
    }

    if (new_game) {
        printf("Masukkan nama file: ");
    }
    
}

int main () {
    mainmenu();
    return 0;
}