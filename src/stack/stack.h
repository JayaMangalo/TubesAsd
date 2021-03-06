/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "../boolean/boolean.h"
#include "../order/order.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct {
  Order buffer[CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
  int CurrentCapacity;     // Capacity bag yang dapat berubah 
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]
#define     CurrentCap(s) (s).CurrentCapacity

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isStackEmpty(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isStackFull(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack *s, Order val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popStack(Stack *s, Order *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

void IncreaseCapacity(Stack *s);
//Meningkatkan Capacity dengan 1 asalkan blom 100

/* ************ Update Perish ************** */
void updPerishStack(Stack *s, int deltaT);
// mengurangi tPerish setiap order bertipe perishable dengan deltaT.
// bila tPerish<=0, order dibuang dari Tas

#endif