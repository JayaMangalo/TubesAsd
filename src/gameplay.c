#include <stdio.h>
#include "setup/setup.h"

extern Command NEW_GAME;
extern Command LOAD_GAME;
extern Command EXIT;
extern Command MOVE;
extern Command PICK_UP;
extern Command DROP_OFF;
extern Command TO_DO;
extern Command MAP;
extern Command IN_PROGRESS;
extern Command BUY;
extern Command INVENTORY;
extern Command HELP;

void game_play() {
    printf("===================\n");
    printf("WELCOME TO THE GAME\n");
    printf("Mobita berada di posisi\n");
    printf("ENTER COMMAND: ");
    startCommand();
    setupCommand(); //fungsi ini buat ngisi command-command diatas biar gausah diisi disini. 
    if(isEqualCommand(currentCommand,MOVE))
    { 
        printf("Waktu:\n");
        printf("MOVED\n");
    }
    else if(isEqualCommand(currentCommand,PICK_UP)){}
    else if(isEqualCommand(currentCommand,DROP_OFF)){}
    else if(isEqualCommand(currentCommand,MAP)){}
    else if(isEqualCommand(currentCommand,TO_DO)){
        toDoCommand();
    }
    else if(isEqualCommand(currentCommand,IN_PROGRESS)){}
    else if(isEqualCommand(currentCommand,BUY)){}
    else if(isEqualCommand(currentCommand,INVENTORY)){}
    else if(isEqualCommand(currentCommand,HELP)){}
    else{
        printf("INVALID COMMAND, TRY AGAIN (TYPE 'HELP' FOR LIST OF COMMANDS)\n");
    }
}
void mainmenu(){
    setupCommand();
    printf("MAIN MENU\n");
    printf("ENTER COMMAND: ");
    startCommand();

    int BarisMap,KolomMap;
    POINT HQ;
    ListDin List_bangunan;
    Matrix m;
    Daftar DaftarOrder;

    if (isEqualCommand(currentCommand,NEW_GAME)) {
        printf("INPUT NAMA FILE: ");
        startCommand();
        game_play();
        setupGame(&BarisMap, &KolomMap, &HQ,  &List_bangunan, &m, &DaftarOrder);
    } else if(isEqualCommand(currentCommand,LOAD_GAME)) {
        printf("INPUT NAMA FILE: ");
        startCommand();
        setupGame(&BarisMap, &KolomMap, &HQ,  &List_bangunan, &m, &DaftarOrder);     
    } else if(isEqualCommand(currentCommand,EXIT)) {
        printf("YOU'VE ENDED THIS GAME");
    } else {
        printf("INVALID COMMAND, PLEASE TRY AGAIN\n");
        mainmenu();
    }  
}

int main() {
    mainmenu();
    return 0;
}