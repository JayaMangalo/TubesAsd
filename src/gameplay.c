#include <stdio.h>
#include "setup/setup.h"
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
    printf("===================\n");
    printf("WELCOME TO THE GAME\n");
    printf("Mobita berada di posisi\n");

    boolean endgame = false;
    while(endgame == false){
        printf("ENTER COMMAND: ");
        startCommand();
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
void mainmenu(){
    setupCommand();
    printf(" ----------------------MAIN MENU------------------\n");
    printf("1. NEW GAME\n");
    printf("2. LOAD GAME (Incoming Next Update)\n");
    printf("3. EXIT\n");
    startCommand();

    if (isEqualCommand(currentCommand,NEW_GAME)) {
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