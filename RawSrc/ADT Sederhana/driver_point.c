/* File: driver_point.c */
/* Tnnggal: 2 September 2021 */
/* Driver ADT POINT */

#include<stdio.h>
#include "point.h"

int main() {
    /* KAMUS */
    POINT P1, P2, P3, P4, P5;
    /* ALGORITMA */
    printf("TEST Konstruktor\n");
    P1 = MakePOINT(2.0,7.0);
    printf("P1 memiliki koordinat "); TulisPOINT(P1); printf("\n");

    printf("\n");
    printf("TEST BACA/TULIS\n");
    printf("Masukkan absis dan ordinat P2:\n");
    BacaPOINT(&P2);
    printf("P2 memiliki koordinat "); TulisPOINT(P2); printf("\n");

    printf("\n");
    printf("TEST Operasi Relasional\n");
    if(EQ(P1,P1)) {
        printf("P1 dan P1 memiliki koordinat yang sama\n");
    } else if(NEQ(P1,P1)) {
        printf("P1 dan P1 memiliki koordinat yang berbeda\n");
    }
    if(EQ(P1,P2)) {
        printf("P1 dan P2 memiliki koordinat yang sama\n");
    } else if(NEQ(P1,P2)) {
        printf("P1 dan P2 memiliki koordinat yang berbeda\n");
    }

    printf("\n");
    printf("TEST letak titik\n");
    P3 = MakePOINT(0.0,0.0); P4 = MakePOINT(3.0,0.0); P5 = MakePOINT(0.0,5.0);
    if(IsOrigin(P3)) {
        TulisPOINT(P3);
        printf(" adalah titik origin\n");
    }
    if(IsOnSbX(P4)) {
        TulisPOINT(P4);
        printf(" terletak pada sumbu X\n");
    }
    if(IsOnSbY(P5)) {
        TulisPOINT(P5);
        printf(" terletak pada sumbu Y\n");
    }
    printf("P1 berada pada kuadran %d\n", Kuadran(P1));

    printf("\n");
    printf("TEST operasi lain\n");
    printf("P1 bila digeser ke kanan satu satuan menghasilkan koordinat "); TulisPOINT(NextX(P1)); printf("\n");
    printf("P1 bila digeser ke atas satu satuan menghasilkan koordinat "); TulisPOINT(NextY(P1)); printf("\n");
    printf("P1 bila digeser ke kanan 2 dan ke atas 3 menghasilkan koordinat "); TulisPOINT(PlusDelta(P1,2,3)); printf("\n");
    printf("P1 bila dicerminkan terhadap sumbu X menghasilkan koordinat "); TulisPOINT(MirrorOf(P1,true)); printf("\n");
    printf("P1 bila dicerminkan terhadap sumbu Y menghasilkan koordinat "); TulisPOINT(MirrorOf(P1,false)); printf("\n");
    printf("Jarak P1 dan titik origin adalah %.2f", Jarak0(P1)); printf("\n");
    printf("Jarak P1 dan P2 adalah %.2f", Panjang(P1,P2)); printf("\n");
    Geser(&P1,2,3);
    printf("Setelah digeser ke kanan 2 dan ke atas 3, P1 berkoordinat "); TulisPOINT(P1); printf("\n");
    GeserKeSbX(&P1);
    printf("Setelah digeser ke sumbu X, P1 berkoordinat "); TulisPOINT(P1); printf("\n");
    GeserKeSbY(&P1);
    printf("Setelah digesr ke sumbu Y, P1 berkoordinat "); TulisPOINT(P1); printf("\n");
    Mirror(&P2, true);
    printf("Setelah dicerminkan terhadap sumbu X, P2 berkoordinat "); TulisPOINT(P2); printf("\n");
    Mirror(&P2,false);
    printf("Setelah dicerminkan terhadap sumbu Y, P2 berkoordinat "); TulisPOINT(P2); printf("\n");
    Putar(&P2,90.0);
    printf("Setelah diputar 90 derajat searah jarum jam, P2 berkoordinat "); TulisPOINT(P2); printf("\n");
}