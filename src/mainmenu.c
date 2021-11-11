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

int main(){
    setupCommand(); //fungsi ini buat ngisi command-command diatas biar gausah diisi disini. 

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
        setupGame(&BarisMap, &KolomMap, &HQ,  &List_bangunan, &m, &DaftarOrder);
    } else if(isEqualCommand(currentCommand,LOAD_GAME)) {
        printf("INPUT NAMA FILE: ");
        startCommand();
        setupGame(&BarisMap, &KolomMap, &HQ,  &List_bangunan, &m, &DaftarOrder);     
    } else if(isEqualCommand(currentCommand,EXIT)) {
        printf("YOU'VE ENDED THIS GAME");
    } else {
        printf("INVALID COMMAND, PLEASE TRY AGAIN\n");
    }  

    boolean endgame = false;
    while(!endgame){
        printf("ENTER COMMAND: ");
        startCommand();
        if(isEqualCommand(currentCommand,MOVE))
        { printf("MOVED\n");}
        else if(isEqualCommand(currentCommand,PICK_UP)){}
        else if(isEqualCommand(currentCommand,DROP_OFF)){}
        else if(isEqualCommand(currentCommand,MAP)){}
        else if(isEqualCommand(currentCommand,TO_DO)){}
        else if(isEqualCommand(currentCommand,IN_PROGRESS)){}
        else if(isEqualCommand(currentCommand,BUY)){}
        else if(isEqualCommand(currentCommand,INVENTORY)){}
        else if(isEqualCommand(currentCommand,HELP)){}
        else{
            printf("INVALID COMMAND, TRY AGAIN (TYPE 'HELP' FOR LIST OF COMMANDS)\n");
        }
    }

    return 0;
}