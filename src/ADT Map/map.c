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

void accessiblePosition(Map m, char name)
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
      printf("\n");
      ctr++;
    }
  }
}