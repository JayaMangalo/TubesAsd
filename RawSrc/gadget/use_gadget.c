#include "stack.h"
#include "order.h"

void useKainPembungkusWaktu(Stack *tas) {
  /* KAMUS LOKAL */
  Order ord;
  /* ALGORITMA */
  ord = TOP(*tas);
  if (TYPE(ord) == 'P') {
    TimePerish(ord) = TimePerishDefault(ord);
  }
}

void useSenterPembesar(Stack *tas) {
  CurrentCap(*tas) = (2 * CurrentCap(*tas)) % CAPACITY;
}

//bingung ngeaddress posisi sekarang, jadi sementara pake current point
void usePintuKemanaSaja(POINT currentP, POINT nextP){
    /* KAMUS LOKAL */
  /* ALGORITMA */
  currentP = nextP;
}

void useMesinWaktu(Time *T) {
  /* KAMUS LOKAL */
  /* ALGORITMA */
  if (currentTime(*T) >= 50) {
    currentTime(*T) -= 50;
  }
  else {
    currentTime(*T) = 0;
  }
}