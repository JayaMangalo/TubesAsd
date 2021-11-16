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
Map map;
char locMobita;
Inventory InventoryGadget;
Time T;

Command Y;
Command N;

void CommandMove(){
    printf("Posisi yang dapat dicapai:\n");
    accessiblePosition(map,locMobita);
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    startCommand();
    int option = CommandToInt(currentCommand);
    printf("\n");
    AddTimeByMove(&T);
    printf("Waktu: %.0f\n", CurrentTime(T));
    printf("Mobita sekarang berada di titik");
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

void CommandDropOff(){
    /* KAMUS LOKAL */
    Address current = FIRST(Inprogress);
    int i = 0;
    Order ord;
    /* ALGORITMA */
    while ((current != NULL) && (DropOff(INFO(current)) != locMobita)) {
        i += 1;
        current = NEXT(current);
    }

    if (DropOff(INFO(current)) == locMobita) {
        if (isOrderEqual(INFO(current), TOP(Tas))) {
            popStack(&Tas,&ord);
            DeliverItem(&Inprogress,locMobita);
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
    displayInProg(Inprogress);
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
                if(isGadgetFull(&InventoryGadget)){
                    money -= 800;
                    insertGadget(&InventoryGadget, "Kain Pembungkus Waktu");
                    printf("Gadget telah dibeli.\n");
                }
                else{
                    printf("Inventory Gadget sudah full. Cancelling...");
                }
            }
            else{
                printf("Uang tidak cukup untuk membeli gadget tersebut.\n");
            }
        }
        else if(currentCommandChar == "2"){
            if (money >= 1200)
            {
                if(isGadgetFull(&InventoryGadget)){
                    money -= 1200;
                    insertGadget(&InventoryGadget, "Senter Pembesar");
                    printf("Gadget telah dibeli.\n");
                }
                else{
                    printf("Inventory Gadget sudah full. Cancelling...");
                }
            }
            else{
                printf("Uang tidak cukup untuk membeli gadget tersebut.\n");
            }
        }
        else if(currentCommandChar == "3"){
            if (money >= 1500)
            {
                if(isGadgetFull(&InventoryGadget)){
                    money -= 1500;
                    insertGadget(&InventoryGadget, "Pintu Kemana Saja");
                    printf("Gadget telah dibeli.\n");
                }
                else{
                    printf("Inventory Gadget sudah full. Cancelling...");
                }
            }
            else{
                printf("Uang tidak cukup untuk membeli gadget tersebut.\n");
            }
        }
        else if(currentCommandChar == "4"){
            if (money >= 3000)
            {
                if(isGadgetFull(&InventoryGadget)){
                    money -= 3000;
                    insertGadget(&InventoryGadget, "Mesin Waktu");
                    printf("Gadget telah dibeli.\n");
                }
                else{
                    printf("Inventory Gadget sudah full. Cancelling...");
                }
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
    displayInventory(InventoryGadget);

    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    startCommand();
    int pilihan = CommandToInt(currentCommand);
    pilihan -= 1;
    if (ELMTListPos(InventoryGadget,pilihan)=="Kain Pembungkus Waktu"){
        useKainPembungkusWaktu(&Tas);
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Senter Pembesar"){
        useSenterPembesar(&Tas);
        printf("Senter Pembesar berhasil digunakan!\n");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Pintu Kemana Saja"){
        // kurang tau cara kerja lokasi sekarang gimana jadi pake POINT currentP sementara
        char Goal;
        printf("Lokasi yang ingin dituju ada di: ");
        scanf(" %c", Goal);
        usePintuKemanaSaja(locMobita, Goal);
        printf("Pintu Kemana Saja berhasil digunakan!\n");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Mesin Waktu"){
        //kurang tau cara kerja waktu sekarang gimana jadi pake TIME T sementara
        useMesinWaktu(&T);
        printf("Mesin Waktu berhasil digunakan!\n");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Mesin Waktu"){
        useSenterPengecil(&Tas);
        printf("Senter Pengecil berhasil digunakan!\n");
    } else {
        printf("Tidak ada Gadget yang d digunakan.\n");
    }
}
void CommandHelp(){
    printf(" ----------------------HELP------------------\n");
    printf("\n");
    printf("1. MOVE : Menampilkan pilihan lokasi yang dapat dicapai dan berpindah ke tempat pilihan\n");
    printf("2. PICK_UP : Mengambil item pada lokasi dan menghapusnya dari To-Do list.\n");
    printf("3. DROP_OFF : Mengantarkan item pada lokasi.\n");
    printf("4. MAP : Menampilkan peta.\n");
    printf("5. TO_DO : Menampilkan pesanan yang masuk pada To Do list.\n");
    printf("6. IN_PROGRESS : Menampilkan barang yang sedang diantarkan.\n");
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
    
}