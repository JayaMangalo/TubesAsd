#include <stdio.h>
#include "../setup/setup.h"

List inProg;
POINT currentP;
Time T;
Inventory Inv;

void CommandInProgress(){
    displayInProg(inProg);
}

void CommandInventory(){
// di src ama setup.h perlu ditambahin ADTListpos
// tambahin juga use_gadget.c yang ada di folder gadget
    displayInventory(Inv);
    int pilihan;
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    scanf("%d", &pilihan);
    pilihan -= 1;
    if (ELMTListPos(Inv,pilihan)=="Kain Pembungkus Waktu"){
        useKainPembungkusWaktu(&Tas);
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
    } else if (ELMTListPos(Inv,pilihan)=="Senter Pembesar"){
        useSenterPembesar(&Tas);
        printf("Senter Pembesar berhasil digunakan!\n");
    } else if (ELMTListPos(Inv,pilihan)=="Pintu Kemana Saja"){
        // kurang tau cara kerja lokasi sekarang gimana jadi pake POINT currentP sementara
        POINT Goal;
        printf("Lokasi yang ingin dituju ada di poin: ");
        scanf(" %d %d", &Absis(Goal), &Ordinat(Goal));
        usePintuKemanaSaja(&currentP, Goal);
        printf("Pintu Kemana Saja berhasil digunakan!\n");
    } else if (ELMTListPos(Inv,pilihan)=="Mesin Waktu"){
        //kurang tau cara kerja waktu sekarang gimana jadi pake TIME T sementara
        useMesinWaktu(&T);
        printf("Mesin Waktu berhasil digunakan!\n");
    } else if (ELMTListPos(Inv,pilihan)=="Mesin Waktu"){
        useSenterPengecil(&Tas);
        printf("Senter Pengecil berhasil digunakan!\n");
    } else {
        printf("Tidak ada Gadget yang d digunakan.\n");
    }
}
