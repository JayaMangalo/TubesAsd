/* Filename: listdin_driver.c (driver of listdin.h) */

#include "listdin.h"
#include "../point/point.h"
#include <stdio.h>

int main() {
  /* KAMUS */
  ListDin l;
  POINT p;
  ElTypel val;
  /* ALGORITMA */
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
  p = MakePOINT(2,3);
  insertBangunan(&l, 'Z', p);
  displayList(l);
  printf("%d\n", length(l));
  deleteBangunan(&l, &val);
  displayList(l);
  printf("%d\n", length(l));
  printf("C merupakan bangunan dengan indeks %d\n", indexOf(l, 'C'));
  printf("Bangunan dengan indeks 4 merupakan %c\n", getNamaBangunan(l, 4));
  return 0;
}