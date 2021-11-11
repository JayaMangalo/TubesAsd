#include <stdio.h>
#include "setup/setup.h"

int main(){

    Command NEW_GAMES;
    char new_game[100] = "NEW GAME";
    int new_game_length = 8;
    NEW_GAMES = StringtoCommand(new_game,new_game_length);

    Command LOAD_GAMES;
    char load_game[100] = "LOAD GAME";
    int load_game_length = 9;
    LOAD_GAMES = StringtoCommand(load_game,load_game_length);

    Command EXIT;
    EXIT.contents[0] = 'E';
    EXIT.contents[1] = 'X';
    EXIT.contents[2] = 'I';
    EXIT.contents[3] = 'T';
    EXIT.length = 4;

    printf("MAIN MENU\n");
    printf("ENTER COMMAND: ");
    startCommand();

    int BarisMap,KolomMap;
    POINT HQ;
    ListDin List_bangunan;
    Matrix m;
    Daftar DaftarOrder;

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
        setup(&BarisMap, &KolomMap, &HQ,  &List_bangunan, &m, &DaftarOrder);
    } else if(isEqualCommand(currentCommand,LOAD_GAMES)) {
        printf("INPUT NAMA FILE: ");
        startCommand();
        setup(&BarisMap, &KolomMap, &HQ,  &List_bangunan, &m, &DaftarOrder);     
    } else if(isEqualCommand(currentCommand,EXIT)) {
        printf("YOU'VE ENDED THIS GAME");
    } else {
        printf("INVALID COMMAND, PLEASE TRY AGAIN");
    }  

    
    char move[100] = "MOVE";
    int move_length = 4;
    Command MOVE = StringtoCommand(move,move_length);
    
    char pick_up[100] = "PICK_UP";
    int pick_up_length = 7;
    Command PICK_UP = StringtoCommand(pick_up,pick_up_length);
    
    char drop_off[100] = "DROP_OFF";
    int drop_off_length = 8;
    Command DROP_OFF = StringtoCommand(drop_off,drop_off_length);
    
    char to_do[100] = "TO_DO";
    int to_do_length = 5;
    Command TO_DO = StringtoCommand(to_do,to_do_length);

    char map[100] = "MAP";
    int map_length = 5;
    Command MAP = StringtoCommand(map,map_length);
    
    char in_progress[100] = "IN_PROGRESS";
    int in_progress_length = 11;
    Command IN_PROGRESS = StringtoCommand(in_progress,in_progress_length);
    
    char buy[100] = "BUY";
    int buy_length = 3;
    Command BUY = StringtoCommand(buy,buy_length);
    
    char inventory[100] = "INVENTORY";
    int inventory_length = 9;
    Command INVENTORY = StringtoCommand(inventory,inventory_length);
    
    char help[100] = "HELP";
    int help_length = 4;
    Command HELP = StringtoCommand(help,help_length);
    
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