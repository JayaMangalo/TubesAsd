#include <stdio.h>
#include <stdlib.h>
#include "gamecommand.h"

void CommandMove(){
    int tAwal, tAkhir;
    printf(" -------------------------MOVE--------------------\n\n");
    printf("Posisi yang dapat dicapai:\n");
    int array[100];
    accessiblePosition(map,locMobita,array);
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    startCommand();
    int option = CommandToInt(currentCommand);
    printf("\n");
    tAwal = GetCurrentTime(T);
    AddTimeByMove(&T);
    tAkhir = GetCurrentTime(T);
    updToDo(&todo, &DaftarOrder, &T) ;
    if(tAkhir-tAwal>0) {
        updPerishInProgress(&Inprogress, tAkhir-tAwal);
        // printf("Selesai update perish in prog\n");
        updPerishStack(&Tas, tAkhir-tAwal);
        // printf("Selesai update perish tas\n");
        // displayInProg(Inprogress);
        // if(!isStackEmpty(Tas)) {
        //     printf("%c %c %c %d\n", PickUp(TOP(Tas)), DropOff(TOP(Tas)), TYPE(TOP(Tas)), TimePerish(TOP(Tas)));
        // }
    }
    ListDin l;
    l = LOC(map);
    if (option != 0) {
        locMobita = ELMTl(l,array[option]).name;
        printf("Mobita sekarang berada di titik ");
        printf("%c ", ELMTl(l,array[option]).name);
        TulisPOINT(ELMTl(l,array[option]).posisi);
        printf("\n");
        printf("Waktu: %d\n", GetCurrentTime(T));
    } 
}
void CommandPickUp(){   
    printf(" -----------------------PICK_UP-------------------\n\n");        
    if(searchPickUp(&todo,locMobita)){
        if (isStackFull(Tas)){
            printf("Tas Sudah Full, Tidak Bisa Melakukan Pick UP.");
        }
        else{
            PickUpItem(&todo,&Inprogress,&Tas,locMobita);
            printf("Item Berhasil di Pick Up.\n");
            if(TYPE(TOP(Tas)) == 'H'){
                Weight(T) += 1;
                if(SpeedBoost(T)>0) {
                    printf("Anda kehilangan ability Speed Boost !\n");
                }
                RemoveSpeedBoost(&T); //reset speedboost
            }
        }
    }
    else{
        printf("Tidak ada Order di Bangunan Ini/Todolist kosong.\n");
    }
}

