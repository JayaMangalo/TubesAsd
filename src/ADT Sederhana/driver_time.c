/* File: driver_time.c */
/* Tanggal: 2 September 2021 */
/* Driver ADT TIME */

#include<stdio.h>
#include "time.h"

int main() {
    /* KAMUS */
    TIME T1, T2;
    /* ALGORITMA */
    printf("TEST Konstruktor\n");
    T1 = MakeTIME(19,0,0);
    printf("Waktu pukul 19.00 disimpan dalam T1\n");
    printf("Hasil tulis T1 adalah "); TulisTIME(T1); printf("\n");

    printf("\n");
    printf("TEST BACA/TULIS\n");
    printf("Masukkan jam, menit, detik untuk T2:\n");
    BacaTIME(&T2);
    printf("Hasil tulis T2 adalah "); TulisTIME(T2); printf("\n");

    printf("\n");
    printf("TEST konversi\n");
    printf("Konversi T1 dalam detik adalah %ld\n", TIMEToDetik(T1));
    printf("Konversi 68400 detik dalam jam adalah "); TulisTIME(DetikToTIME(68400)); printf("\n");

    printf("\n");
    printf("TEST operasi terhadap type\n");
    printf("Kelompok operator relational\n");
    if(TEQ(T1,T1)) printf("T1 = T1\n");
    if(TNEQ(T1,T2)) printf("T1 != T2\n");
    if(TLT(T1,T2)) {
        printf("T1 lebih awal dari T2\n");
    } else {
        printf("T1 tidak lebih awal dari T2\n");
    }
    if(TGT(T1,T2)) {
        printf("T1 lebih akhir dari T2\n");
    } else {
        printf("T1 tidak lebih akhir dari T2\n");
    }
    
    printf("\n");
    printf("Kelompok operator aritmatika\n");
    printf("1 detik setelah T1 adalah "); TulisTIME(NextDetik(T1)); printf("\n");
    printf("301 detik setelah T1 adalah "); TulisTIME(NextNDetik(T1,301)); printf("\n");
    printf("1 detik sebelum T1 adalah "); TulisTIME(PrevDetik(T1)); printf("\n");
    printf("301 detik sebelum T1 adalah "); TulisTIME(PrevNDetik(T1,301)); printf("\n");

    printf("\n");
    printf("Kelompok operator aritmetika\n");
    printf("Total durasi dari T1 sampai T2 adalah %ld\n", Durasi(T1,T2));
}
