#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include "../setup/setup.h"

extern int Row;
extern int Column;
extern POINT HQ;
extern ListDin List_bangunan; 
extern Matrix m;
extern Daftar DaftarOrder;
extern List toDo;
extern List Inprogress;
extern Stack Tas;
extern Map map;
extern char locMobita;

extern int money;

extern Command Y;
extern Command N;

void CommandMove();
void CommandPickUp();
void CommandDropOff();
void CommandMap();
void CommandToDo();
void CommandInProgress();
void CommandBuy();
void CommandInventory();
void CommandHelp();
boolean CommandExit();


#endif