void CommandDropOff(){
    /* KAMUS LOKAL */
    Order ord;
    /* ALGORITMA */
    printf(" -----------------------DROP_OFF------------------\n\n");
    if (isEmptyLL(Inprogress)) {
        printf("Tidak ada pesanan yang dapat diantarkan!\n");
    }else if (isStackEmpty(Tas)) {
        printf("Tas kosong! Tidak ada baran yang bisa diantar!\n");
    }
    else {
        if (DropOff(TOP(Tas)) == locMobita) {
                popStack(&Tas,&ord);
                DeliverItem(&Inprogress,locMobita);            
                if (TYPE(ord) == 'H') {
                    Weight(T)-=1;
                    AddSpeedBoost(&T);
                    if(SpeedBoost(T)>0) {
                        printf("Ability Speed Boost aktif !\n");
                        printf("Anda bergerak dua kali lebih cepat untuk %d lokasi berikutnya\n", SpeedBoost(T));
                    }
                    money += 400;
                    printf("Uang yang didapatkan : 400 Yen\n\n");
                }
                else if (TYPE(ord) == 'P') {
                    if(CurrentCap(Tas)<100) {
                        printf("Ability Increase Capacity aktif !\n");
                        printf("Kapasitas Tas menjadi %d\n", CurrentCap(Tas)+1);
                    }
                    IncreaseCapacity(&Tas);
                    money += 400;
                    printf("Uang yang didapatkan : 400 Yen!\n\n");
                }
                else {
                    money += 200;
                    printf("Uang yang didapatkan : 200 Yen!\n\n");
                }
                printf("\n");
                printf("Jumlah uang sekarang : %d Yen!\n\n", money);
                counter++;
        }
        else {
            printf("Barang di tumpukan teratas tas tidak sesuai dengan lokasi sekarang!\n");
        }
    }

}
void CommandMap(){
    printf(" --------------------------MAP--------------------\n\n");
    displayMap(map,locMobita,Tas,todo,Row,Column);
}
void CommandToDo(){
    printf(" ------------------------TO_DO--------------------\n\n");
    displayToDo(todo);
}
void CommandInProgress(){
    printf(" ---------------------IN_PROGRESS-----------------\n\n");
    displayInProg(Inprogress);
}
void CommandBuy(){
    printf(" -------------------------BUY---------------------\n\n");
    if(locMobita == '8'){
        printf("Uang Anda sekarang: %d Yen\n",money);
        printf("Gadget yang tersedia:\n");
        printf("1. Kain Pembungkus Waktu (800 Yen)\n");
        printf("2. Senter Pembesar (1200 Yen)\n");
        printf("3. Pintu Kemana Saja (1500 Yen)\n");
        printf("4. Mesin Waktu (3000 Yen)\n");
        printf("5. Senter Pengecil (800 Yen)\n");
        printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
        printf("ENTER COMMAND: ");
        startCommand();
        if(currentCommand.contents[0] == '1'){
            if (money >= 800)
            {
                if(!isGadgetFull(&InventoryGadget)){
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
        else if(currentCommand.contents[0] == '2'){
            if (money >= 1200)
            {
                if(!isGadgetFull(&InventoryGadget)){
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
        else if(currentCommand.contents[0] == '3'){
            if (money >= 1500)
            {
                if(!isGadgetFull(&InventoryGadget)){
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
        else if(currentCommand.contents[0] == '4'){
            if (money >= 3000)
            {
                if(!isGadgetFull(&InventoryGadget)){
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
        else if(currentCommand.contents[0] == '5'){
            if (money >= 800)
            {
                if(!isGadgetFull(&InventoryGadget)){
                    money -= 800;
                    insertGadget(&InventoryGadget, "Senter Pengecil");
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
        else if(currentCommand.contents[0] == '0'){
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
    printf(" ----------------------INVENTORY------------------\n\n");
    displayInventory(InventoryGadget);

    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    startCommand();
    int pilihan = CommandToInt(currentCommand);
    pilihan -= 1;
    if (ELMTListPos(InventoryGadget,pilihan)=="Kain Pembungkus Waktu"){
        useKainPembungkusWaktu(&TOP(Tas));
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
        removeGadget(&InventoryGadget,"Kain Pembungkus Waktu");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Senter Pembesar"){
        useSenterPembesar(&Tas);
        printf("Kapasitas Tas menjadi %d\n", CurrentCap(Tas));
        printf("Senter Pembesar berhasil digunakan!\n");
        removeGadget(&InventoryGadget,"Senter Pembesar");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Pintu Kemana Saja"){
        // kurang tau cara kerja lokasi sekarang gimana jadi pake POINT currentP sementara
        printf("Lokasi yang ingin dituju ada di: ");
        startCommand();
        usePintuKemanaSaja(&locMobita, currentCommand.contents[0]);
        printf("Pintu Kemana Saja berhasil digunakan!\n");
        printf("Lokasi Mobita sekarang adalah : %c\n", locMobita);
        removeGadget(&InventoryGadget,"Pintu Kemana Saja");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Mesin Waktu"){
        //kurang tau cara kerja waktu sekarang gimana jadi pake TIME T sementara
        useMesinWaktu(&T, &Inprogress, &Tas);
        printf("Mesin Waktu berhasil digunakan!\n");
        removeGadget(&InventoryGadget,"Mesin Waktu");
    } else if (ELMTListPos(InventoryGadget,pilihan)=="Senter Pengecil"){
        useSenterPengecil(&TOP(Tas),&Inprogress);
        printf("Senter Pengecil berhasil digunakan!\n");
        removeGadget(&InventoryGadget,"Senter Pengecil");
    } else {
        printf("Tidak ada Gadget yang dapat digunakan.\n");
    }
}
void CommandSave() {
    printf(" ----------------------SAVE_GAME------------------\n");
    printf("Masukkan nama save file permainan: ");
    startCommand();
    FILE *save_file;
    save_file = fopen(currentCommand.contents, "w");
    char duadigit[2];
    char satudigit;
    char blank = ' ';
    char newline = '\n';
    /* ROW */
    duadigit[0] = Row/10 + '0';
    duadigit[1] = Row%10 + '0';
    fwrite(&duadigit,1,2,save_file);
    fwrite(&blank,1,1,save_file);
    /* COLUMN */
    duadigit[0] = Column/10 + '0';
    duadigit[1] = Column%10 + '0';
    fwrite(&duadigit,1,2,save_file);
    fwrite(&newline,1,1,save_file); 
    /* HEADQUARTERS */
    if (HQ.X / 10 < 1) {
        satudigit = HQ.X + '0';
        fwrite(&satudigit,1,1,save_file);
    } else {
        duadigit[0] = HQ.X/10 + '0';
        duadigit[1] = HQ.X%10 + '0';
        fwrite(&duadigit,1,2,save_file);
    }
    fwrite(&blank,1,1,save_file);
    if (HQ.Y / 10 < 1) {
        satudigit = HQ.Y + '0';
        fwrite(&satudigit,1,1,save_file);
    } else {
        duadigit[0] = HQ.Y/10 + '0';
        duadigit[1] = HQ.Y%10 + '0';
        fwrite(&duadigit,1,2,save_file);
    }
    fwrite(&newline,1,1,save_file); 
    if ((List_bangunan.nEff-1)/10 < 1) {
        satudigit = List_bangunan.nEff-1 + '0';
        fwrite(&satudigit,1,1,save_file); 
    }  else {
        duadigit[0] = (List_bangunan.nEff-1)/10 + '0';
        duadigit[1] = (List_bangunan.nEff-1)%10 + '0';
        fwrite(&duadigit,1,2,save_file);
    }
    fwrite(&newline,1,1,save_file);
    for (int i = 0; i < List_bangunan.nEff; i++) {
        fwrite(&ELMTl(List_bangunan,i).name,1,1,save_file);
        fwrite(&blank,1,1,save_file);
        if(ELMTl(List_bangunan,i).posisi.X/10 < 1) {
            satudigit = ELMTl(List_bangunan,i).posisi.X + '0';
            fwrite(&satudigit,1,1,save_file);
        } else {
            duadigit[0] = ELMTl(List_bangunan,i).posisi.X/10 + '0';
            duadigit[1] = ELMTl(List_bangunan,i).posisi.X%10 + '0';
            fwrite(&duadigit,1,2,save_file);
        }
        fwrite(&blank,1,1,save_file);
        if(ELMTl(List_bangunan,i).posisi.Y/10 < 1) {
            satudigit = ELMTl(List_bangunan,i).posisi.Y + '0';
            fwrite(&satudigit,1,1,save_file);
        } else {
            duadigit[0] = ELMTl(List_bangunan,i).posisi.Y/10 + '0';
            duadigit[1] = ELMTl(List_bangunan,i).posisi.Y%10 + '0';
            fwrite(&duadigit,1,2,save_file);
        }
        fwrite(&newline,1,1,save_file);
    }
    for(int i=0;i<ROWS(m);i++) {
        for(int j=0;j<COLS(m);j++) {
            satudigit = ELMT(m,i,j) + '0';
            fwrite(&satudigit,1,1,save_file);
            if (j < COLS(m) - 1) {
                fwrite(&blank,1,1,save_file);
            }
        }
        fwrite(&newline,1,1,save_file);
    }
    if((DaftarOrder.idxTail - DaftarOrder.idxHead + 1)/10 < 1) {
        satudigit = (DaftarOrder.idxTail - DaftarOrder.idxHead + 1) + '0';
        fwrite(&satudigit,1,1,save_file);
    } else {
        duadigit[0] = (DaftarOrder.idxTail - DaftarOrder.idxHead + 1)/10 + '0';
        duadigit[1] = (DaftarOrder.idxTail - DaftarOrder.idxHead + 1)%10 + '0';
        fwrite(&duadigit,1,2,save_file);
    }
    fwrite(&newline,1,1,save_file);
    // punten ini kenapa cuman 8 biji yak yg kedetectnya? :(
    for(int i = 0; i < DaftarOrder.idxTail - DaftarOrder.idxHead + 1; i++) {
        if(DaftarOrder.buffer[i].tArrival/10 < 1) {
            satudigit = DaftarOrder.buffer[i].tArrival + '0';
            fwrite(&satudigit,1,1,save_file);
        } else if(DaftarOrder.buffer[i].tArrival/100 < 1) {
            duadigit[0] = DaftarOrder.buffer[i].tArrival/10 + '0';
            duadigit[1] = DaftarOrder.buffer[i].tArrival%10 + '0';
            fwrite(&duadigit,1,2,save_file);
        }
        fwrite(&blank,1,1,save_file);
        fwrite(&DaftarOrder.buffer[i].pick_up_point,1,1,save_file);
        fwrite(&blank,1,1,save_file);
        fwrite(&DaftarOrder.buffer[i].drop_off_point,1,1,save_file);
        fwrite(&blank,1,1,save_file);
        fwrite(&DaftarOrder.buffer[i].type,1,1,save_file);
        if(DaftarOrder.buffer[i].type == 'P') {
            fwrite(&blank,1,1,save_file);
            if(DaftarOrder.buffer[i].tPerish / 10 < 1) {
                satudigit = DaftarOrder.buffer[i].tPerish + '0';
                fwrite(&satudigit,1,1,save_file);
            } else {
                duadigit[0] = DaftarOrder.buffer[i].tPerish/10 + '0';
                duadigit[1] = DaftarOrder.buffer[i].tPerish%10 + '0';
                fwrite(&duadigit,1,2,save_file);
            }
        }
        if (i < DaftarOrder.idxTail - DaftarOrder.idxHead) {
            fwrite(&newline,1,1,save_file);
        }
    }
    char mark = '.';
    fwrite(&mark,1,1,save_file);
    fwrite(&newline,1,1,save_file);
    fclose(save_file);
    printf("Save file berhasil dibuat!\n\n");
}
void CommandHelp(){
    printf(" -------------------------HELP--------------------\n");
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
    /* printf("10. SAVE_GAME : Menyimpan file konfigurasi permainan.\n"); */
    printf("10. EXIT : Keluar dari game Mobilita Delivery Services.\n");
    printf("\n");
}
boolean CommandExit(){
    printf(" -------------------------EXIT--------------------\n\n");
    printf("ARE YOU SURE YOU WANT TO EXIT THE GAME? YOUR PROGRESS WILL NOT BE SAVED\n");
    printf("(Y/N)\n");
    printf("ENTER COMMAND: ");

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