/* File: listdin.c */
/* *** Body ABSTRACT DATA TYPE CHARACTER DYNAMIC LIST *** */

#include "map.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create map kosong  */
void CreateMap(Map *m, int nRow, int nCol)
/* I.S. m sembarang, nRow dan nCol adalah valid */
/* F.S. Terbentuk map m dengan kapasitas list dinamis CAPACITY dan jumlah
   baris dan kolom matriks yaitu nRow dan nCol */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  CreateListDin(&((*m).lokasi), CAPLIST);
  CreateMatrix(nRow, nCol, &((*m).mat));
}

/* ********** SELEKTOR ********** */
void setMatrix(Map *m, Matrix mat)
/* I.S. Matrix mat merupakan matrix adjacency yang valid */
/* F.S. mat merupakan elemen mat dari Map */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  (*m).mat = mat;
}

void setLokasi(Map *m, ListDin l)
/* I.S. Listdin l merupakan list dinamis berisi karakter dan koordinat lokasi yang valid */
/* F.S. l merupakan elemen lokasi dari Map */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  (*m).lokasi = l;
}

Matrix getMatrix(Map m)
/* Mengembalikan matrix adjacency suatu Map m */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return MAT(m);
}

ListDin getLokasi(Map m)
/* Mengembalikan list dinamis lokasi dari Map */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return LOC(m);
}

void displayPosisi(Map m, int idx)
/* I.S. m tidak kosong */
/* F.S. Jika elemen list dari m tidak kosong : menampilkan karakter lokasi dan koordinat lokasi
        Jika elemen list dari m kosong : menampilkan pesan kesalahan */
{
  /* KAMUS LOKAL */
  ListDin l;
  /* ALGORITMA */
  l = LOC(m);
  if (idx != IDX_UNDEF) {
    if (idx == 0) {
      printf("Headquarters ");
    } else {
      printf("%c ", ELMTl(l,idx).name);
    }
    TulisPOINT(ELMTl(l,idx).posisi);
  } else {
    printf("Lokasi pada indeks %d tidak ada\n", idx);
  }
}

void accessiblePosition(Map m, char name, int arr[1000])
/* I.S. m tidak kosong */
/* F.S. Jika m tidak kosong : menampilkan posisi yang dapat dicapai dari suatu lokasi dengan nama 
        name sesuai dengan format pada command MOVE
        Jika m kosong : menampilkan pesan kesalahan */
{
  /* KAMUS LOKAL */
  int idx, i, ctr;
  Matrix mat;
  /* ALGORITMA */
  idx = indexOf(m.lokasi, name);
  mat = MAT(m);
  ctr = 1;
  for (i=0; i < COLS(mat); i++) {
    if (ELMT(mat,idx,i) == 1) {
      printf("%d. ", ctr);
      displayPosisi(m, i);
      arr[ctr] = i;
      printf("\n");
      ctr++;
    }
  }
}

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
