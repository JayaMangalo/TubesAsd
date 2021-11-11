#ifndef Map_H
#define Map_H

#include "boolean.h"
#include "matrix.h" // sebagai representasi peta dan merepresentasikan hubungan jalan antar bangunan
#include "point.h" // untuk menunjukkan posisi bangunan
#include "listdin.h" // untuk menyimpan daftar bangunan yang tersedia pada peta

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

#endif