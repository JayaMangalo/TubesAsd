/* NIM: 13520009 */
/* Nama: Ahmad Romy Zahran */
/* Tanggal : 7 Oktober 2021 */
/* Topik Praktikum : ADT Queue */
/* File : prioqueue.c */
/* implementasi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi statik */
/* Queue terurut mengecil berdasarkan elemen score (nilai Daspro) */
/* Jika score sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */

#include "prioqueue.h"

/* *** Kreator *** */
void CreatePrioQueue(Daftar *d) {
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
    /* Kamus Lokal */
    /* Algoritma */
    IDX_HEAD(*d) = IDX_UNDEF;
    IDX_TAIL(*d) = IDX_UNDEF;
};

boolean isQEmpty(Daftar pq) {
/* Mengirim true jika pq kosong: lihat definisi di atas */
    /* Kamus Lokal */
    /* Algoritma */
    return IDX_HEAD(pq)==IDX_UNDEF && IDX_TAIL(pq)==IDX_UNDEF;
};

boolean isQFull(Daftar pq) {
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    /* Kamus Lokal */
    /* Algoritma */
    return IDX_HEAD(pq)==0 && IDX_TAIL(pq)==CAPACITY-1;
};

int Qlength(Daftar pq) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */
    /* Kamus Lokal */
    /* Algoritma */
    if(isQEmpty(pq)) {
        return 0;
    } else {
        return IDX_TAIL(pq)-IDX_HEAD(pq)+1;
    }
};

/*** Primitif Add/Delete ***/
void enqueue(Daftar *pq, Order val) {
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if(IDX_TAIL(*pq)==CAPACITY-1) {
        for(i=IDX_HEAD(*pq);i<=IDX_TAIL(*pq);i++) {
            (*pq).buffer[i-IDX_HEAD(*pq)] = (*pq).buffer[i];
        }
        IDX_TAIL(*pq) -= IDX_HEAD(*pq);
        IDX_HEAD(*pq) = 0;
    }
    if(isQEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    } else {
        i = IDX_TAIL(*pq);
        while(i>=IDX_HEAD(*pq) && ((*pq).buffer[i].tArrival > val.tArrival || ((*pq).buffer[i].tArrival == val.tArrival && (*pq).buffer[i].tArrival > val.tArrival))) {
            (*pq).buffer[i+1] = (*pq).buffer[i];
            i = i-1;
        }
        (*pq).buffer[i+1] = val;
        IDX_TAIL(*pq)++;
    }
};

void dequeue(Daftar * pq, Order *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur";
        pq mungkin kosong */
    /* Kamus Lokal */
    /* Algoritma */
    *val = HEAD(*pq);
    if(Qlength(*pq)==1) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq) +=1;
    }
};

void displayDaftar(Daftar q)
{
    if(!isQEmpty(q)) {
        Order val;
        int i = 1;
        while(!isQEmpty(q))
        {
            dequeue(&q,&val);
            if(TYPE(val)=='N') {
                printf("%d. %c -> %c (Normal Item)\n", i, PickUp(val), DropOff(val));
                i++;
            } else if(TYPE(val)=='H') {
                printf("%d. %c -> %c (Heavy Item)\n", i, PickUp(val), DropOff(val));
                i++;
            } else if(TYPE(val)=='P') {
                printf("%d. %c -> %c (Perishable Item, sisa waktu %d)\n", i, PickUp(val), DropOff(val), TimePerish(val));
                i++;
            }
        }
    }
};
