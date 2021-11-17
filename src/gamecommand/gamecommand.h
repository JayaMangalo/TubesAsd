#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include "../setup/setup.h"

extern int Row;
extern int Column;
extern POINT HQ;
extern ListDin List_bangunan; 
extern Matrix m;
extern Daftar DaftarOrder;
extern List todo;
extern List Inprogress;
extern Stack Tas;
extern Map map;
extern char locMobita;
extern Inventory InventoryGadget;
extern Time T;
extern int money;
extern int counter;

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