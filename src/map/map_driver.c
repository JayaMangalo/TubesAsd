/* Filename: map_driver.c (driver of map.h) */

#include "map.h"
#include "matrix.h"
#include "listdin.h"
#include "point.h"
#include <stdio.h>

int main() {
  /* KAMUS */
  Map m;
  Matrix mat;
  ListDin l;
  POINT p;
  /* ALGORITMA */
  CreateMap(&m, 6, 6);
  readMatrix(&mat, 6, 6);
  setMatrix(&m, mat);
  printf("Matriks adjacency yang terbentuk:\n");
  displayMatrix(getMatrix(m));
  printf("\n");
  /* membuat list lokasi */
  CreateListDin(&l,26);
  p = MakePOINT(1,1); // lokasi headquarters
  insertBangunan(&l, '8', p); 
  p = MakePOINT(10,1);
  insertBangunan(&l, 'A', p);
  p = MakePOINT(1,15);
  insertBangunan(&l, 'B', p);
  p = MakePOINT(1,9);
  insertBangunan(&l, 'C', p);
  p = MakePOINT(1,13);
  insertBangunan(&l, 'D', p);
  p = MakePOINT(2,3);
  insertBangunan(&l, 'E', p);
  setLokasi(&m, l);
  printf("Lokasi bangunan yang tersedia:\n");
  displayList(getLokasi(m));
  printf("Posisi yang dapat dicapai dari D\n");
  //accessiblePosition(m, 'D');
}