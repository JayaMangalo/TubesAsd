#include <stdio.h>
#include "gadget.h"

void useKainPembungkusWaktu(Order *ord) {
  /* KAMUS LOKAL */
  /* ALGORITMA */
  TimePerish(*ord) = TimePerishDefault(*ord);
}

void useSenterPembesar(Stack *tas) {
  CurrentCap(*tas) = (2 * CurrentCap(*tas));
  if (CurrentCap(*tas) > 100) {
    CurrentCap(*tas) = 100;
  }
}

void usePintuKemanaSaja(char *currentP, char nextP){
    /* KAMUS LOKAL */
  /* ALGORITMA */
  *currentP = nextP;
}

void useMesinWaktu(Time *T, List *ip, Stack *s) {
  /* KAMUS LOKAL */
  int minusT;
  Address p;
  Stack sInv;
  Order temp;
  /* ALGORITMA */
  if (CurrentTime(*T) >= 50) {
    CurrentTime(*T) -= 50;
    minusT = 50; 
  }
  else {
    minusT = CurrentTime(*T);
    CurrentTime(*T) = 0;
  }

  p = FIRST(*ip);
  while(p!=NULL) {
    if(TYPE(INFO(p))=='P') {
      TimePerish(INFO(p)) += minusT;
      if(TimePerish(INFO(p))>TimePerishDefault(INFO(p))) {
        TimePerish(INFO(p)) = TimePerishDefault(INFO(p));
      }
    }
    p = NEXT(p);
  }

  CreateStack(&sInv);
  while(!isStackEmpty(*s)) {
    popStack(s, &temp);
    if(TYPE(temp)=='P') {
      TimePerish(temp) += minusT;
      if(TimePerish(temp)>TimePerishDefault(temp)) {
        TimePerish(temp) = TimePerishDefault(temp);
      }
    }
    pushStack(&sInv, temp);
  }
  while(!isStackEmpty(sInv)) {
    popStack(&sInv, &temp);
    pushStack(s,temp);
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