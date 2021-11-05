/* Driver ADT POINT */

#include<stdio.h>
#include "garis.h"

int main() {
    /* KAMUS */
    GARIS L1, L2;
    /* ALGORITMA */
    printf("TEST Konstruktor\n");
    MakeGARIS(MakePOINT(2,7),MakePOINT(3,7),&L1);
    TulisGARIS(L1); printf("\n");

    printf("\n");
    printf("TEST BACA/TULIS\n");
    BacaGARIS(&L2);
    TulisGARIS(L2); printf("\n");

    printf("\n");
    printf("TEST Operasi Relasional\n");
    if(IsTegakLurus(L1,L2)) {
        printf("L1 dan L2 tegak lurus\n");
    }
    if(IsSejajar(L1,L2)) {
        printf("L1 dan L2 sejajar\n");
    }

    printf("\n");
    printf("TEST operasi lain\n");
    printf("Panjang garis L1 adalah %.2f", PanjangGARIS(L1));
    printf("Gradien L1 adalah %.2f", Gradien(L1));
    printf("Panjang garis L2adalah %.2f", PanjangGARIS(L2));
    printf("Gradien L2 adalah %.2f", Gradien(L2));
    GeserGARIS(&L1,2.0,3.0);
    printf("Sekarang L1 digeser 2 dan 3 menjadi "); TulisGARIS(L1); printf("\n");
}