#ifndef setup_H
#define setup_H

#include <stdio.h>
#include "../matrix/matrix.h"
#include "../point/point.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"
#include "../listdin/listdin.h"
#include "../order/order.h"
#include "../queue/prioqueue.h"
#include "../command/commandcharmachine.h"
#include "../command/commandwordmachine.h"

extern Command NEW_GAME;
extern Command LOAD_GAME;
extern Command EXIT;
extern Command MOVE;
extern Command PICK_UP;
extern Command DROP_OFF;
extern Command TO_DO;
extern Command MAP;
extern Command IN_PROGRESS;
extern Command BUY;
extern Command INVENTORY;
extern Command HELP;

void setupCommand();
void setupGame(int *Row,int *Column, POINT *HQ, ListDin *List_bangunan, Matrix *m, Daftar *DaftarOrder);

#endif