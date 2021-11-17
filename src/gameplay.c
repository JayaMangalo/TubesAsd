#include <stdio.h>
#include "gamecommand/gamecommand.h"

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
extern Command Exit;


void game_play() {
    printf(" ----------------WELCOME TO THE GAME--------------\n\n");
    printf("Mobita berada di posisi ");

    /* TAMBAHAN DISPLAY LOKASI TERKINI MOBITA */
    ListDin l;
    l = LOC(map);
    if(ELMTl(l,0).name == '8') {
        printf("Headquarters ");
    }
    TulisPOINT(ELMTl(l,0).posisi);
    printf("\n");
    printf("Waktu: %.0f\n", CurrentTime(T));
    boolean endgame = false;
    while(endgame == false){
        printf("\n");
        printf(" ----------------MOBITA DELIVERY SERVICE----------\n\n");
        if (isEmptyLL(Inprogress) && isEmptyLL(todo) && GetCurrentTime(T) > 0) {
            endgame = true;
            printf("CONGRATULATIONS! YOU HAVE COMPLETED THE GAME!\n");
            printf("Uang yang didapatkan : %d Yen\n", money);
            printf("Jumlah pesanan yang berhasil diantarkan : %d \n", counter);
        }
        else {
            printf("ENTER COMMAND: ");
            startCommand();
            printf("\n");
            if(isEqualCommand(currentCommand,MOVE))
            { 
                CommandMove();
            }
            else if(isEqualCommand(currentCommand,PICK_UP)){
                CommandPickUp();
            }
            else if(isEqualCommand(currentCommand,DROP_OFF)){
                CommandDropOff();
            }
            else if(isEqualCommand(currentCommand,MAP)){
                CommandMap();
            }
            else if(isEqualCommand(currentCommand,TO_DO)){
                CommandToDo();
            }
            else if(isEqualCommand(currentCommand,IN_PROGRESS)){
                CommandInProgress();
            }
            else if(isEqualCommand(currentCommand,BUY)){
                CommandBuy();
            }   
            else if(isEqualCommand(currentCommand,INVENTORY)){
                CommandInventory();
            }
            else if(isEqualCommand(currentCommand,HELP)){
                CommandHelp();
            }
            else if(isEqualCommand(currentCommand,EXIT)){
                if(CommandExit() == true ){
                    endgame = true;
                }
            }
            else{
                printf("INVALID COMMAND, TRY AGAIN (TYPE 'HELP' FOR LIST OF COMMANDS)\n");
            }
        }
        
    }
}
void mainmenu(){
    setupCommand();
    printf("--------------------------------------------------\n\n");
    printf("            GAME MOBILITA DELIVERY SERVICES       \n");
    printf("                 BY GROUP 04 CLASS 01             \n\n");
    printf(" ----------------------MAIN MENU------------------\n\n");
    printf("1. NEW GAME\n");
    printf("2. LOAD GAME (Incoming Next Update)\n");
    printf("3. EXIT\n\n");
    printf("ENTER COMMAND: ");
    startCommand();
    printf("\n");
    if (isEqualCommand(currentCommand,NEW_GAME)) {
        printf(" ----------------------NEW GAME-------------------\n\n");
        printf("INPUT NAMA FILE: ");
        startCommand();
        setupGame();
        game_play();
    } else if(isEqualCommand(currentCommand,LOAD_GAME)) {
        printf("LOAD GAME is Incoming Next Update, PLEASE TRY AGAIN\n"); 
        mainmenu();
        // printf("INPUT NAMA FILE: ");
        // startCommand();
        // setupGame();     
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