#ifndef GADGET_H
#define GADGET_H

#include <stdio.h>

#include "../matrix/matrix.h"
#include "../point/point.h"
#include "../stack/stack.h"
#include "../map/map.h"
#include "../time/time.h"

void useKainPembungkusWaktu(Stack *tas);

void useSenterPembesar(Stack *tas);

//bingung ngeaddress posisi sekarang, jadi sementara pake current point
void usePintuKemanaSaja(char currentP, char nextP);

void useMesinWaktu(Time *T);


void useSenterPengecil(Stack *tas);

#endif 