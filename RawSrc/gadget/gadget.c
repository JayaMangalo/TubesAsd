#include "stack.h"

void useKainPembungkusWaktu(Stack *tas) {
  
}

void useSenterPembesar(Stack *tas) {
  CurrentCap(*tas) = (2 * CurrentCap(*tas)) % CAPACITY;
}