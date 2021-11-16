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

void CommandDropOff(List *inprog, stack *tas, char loc){
    /* KAMUS LOKAL */
    Address current = FIRST(*inprog);
    int i = 0;
    Order ord;
    /* ALGORITMA */
    while ((current != NULL) && (DropOff(INFO(current)) != loc)) {
        i += 1;
        current = NEXT(current);
    }

    if (DropOff(INFO(current)) == loc) {
        if (INFO(current) == TOP(*tas)) { // masih belum bisa ngebandingin item di tas sama di order
            pop(*tas,&ord);
            deleteAt(*inprog,i,&ord);
        }
        else {
            printf("Item teratas pada tas tidak sesuai dengan pesanan pada lokasi.\n");
        }
    }
    else {
        printf("Tidak ada pesanan pada lokasi.\n");
    }
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
    printf(" ----------------------HELP------------------\n");
    printf("LIST COMMAND YANG BISA DIMASUKKAN\n");
    printf("1. MOVE : Menampilkan pilihan lokasi yang dapat dicapai dan berpindah ke tempat pilihan\n");
    printf("2. PICK_UP : Mengambil item pada lokasi dan menghapusnya dari To-Do list.")
    printf("3. DROP_OFF : Mengantarkan item pada lokasi.");
    printf("4. MAP : Menampilkan peta.");
    printf("5. TO_DO : Menampilkan pesanan yang masuk pada To Do list.\n");
    printf("6. BUY : Digunakan untuk menampilkan gadget yang dapat dibeli. Hanya dapat dipanggil di HQ.\n");
    printf("7. INVENTORY : Menampilkan isi list inventory (gadgets) dan bisa memilih menggunakan gadget.\n");
    printf("8. HELP : Menampilkan list command dan penjelasannya.\n");
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