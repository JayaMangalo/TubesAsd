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