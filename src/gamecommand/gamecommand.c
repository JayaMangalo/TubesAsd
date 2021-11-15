#include <stdio.h>
#include "gamecommand.h"

int Row;
int Column;
POINT HQ;
ListDin List_bangunan; 
Matrix m;
Daftar DaftarOrder;
List todo;
Stack Tas;

Command Y;
Command N;

void CommandMove(){
    //donothing
}
void CommandPickUp(){           //blomselesai
    if (isStackFull(Tas)){
        printf("Tas Sudah Full, Tidak Bisa Melakukan Pick UP.");
    }
    else{
        //
    }
}

void CommandDropOff(){

}
void CommandMap(){

}
void CommandToDo(){
    displayToDo(todo);
}
void CommandInProgress(){

}
void CommandBuy(){

}
void CommandInventory(){
    
}
void CommandHelp(){

}
boolean CommandExit(){
    printf("ARE YOU SURE YOU WANT TO EXIT THE GAME? YOUR PROGRESS WILL NOT BE SAVED\n");
    printf("YES/NO");

    boolean correctinput = true;
    while (correctinput){
        startCommand();
        if(isEqualCommand(currentCommand,Y)){
            printf("EXITING GAME....\n");
            return true;
        }
        else if(isEqualCommand(currentCommand,N)){
            printf("EXIT Cancelled....\n");
            printf("Returning to game...\n");
            return false;
        }
        else{
            printf("Input Invalid: (Y/N)");
        }
    }
    
}