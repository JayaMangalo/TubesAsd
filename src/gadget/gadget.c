#include <stdio.h>
#include "gadget.h"

void useKainPembungkusWaktu(Order *ord) {
  /* KAMUS LOKAL */
  /* ALGORITMA */
  TimePerish(*ord) = TimePerishDefault(*ord);
}

void useSenterPembesar(Stack *tas) {
  CurrentCap(*tas) = (2 * CurrentCap(*tas)) % CAPACITY;
}

void usePintuKemanaSaja(char *currentP, char nextP){
    /* KAMUS LOKAL */
  /* ALGORITMA */
  *currentP = nextP;
}

void useMesinWaktu(Time *T) {
  /* KAMUS LOKAL */
  /* ALGORITMA */
  if (CurrentTime(*T) >= 50) {
    CurrentTime(*T) -= 50;
  }
  else {
    CurrentTime(*T) = 0;
  }
}


void useSenterPengecil(Order *ord, List *inprog) {
  /* KAMUS LOKAL */
  Address p = *inprog;
  while (!isOrderEqual(*ord,INFO(p))) {
    p = NEXT(p);
  }
  TYPE(*ord) = 'N';
  TYPE(INFO(p)) = 'N';
}