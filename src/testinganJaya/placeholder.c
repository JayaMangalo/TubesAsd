#include <stdio.h>
#include "boolean.h"
#include "prototypeTime.c"
#include "point.h"

int main(){
    POINT MC ;
    boolean endgame = false;
    while(endgame == false){
        
        if(command == "MOVE"){
            AddTimeByMove(Time *T);
            //Update location
            //update to do list
        }
        else if(command == "PICK_UP"){}
        else if(command == "DROP_OFF"){}
        else if(command == "PETA"){}
        else if(command == "TO_DO"){}
        else if(command == " IN_PROGRESS"){}
        else if(command == "BUY"){}
        else if(command == "INVENTORY"){}
        else if(command == "HELP"){}
        else{
            printf("Input Invalid");
        }

    }
}