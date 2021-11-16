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
Map map;
char locMobita;
Inventory InventoryGadget;

Command Y;
Command N;

void CommandMove(){
    //donothing
}
void CommandPickUp(){           
    if(searchPickUp(todo,locMobita)){
        if (isStackFull(Tas)){
            printf("Tas Sudah Full, Tidak Bisa Melakukan Pick UP.");
        }
        else{
            PickUpItem(&todo,&Inprogress,&Tas,locMobita);
            printf("Item Berhasil di Pick Up.\n");
        }
    }
    else{
        printf("Tidak ada Order di Bangunan Ini.\n");
    }
}

void CommandDropOff(List *inprog, Stack *tas, char loc){
    // /* KAMUS LOKAL */
    // Address current = FIRST(*inprog);
    // int i = 0;
    // Order ord;
    // /* ALGORITMA */
    // while ((current != NULL) && (DropOff(INFO(current)) != loc)) {
    //     i += 1;
    //     current = NEXT(current);
    // }

    // if (DropOff(INFO(current)) == loc) {
    //     if (INFO(current) == TOP(*tas)) { // udah dites, tinggal ngebandingin dua order sama atau ngga
    //         popStack(tas,&ord);
    //         deleteAt(inprog,i,&ord);
    //         printf("Barang berhasil diantarkan pada lokasi %c.\n", loc);
    //     }
    //     else {
    //         printf("Item teratas pada tas tidak sesuai dengan pesanan pada lokasi.\n");
    //     }
    // }
    // else {
    //     printf("Tidak ada pesanan pada lokasi.\n");
    // }
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
    if(locMobita == "8"){
        printf("Uang Anda sekarang: %d Yen\n",money);
        printf("Gadget yang tersedia:\n");
        printf("1. Kain Pembungkus Waktu (800 Yen)\n");
        printf("2. Senter Pembesar (1200 Yen)\n");
        printf("3. Pintu Kemana Saja (1500 Yen)\n");
        printf("4. Mesin Waktu (3000 Yen)\n");
        printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");

        
        startCommand();
        if(currentCommandChar == "1"){
            if (money >= 800)
            {
                money -= 800;
                //masukin ke inventory gadget.
                printf("Gadget telah dibeli.\n");
            }
            else{
                printf("Uang tidak cukup untuk membeli gadget tersebut.\n");
            }
        }
        else if(currentCommandChar == "2"){
            if (money >= 1200)
            {
                money -= 1200;
                //masukin ke inventory gadget.
                printf("Gadget telah dibeli.\n");
            }
            else{
                printf("Uang tidak cukup untuk membeli gadget tersebut.\n");
            }
        }
        else if(currentCommandChar == "3"){
            if (money >= 1500)
            {
                money -= 1500;
              //masukin ke inventory gadget.
                printf("Gadget telah dibeli.\n");
            }
            else{
                printf("Uang tidak cukup untuk membeli gadget tersebut.\n");
            }
        }
        else if(currentCommandChar == "4"){
            if (money >= 3000)
            {
                money -= 3000;
                //masukin ke inventory gadget.
                printf("Gadget telah dibeli.\n");
            }
            else{
                printf("Uang tidak cukup untuk membeli gadget tersebut.\n");
            }
        }
        else if(currentCommandChar == "0"){
            printf("Cancelling...\n");
        }
        else{
            printf("Input salah, Cancelling...\n");
        }
    }
    else{
        printf("Command Buy Hanya Bisa dilakukan di HQ.\n");
    }
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
    
}