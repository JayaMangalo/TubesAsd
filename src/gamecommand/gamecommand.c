<<<<<<< HEAD
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
    // if (isStackFull(Tas)){
    //     printf("Tas Sudah Full, Tidak Bisa Melakukan Pick UP.");
    // }
    // else{
    //     //
    // }
}

void CommandDropOff(List *inprog, Stack *tas, char loc){
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
        if (INFO(current) == TOP(*tas)) { // udah dites, tinggal ngebandingin dua order sama atau ngga
            popStack(tas,&ord);
            deleteAt(inprog,i,&ord);
            printf("Barang berhasil diantarkan pada lokasi %c.\n", loc);
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
    displayMap(map,locMobita,Tas,todo,Row,Column);
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
    printf("\n");
    printf("1. MOVE : Menampilkan pilihan lokasi yang dapat dicapai dan berpindah ke tempat pilihan\n");
    printf("2. PICK_UP : Mengambil item pada lokasi dan menghapusnya dari To-Do list.\n");
    printf("3. DROP_OFF : Mengantarkan item pada lokasi.\n");
    printf("4. MAP : Menampilkan peta.\n");
    printf("5. TO_DO : Menampilkan pesanan yang masuk pada To Do list.\n");
    printf("6. BUY : Digunakan untuk menampilkan gadget yang dapat dibeli. Hanya dapat dipanggil di HQ.\n");
    printf("7. INVENTORY : Menampilkan isi list inventory (gadgets) dan bisa memilih menggunakan gadget.\n");
    printf("8. HELP : Menampilkan list command dan penjelasannya.\n");
    printf("\n");
    printf("----------------------------------------------\n");
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
    
=======
#include <stdio.h>
#include "gamecommand.h"

int Row;
int Column;
POINT HQ;
ListDin List_bangunan; 
Matrix m;
Daftar DaftarOrder;
List todo;
List Inprogress;
Stack Tas;

Command Y;
Command N;

void CommandMove(){
    //donothing
}
void CommandPickUp(){           //blomselesai
    // if (isStackFull(Tas)){
    //     printf("Tas Sudah Full, Tidak Bisa Melakukan Pick UP.");
    // }
    // else{
    //     //
    // }
}

void CommandDropOff(char loc){
    /* KAMUS LOKAL */
    Address current = FIRST(Inprogress);
    int i = 0;
    Order ord;
    /* ALGORITMA */
    while ((current != NULL) && (DropOff(INFO(current)) != loc)) {
        i += 1;
        current = NEXT(current);
    }

    if (DropOff(INFO(current)) == loc) {
        if (isOrderEqual(INFO(current), TOP(Tas))) {
            popStack(&Tas,&ord);
            deleteAt(&Inprogress,i,&ord);
            printf("Barang berhasil diantarkan pada lokasi %c.\n", loc);
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
    printf("\n");
    printf("1. MOVE : Menampilkan pilihan lokasi yang dapat dicapai dan berpindah ke tempat pilihan\n");
    printf("2. PICK_UP : Mengambil item pada lokasi dan menghapusnya dari To-Do list.\n");
    printf("3. DROP_OFF : Mengantarkan item pada lokasi.\n");
    printf("4. MAP : Menampilkan peta.\n");
    printf("5. TO_DO : Menampilkan pesanan yang masuk pada To Do list.\n");
    printf("6. IN_PROGRESS : Menampilkan item yang sedang diantarkan.\n");
    printf("7. BUY : Digunakan untuk menampilkan gadget yang dapat dibeli. Hanya dapat dipanggil di HQ.\n");
    printf("8. INVENTORY : Menampilkan isi list inventory (gadgets) dan bisa memilih menggunakan gadget.\n");
    printf("9. HELP : Menampilkan list command dan penjelasannya.\n");
    printf("\n");
    printf("----------------------------------------------\n");
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
    
>>>>>>> 3165a6ed2be4ef478bc307dcfa7f9131ccf5b5a0
}