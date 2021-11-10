// #include "wordmachine/wordmachine.h"
// #include "charmachine/charmachine.h"
// #include "listdin/listdin.h"
// #include "point/point.h"
// #include "matrix/matrix.h"
// #include "order/order.h"
#include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
#include "setup/setup.h"

int main(){
    
    Command NEW_GAMES;
    NEW_GAMES.contents[0] = 'N';
    NEW_GAMES.contents[1] = 'E';
    NEW_GAMES.contents[2] = 'W';
    NEW_GAMES.contents[3] = ' ';
    NEW_GAMES.contents[4] = 'G';
    NEW_GAMES.contents[5] = 'A';
    NEW_GAMES.contents[6] = 'M';
    NEW_GAMES.contents[7] = 'E';
    NEW_GAMES.length = 8;

    Command LOAD_GAMES;
    LOAD_GAMES.contents[0] = 'L';
    LOAD_GAMES.contents[1] = 'O';
    LOAD_GAMES.contents[2] = 'A';
    LOAD_GAMES.contents[3] = 'D';
    LOAD_GAMES.contents[4] = ' ';
    LOAD_GAMES.contents[5] = 'G';
    LOAD_GAMES.contents[6] = 'A';
    LOAD_GAMES.contents[7] = 'M';
    LOAD_GAMES.contents[8] = 'E';
    LOAD_GAMES.length = 9;

    Command EXIT;
    EXIT.contents[0] = 'E';
    EXIT.contents[1] = 'X';
    EXIT.contents[2] = 'I';
    EXIT.contents[3] = 'T';
    EXIT.length = 4;

    printf("MAIN MENU\n");
    printf("ENTER COMMAND: ");
    startCommand();
    if (isEqualCommand(currentCommand,NEW_GAMES)) {
        printf("INPUT NAMA FILE: ");
        Command FILE_CONFIGURATION_NAME;
        FILE_CONFIGURATION_NAME.contents[0] = 'c';
        FILE_CONFIGURATION_NAME.contents[1] = 'o';
        FILE_CONFIGURATION_NAME.contents[2] = 'n';
        FILE_CONFIGURATION_NAME.contents[3] = 'f';
        FILE_CONFIGURATION_NAME.contents[4] = 'i';
        FILE_CONFIGURATION_NAME.contents[5] = 'g';
        FILE_CONFIGURATION_NAME.contents[6] = 'u';
        FILE_CONFIGURATION_NAME.contents[7] = 'r';        
        FILE_CONFIGURATION_NAME.contents[8] = 'a';
        FILE_CONFIGURATION_NAME.contents[9] = 't';
        FILE_CONFIGURATION_NAME.contents[10] = 'i';
        FILE_CONFIGURATION_NAME.contents[11] = 'o';
        FILE_CONFIGURATION_NAME.contents[12] = 'n';
        FILE_CONFIGURATION_NAME.contents[13] = '.';
        FILE_CONFIGURATION_NAME.contents[14] = 't';
        FILE_CONFIGURATION_NAME.contents[15] = 'x';
        FILE_CONFIGURATION_NAME.contents[16] = 't';
        FILE_CONFIGURATION_NAME.length = 17;
        startCommand();
        while(!isEqualCommand(currentCommand,FILE_CONFIGURATION_NAME)) {
            printf("NAMA FILE SALAH, SILAKAN INPUT ULANG!\n");
            printf("INPUT NAMA FILE: ");
            startCommand();
        }
        setup();
    } else if(isEqualCommand(currentCommand,LOAD_GAMES)) {
        printf("INPUT NAMA FILE: ");
        startCommand();
        setup();        
    } else if(isEqualCommand(currentCommand,EXIT)) {
        printf("YOU'VE ENDED THIS GAME");
    } else {
        printf("INVALID COMMAND, PLEASE TRY AGAIN");
    }  
    return 0;
}