/* Filename: point_driver.c (driver of point.h) */

#include "point.h"
#include <stdio.h>

int main() {
  /* KAMUS */
  POINT p1, p2;
  /* ALGORITMA */
  p1 = MakePOINT(1,3);
  BacaPOINT(&p2);
  TulisPOINT(p1);
  printf("\n");
  TulisPOINT(p2);
  printf("\n");
  if (EQ(p1,p2)) {
    printf("p1 sama dengan p2\n");
  } else {
    printf("p1 tidak sama dengan p2\n");
  }
  return 0;
}