/* File: listdin.c */
/* *** Body ABSTRACT DATA TYPE CHARACTER DYNAMIC LIST *** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    /* Kamus Lokal */
    /* Algoritma */
    BUFFER(*l) = (ElTypel*) malloc((capacity)*sizeof(int));
    CAPACITY(*l) = capacity;
    (*l).nEff = 0;
}

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    /* Kamus Lokal */
    /* Algoritma */
    free(l);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    /* Kamus Lokal */
    /* Algoritma */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    /* Kamus Lokal */
    /* Algoritma */
    return CAPACITY(l) - 1;
}

/* *** Selektor Bangunan *** */
char getNamaBangunan(ListDin l, int idx)
/* Mengembalikan nama bangunan dari suatu bangunan dengan nomor bangunan idx */
/* Nomor bangunan merupakan indeks dari matriks adjacency */
{
    /* Kamus Lokal */
    /* Algoritma */
    return ELMTl(l, idx).name;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidl(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    /* Kamus Lokal */

    /* Algoritma */
    return (i>=0 && i<CAPACITY(l));
}
boolean isIdxEffl(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    /* Kamus Lokal */

    /* Algoritma */
    return (i>=0 && i<length(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return (length(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    /* Kamus Lokal */

    /* Algoritma */
    return (NEFF(l) == CAPACITY(l));
}

void displayList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, isi list berupa nama dan
   posisi ditulis satu per satu */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong:  */
/* Contoh : jika ada dua elemen berupa A 10 1 dan B 1 15 maka ditulis
   A (10,1)
   B (1,15) */
/* Jika list kosong : menulis kosong */
{
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (isEmpty(l)) {
        printf("kosong\n");
    }
    else {
        printf("Headquarters ");
        TulisPOINT(ELMTl(l,0).posisi);
        printf("\n");
        for (i=1; i<length(l); i++) {
            printf("%c ", ELMTl(l,i).name);
            TulisPOINT(ELMTl(l,i).posisi);
            printf("\n");
        }
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, char name)
/* Search apakah ada elemen List l yang memiliki komponen name berupa name */
/* Jika ada, menghasilkan indeks i terkecil, dengan komponen name pada 
   elemen ke-i = name */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Indeks yang dihasilkan juga merupakan indeks dari matrix adjacency */
/* Skema Searching yang digunakan bebas */
{
    /* Kamus Lokal */
    bool found;
    int i;
    /* Algoritma */
    found = false;
    i = 0;
    while (i<length(l) && !(found)) {
        if (ELMTl(l,i).name == name) {
            found = true;
        } else {
            i = i + 1;
        }
    }
    if (found) {
        return i;
    } else {
        return IDX_UNDEF;
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    CreateListDin(lOut, lIn.capacity);
    for (i=0; i<length(lIn); i++) {
        ELMTl(*lOut,i) = ELMTl(lIn,i);
    }
    NEFF(*lOut) = NEFF(lIn);
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertBangunan(ListDin *l, char name, POINT posisi)
/* Proses: Menambahkan name dan posisi sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. name dan posisi adalah elemen terakhir l yang baru */
{
    /* Kamus Lokal */

    /* Algoritma */
    ELMTl(*l, length(*l)).name = name;
    ELMTl(*l, length(*l)).posisi = posisi;
    NEFF(*l) = NEFF(*l) + 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteBangunan(ListDin *l, ElTypel *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    /* Kamus Lokal */

    /* Algoritma */
    *val = ELMTl((*l), getLastIdx(*l));
    NEFF(*l) = NEFF(*l) - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    /* Kamus Lokal */

    /* Algoritma */
    (*l).capacity = (*l).capacity + num;
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    /* Kamus Lokal */

    /* Algoritma */
    /* if ((*l).capacity == (*l).nEff) {
        (*l).nEff = (*l).nEff - num;
    (*l).capacity = (*l).capacity - num; */

    while (num>0) {
        if ((*l).capacity == (*l).nEff) {
            (*l).nEff = (*l).nEff - 1;
        }
        (*l).capacity = (*l).capacity - 1;
        num = num - 1;
    }
}

void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    /* Kamus Lokal */

    /* Algoritma */
    (*l).capacity = (*l).nEff;
}
