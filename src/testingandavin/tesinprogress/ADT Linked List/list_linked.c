/* NIM: 13520009 */
/* Nama: Ahmad Romy Zahran */
/* Tanggal : 25 Oktober 2021 */
/* Topik Praktikum : ADT Linked List */
/* File : list_linked.c */
/* IMplementasi ADT list berkait dengan representasi fisik pointer */

#include "list_linked.h"
#include<stdlib.h>
#include<stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    /* Kamus Lokal */
    /* Algoritma */
    FIRST(*l) = NULL;
};

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong */
    /* Kamus Lokal */
    /* Algoritma */
    return FIRST(l) == NULL;
};

/****************** GETTER SETTER ******************/
node_El getElmt(List l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* Kamus Lokal */
    Address p;
    int i;
    /* Algoritma */
    p = FIRST(l);
    i=0;
    while(i<idx) {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}; 

void setElmt(List *l, int idx, node_El val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* Kamus Lokal */
    Address p;
    int i;
    /* Algoritma */
    p = FIRST(*l);
    i = 0;
    while(i<idx) {
        p = NEXT(p);
        i++;
    }
    INFO(p)=val;
};

// int indexOf(List l, node_El val) {
// /* I.S. l, val terdefinisi */
// /* F.S. Mencari apakah ada elemen list l yang bernilai val */
// /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
// /* Mengembalikan IDX_UNDEF jika tidak ditemukan */
//     /* Kamus Lokal */
//     int idx,i;
//     Address p;
//     /* Algoritma */
//     idx = IDX_UNDEF;
//     i = 0;
//     p = FIRST(l);
//     while(p!=NULL && idx==IDX_UNDEF) {
//         if(INFO(p)==val) {
//             idx = i;
//         } else {
//             p = NEXT(p);
//             i++;
//         }
//     }
//     return idx;
// };

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, node_El val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /* Kamus Lokal */
    Address p;
    /* Algoritma */
    p = newNode(val);
    if(p!=NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
};

void insertLast(List *l, node_El val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* Kamus Lokal */
    Address p, pLast;
    /* Algoritma */
    if(isEmpty(*l)) {
        insertFirst(l,val);
    } else {
        pLast = newNode(val);
        if(pLast!=NULL) {
            p = FIRST(*l);
            while(NEXT(p)!=NULL) {
                p = NEXT(p);
            }
            NEXT(p) = pLast;
        }
    }
};

void insertAt(List *l, node_El val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* Kamus Lokal */
    Address pi, p;
    int i;
    /* Algoritma */
    pi = newNode(val);
    if(pi!=NULL) {
        p = FIRST(*l);
        if(idx==0) {
            NEXT(pi) = FIRST(*l);
            FIRST(*l) = pi;
        } else {
            i = 0;
            while(i!=idx-1) {
                p = NEXT(p);
                i++;
            }
            NEXT(pi) = NEXT(p);
            NEXT(p) = pi;
        }
    }
};

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, node_El *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    /* Kamus Lokal */
    Address p;
    /* Algoritma */
    *val = INFO(FIRST(*l));
    p = FIRST(*l);
    FIRST(*l) = NEXT(p);
    free(p);
};
void deleteLast(List *l, node_El *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    /* Kamus Lokal */
    Address p,loc;
    /* Algoritma */
    p = FIRST(*l);
    loc = NULL;
    while(NEXT(p)!=NULL) {
        loc = p;
        p = NEXT(p);
    }
    if(loc==NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
};

void deleteAt(List *l, int idx, node_El *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /* Kamus Lokal */
    Address p,loc;
    int i;
    /* Algoritma */
    if(idx==0) {
        deleteFirst(l,val);
    } else {
        i=1;
        loc = FIRST(*l);
        p = NEXT(loc);
        while(i!=idx) {
            loc = p;
            p = NEXT(p);
            i++;
        }
        NEXT(loc) = NEXT(p);
        *val = INFO(p);
        free(p);
    }
};


/****************** PROSES SEMUA ELEMEN LIST ******************/
// void displayList(List l) {
// // void printInfo(List l);
// /* I.S. List mungkin kosong */
// /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
//     /* Kamus Lokal */
//     Address p;
//     /* Algoritma */
//     printf("[");
//     if(!isEmpty(l)) {
//         printf("%d",INFO(FIRST(l)));
//         p = NEXT(FIRST(l));
//         while(p!=NULL) {
//             printf(",%d", INFO(p));
//             p = NEXT(p);
//         }
//     }
//     printf("]");
// };

int length(List l) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* Kamus Lokal */
    int ct;
    Address p;
    /* Algoritma */
    ct = 0;
    p = FIRST(l);
    while(p!=NULL) {
        ct++;
        p = NEXT(p);
    }
    return ct;
};

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)  {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    /* Kamus Lokal */
    List l3;
    Address p;
    /* Algoritma */
    CreateList(&l3);
    /*
    FIRST(l3)=FIRST(l1);
    p = FIRST(l3);
    while(NEXT(p)!=NULL) {
        p = NEXT(p);
    }
    NEXT(p) = FIRST(l2);
    */
    p = FIRST(l1);
    while(p!=NULL) {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while(p!=NULL) {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    return l3;
};