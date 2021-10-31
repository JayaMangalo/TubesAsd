#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../src/ADT Mesin Kata/wordmachine.h"

void mainmenu() { 
    boolean new_game = false;  
    boolean load_game = false;
    boolean exit_game = false;

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
            endWord = true;
        } else if(isEqual(currentWord,LOAD)) {
            load_game = true;
            endWord = true;
        } else if(isEqual(currentWord,EXIT)){
            endWord = true;
            exit_game = true;
        }
    }

    if (new_game) {

        Word file;
        file.contents[0] = 'f';
        file.contents[1] = 'i';
        file.contents[2] = 'l';
        file.contents[3] = 'e';
        file.length = 4;

        boolean file_valid = false;
        printf("Masukkan nama file: ");
        startWord();

        while(!endWord) {
            if(isEqual(currentWord, file)) {
                file_valid = true;
            } else {
                while(!file_valid) {
                    printf("Masukkan nama file: ");
                    startWord();
                    if(isEqual(currentWord, file)) {
                        file_valid = true;
                    }
                }
            }
        }
    } else if (load_game) {
        printf("Masukkan nama file: ");
        /* read file */
        startWord();
        while (!endWord) {
            /* this area's function will be able to read file" */
            advWord();
        } 
    } else if (exit_game) {
        printf("Game mobilita selesai.");
    }
}

int main () {
    mainmenu();
    return 0;
}