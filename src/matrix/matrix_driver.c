/* Filename: matrix_driver.c (driver of matrix.h) */

#include "matrix.h"
#include <stdio.h>

int main() {
  /* KAMUS */
  Matrix m;
  int row, col;
  /* ALGORITMA */
  printf("Masukkan jumlah baris matrix:");
  scanf("%d", &row);
  printf("Masukkan jumlah kolom matrix:");
  scanf("%d", &col);
  printf("Masukkan matrix\n");
  readMatrix(&m, 6, 6);
  displayMatrix(m);
  printf("\nbanyaknya elemen matrix: %d\n", count(m));
  if (isIdxEff(m,2,3)) {
    printf("2,3 adalah index efektif bagi matrix\n");
  } else {
    printf("2,3 bukan merupakan index efektif bagi matrix\n");
  }
  printf("elemen matrix pada index baris 1 kolom 2 adalah %d\n", ELMT(m,1,2));
  return 0;
}