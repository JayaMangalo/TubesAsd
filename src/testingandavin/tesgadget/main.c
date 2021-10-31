#include <stdio.h>
#include <stdlib.h>
#include "ADT List/listpos.h"
#include "boolean.h"

void CreateInventory(Inventory *g) {
   int i;
   for(i=0;i<5;i++) {
      ELMT(*g,i) = "-";
   }
};

int Invlength(Inventory l) {
   int last=-1;
   while(last <4 && ELMT(l,last+1)!="-") {
      last = last+1;
   }
   return last+1;
};

void insertGadget(Inventory *g, char *Gadget)
{
    if(Invlength(*g)<5)
    {
        ELMT(*g, Invlength(*g)) = Gadget;
    } else {
        printf("Inventory penuh\n");
    }
}

void displayInventory(Inventory g)
{
   int i;
  printf("1. %s\n", ELMT(g,0));
  for(i=1;i<5;i++) {
     printf("%d. %s\n", i+1, ELMT(g,i));
  }
}

void removeGadget(Inventory *g, char *Gadget)
{
  for(int i=0;i<5;i++) {
     if (ELMT(*g,i)==Gadget)
     {
         ELMT(*g,i) = "-";
     }
  }
}

int main()
{
    Inventory g;
    CreateInventory(&g);
    displayInventory(g);
    printf("\n");
    insertGadget(&g, "Senter Pembesar");
    insertGadget(&g, "Kain Pembungkus Waktu");
    insertGadget(&g, "Mesin Waktu");
    displayInventory(g);
    printf("\n");
    removeGadget(&g, "Kain Pembungkus Waktu");
    displayInventory(g);
    return 0;
}
