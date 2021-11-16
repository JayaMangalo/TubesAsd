#include "map\map.h"
#include "pcolor\pcolor.h"
#include "stack\stack.h"
#include "linkedlist\list_linked.h"
#include "map\point.h"
#include "map\listdin.h"
#include "map\matrix.h"
#include "node\node.h"
#include "order\order.h"
#include <stdio.h>

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