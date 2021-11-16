#include <stdio.h>
#include "../setup/setup.h"
#include "../time/time.h"

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
void usePintuKemanaSaja(char currentP, char nextP){
    /* KAMUS LOKAL */
  /* ALGORITMA */
  currentP = nextP;
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


void useSenterPengecil(Stack *tas) {
  /* KAMUS LOKAL */
  Order ord = TOP(*tas);
  /* ALGORITMA */
  if (TYPE(ord) == 'H') {
    TYPE(ord) = 'N';
  }
  else {
    printf("Barang di tumpukan teratas tas bukan heavy item\n");
  }
}