#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "setup.h"

Command NEW_GAME;
Command LOAD_GAME;
Command EXIT;
Command MOVE;
Command PICK_UP;
Command DROP_OFF;
Command TO_DO;
Command MAP;
Command IN_PROGRESS;
Command BUY;
Command INVENTORY;
Command HELP;
Command EXIT;
Command Y;
Command N;

int Row;
int Column;
POINT HQ;
ListDin List_bangunan; 
Matrix m;
Daftar DaftarOrder;
List todo;
Map map;
char locMobita;
List Inprogress;
Stack Tas;
Inventory InventoryGadget;
Time T;
int money;

void setupCommand(){
    char new_game[100] = "NEW GAME";
    int new_game_length = 8;
    NEW_GAME = StringtoCommand(new_game,new_game_length);

    char load_game[100] = "LOAD GAME";
    int load_game_length = 9;
    LOAD_GAME = StringtoCommand(load_game,load_game_length);

    char exit[100] = "EXIT";
    int exit_length = 4;
    EXIT = StringtoCommand(exit,exit_length);

    char move[100] = "MOVE";
    int move_length = 4;
    MOVE = StringtoCommand(move,move_length);
    
    char pick_up[100] = "PICK_UP";
    int pick_up_length = 7;
    PICK_UP = StringtoCommand(pick_up,pick_up_length);
    
    char drop_off[100] = "DROP_OFF";
    int drop_off_length = 8;
    DROP_OFF = StringtoCommand(drop_off,drop_off_length);
    
    char to_do[100] = "TO_DO";
    int to_do_length = 5;
    TO_DO = StringtoCommand(to_do,to_do_length);

    char map[100] = "MAP";
    int map_length = 3;
     MAP = StringtoCommand(map,map_length);
    
    char in_progress[100] = "IN_PROGRESS";
    int in_progress_length = 11;
     IN_PROGRESS = StringtoCommand(in_progress,in_progress_length);
    
    char buy[100] = "BUY";
    int buy_length = 3;
     BUY = StringtoCommand(buy,buy_length);
    
    char inventory[100] = "INVENTORY";
    int inventory_length = 9;
     INVENTORY = StringtoCommand(inventory,inventory_length);
    
    char help[100] = "HELP";
    int help_length = 4;
     HELP = StringtoCommand(help,help_length);

    char y[100] = "Y";
    int y_length = 1;
    Y = StringtoCommand(y,y_length);

    char n[100] = "N";
    int n_length = 1;
    N = StringtoCommand(n,n_length);   
}

void setupGame(){
    startWord();

    //GET BANYAK ROW&COLUMN AND CHANGE IT
    Row = WordToInt(currentWord);
    advWord();
    Column = WordToInt(currentWord);


    //GET HQ COORDINATES AND CHANGE IT
    int Absis, Ordinat;
    advWord();
    Absis = WordToInt(currentWord);
    advWord();
    Ordinat = WordToInt(currentWord);
    HQ = MakePOINT(Absis,Ordinat);

    //GET BANYAK BANGUNAN
    int Bangunan_amount;
    advWord();
    Bangunan_amount = WordToInt(currentWord);

    //MAKE LISTDIN BANGUNAN
    CreateListDin(&List_bangunan,Bangunan_amount);


    //MAKE POINT OF HQ AND INSERT TO LISTDIN BANGUNAN
    POINT p;
    p = MakePOINT(Absis,Ordinat);
    insertBangunan(&List_bangunan, '8' ,p);

    //MAKE POINT OF BANGUNAN AND INSERT TO LISTDIN BANGUNAN (FOR LOOP BANYAK BANGUNAN)
    char bangunan_nama;
    for (int i = 0; i < Bangunan_amount; i++)
    {
        //GET POINT FOR BANGUNAN
        advWord();
        bangunan_nama =  currentWord.contents[0];
        advWord();
        Absis = WordToInt(currentWord);
        advWord();
        Ordinat = WordToInt(currentWord);

        //MAKE POINT OF BANGUNAN AND INSERT TO LISTDIN BANGUNAN
        p = MakePOINT(Absis,Ordinat);
        insertBangunan(&List_bangunan, bangunan_nama ,p);
    }

    //GET AND MAKE ADJANCENCY MATRIX
    CreateMatrix(Bangunan_amount+1,Bangunan_amount+1,&m);
    for(int i=0;i<ROWS(m);i++) {
        for(int j=0;j<COLS(m);j++) {
            advWord();
            ELMT(m,i,j) = WordToInt(currentWord);
        }
    }

    //GET BANYAK ORDER
    int Order_amount;
    advWord();
    CreatePrioQueue(&DaftarOrder);
    Order_amount = WordToInt(currentWord);
    Order ord;
    for (int i = 0; i < Order_amount; i++)
    {
        advWord();
        TimeIn(ord) = WordToInt(currentWord);
        advWord();
        PickUp(ord) = currentWord.contents[0];
        advWord();
        DropOff(ord) = currentWord.contents[0];
        advWord();
        TYPE(ord) =  currentWord.contents[0];
        if (currentWord.contents[0] == 'P')
        {
            advWord();
            TimePerishDefault(ord) = WordToInt(currentWord);
            TimePerish(ord) = TimePerishDefault(ord);
        }
        else{
            TimePerish(ord) = 0;
            TimePerishDefault(ord) = TimePerish(ord);
        }
        enqueue(&DaftarOrder, ord);
    }
    map.mat = m;
    map.lokasi = List_bangunan;
    CreateStack(&Tas);
    CreateList(&Inprogress);
    CreateInventory(&InventoryGadget);
    CreateTime(&T);
    CreateList(&todo);
    updToDo(&todo, &DaftarOrder, &T);
    money = 0;
    locMobita = '8';

    printf("GAME INITIALIZED SUCCESFULLY\n");
}
