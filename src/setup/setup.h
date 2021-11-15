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
#include "../node/node.h"
#include "../linked list/list_linked.h"
#include "../commandmachine/commandcharmachine.h"
#include "../commandmachine/commandwordmachine.h"
#include "../commandmachine/command.h"

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
extern Command EXIT;
extern Command Y;
extern Command N;

extern int Row;
extern int Column;
extern POINT HQ;
extern ListDin List_bangunan; 
extern Matrix m;
extern Daftar DaftarOrder;
extern List toDo;

void setupCommand();
void setupGame();

#endif