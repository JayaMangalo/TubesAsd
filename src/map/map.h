#ifndef Map_H
#define Map_H

#include "../boolean/boolean.h"
#include "../matrix/matrix.h" // sebagai representasi peta dan merepresentasikan hubungan jalan antar bangunan
#include "../point/point.h" // untuk menunjukkan posisi bangunan
#include "../listdin/listdin.h" // untuk menyimpan daftar bangunan yang tersedia pada peta

/* Kamus Umum */
#define CAPLIST 26  // kapasitas maksimum list dinamis, merupakan jumlah maksimal lokasi

typedef struct {
  Matrix mat; // matriks adjacency
  ListDin lokasi; // list berisi karakter dan koordinat dari lokasi
} Map;

/* ********** SELEKTOR ********** */
#define MAT(m) (m).mat;
#define LOC(m) (m).lokasi;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create map kosong  */
void CreateMap(Map *m, int nRow, int nCol);
/* I.S. m sembarang, nRow dan nCol adalah valid */
/* F.S. Terbentuk map m dengan kapasitas list dinamis CAPACITY dan jumlah
   baris dan kolom matriks yaitu nRow dan nCol */

/* ********** SELEKTOR ********** */
void setMatrix(Map *m, Matrix mat);
/* I.S. Matrix mat merupakan matrix adjacency yang valid */
/* F.S. mat merupakan elemen mat dari Map */

void setLokasi(Map *m, ListDin l);
/* I.S. Listdin l merupakan list dinamis berisi karakter dan koordinat lokasi yang valid */
/* F.S. l merupakan elemen lokasi dari Map */

Matrix getMatrix(Map m);
/* Mengembalikan matrix adjacency suatu Map m */

ListDin getLokasi(Map m);
/* Mengembalikan list dinamis lokasi dari Map */

void displayPosisi(Map m, int idx);
/* I.S. m tidak kosong */
/* F.S. Jika elemen list dari m tidak kosong : menampilkan karakter lokasi dan koordinat lokasi
        Jika elemen list dari m kosong : menampilkan pesan kesalahan */

void accessiblePosition(Map m, char name);
/* I.S. m tidak kosong */
/* F.S. Jika m tidak kosong : menampilkan posisi yang dapat dicapai dari suatu lokasi dengan nama 
        name sesuai dengan format pada command MOVE
        Jika m kosong : menampilkan pesan kesalahan */


/* FUNGSI TAMBAHAN UNTUK DISPLAY MAP */
char findBangunan(ListDin l, POINT p) 
/* Mencari bangunan dengan posisi p */
/* Mengembalikan nama bangunan jika ditemukan dan '-' jika tidak */
{
  /* Kamus Lokal */
  boolean found;
  int i;
  /* Algoritma */
  found = false;
  i = 0;
  while (i<length(l) && !found) {
    if (EQ(ELMTl(l,i).posisi,p)) {
      found = true;
    } else {
      i++;
    }
  }
  if (found) {
    return ELMTl(l,i).name;
  } else {
    return '-';
  }
}

boolean isAccessible(Map m, char loc_mobita, char bangunan)
/* Mengembalikan true jika mobita bisa menuju bangunan */
{
  /* KAMUS LOKAL */
  int idx_mobita, idx_bangunan;
  /* ALGORITMA */
  idx_mobita = indexOf(m.lokasi, loc_mobita);
  idx_bangunan = indexOf(m.lokasi, bangunan);
  return (ELMT(m.mat, idx_mobita, idx_bangunan) == 1);
}

boolean findOrder(Map m, List toDo, POINT p)
/* Mengembalikan true jika terdapat order dengan lokasi pick up yaitu p */
{
  /* KAMUS LOKAL */
  int idx_order;
  boolean found;
  Address loc;
  /* ALGORITMA */
  loc = FIRST(toDo);
  found = false;
  while (loc != NULL && !found) {
    idx_order = indexOf(m.lokasi, PickUp(INFO(loc)));
    if (EQ(ELMTl(m.lokasi,idx_order).posisi, p)) {
      found = true;
    } else {
      loc = NEXT(loc);
    }
  }
  return found;
}

void displayMap(Map m, char loc_mobita, Stack tas, List toDo, int nrow, int ncol)
{
  /* KAMUS */
  int row,col;
  POINT p;
  char bangunan;
  ListDin l;
  /* ALGORITMA */
  for (row=0; row < nrow+2; row++) {
    for (col=0; col < ncol+2; col++) {
      if (row == 0 || row == nrow+1 || col == 0 || col == ncol+1){
        printf("*");
        if (col == ncol+1) {
          printf("\n");
        }
      } else {
        l = LOC(m);
        p = MakePOINT(row,col);
        bangunan = findBangunan(l,p);
        if (bangunan != '-') {
          if (EQ(ELMTl(l, indexOf(l,loc_mobita)).posisi, p)) {  // lokasi mobita
            print_yellow(bangunan);
          } else if (EQ(ELMTl(l,indexOf(l,DropOff(TOP(tas)))).posisi, p)) { // lokasi drop off pesanan
            print_blue(bangunan);
          } else if (findOrder(m,toDo,p)) { // lokasi pick up pesanan
            print_red(bangunan);
          } else if (isAccessible(m,loc_mobita,bangunan)) { // lokasi yang dapat dicapai
            print_green(bangunan);
          } else {
            printf("%c", bangunan);
          }
        } else {
          printf(" ");
        }
      }
    }
  }
}

#endif