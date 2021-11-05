/* NIM: 13520009 */
/* Nama: Ahmad Romy Zahran */
/* Tanggal : 7 Oktober 2021 */
/* Topik Praktikum : ADT Stack */
/* File : stack.c */
/* implementasi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
    /* Kamus Lokal */
    /* Algoritma */
    IDX_TOP(*s) = IDX_UNDEF;
};

/* ************ Prototype ************ */
boolean isEmpty(Stack s) {
/* Mengirim true jika s kosong: lihat definisi di atas */
    /* Kamus Lokal */
    /* Algoritma */
    return IDX_TOP(s)==IDX_UNDEF;
};
boolean isFull(Stack s) {
/* Mengirim true jika tabel penampung nilai s stack penuh */
    /* Kamus Lokal */
    /* Algoritma */
    return IDX_TOP(s)==CAPACITY-1;
};

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, ElType val) {
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
    /* Kamus Lokal */
    /* Algoritma */
    if(isEmpty(*s)) {
        IDX_TOP(*s)=0;
        TOP(*s) = val;
    } else {
        IDX_TOP(*s)++;
        TOP(*s) = val;
    }
};

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, ElType *val) {
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
    /* Kamus Lokal */
    /* Algoritma */
    *val = TOP(*s);
    if(IDX_TOP(*s)==0) {
        IDX_TOP(*s) = IDX_UNDEF;
    } else {
        IDX_TOP(*s)--;
    }
};
