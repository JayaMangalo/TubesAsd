#ifndef STATEPLAYER_H
#define STATEPLAYER_H

#include "../ADT List/listpos.h"
#include "../ADT Map/map.h"
#include "../ADT Stack/stack.h"
#include "prototypeTime.c"
#include "boolean.h"

typedef struct {
    ListDin order;   //Menyimpan todo list
    int money;      //menyimpan jumlah uang
    Stack tas;      //tas
    Map map;        //map
    POINT posisi;   //posisi sekarang
    Time t;         //waktu sekarang
} statePlayer;

/* Selektor */
#define ORDER(player) (player).order
#define CASH(player) (player).money
#define TAS(player) (player).tas
#define MAP(player) (player).map
#define POSITION(player) (player).posisi
#define TIME(player) (player).t

ListDin getAccessible(statePlayer state);
/* mengembalikan list yang berisi titik titik yang dapat diakses */
/* dari lokasi sekarang */

boolean isAccessible(statePlayer state, POINT p2);
/* mengembalikan true jika p2 dapat diakses dari p1, false jika sebaliknya */

boolean isItemReadyPickUp(statePlayer state);
/* mengembalikan true jika terdapat item yang bisa dipickup */
/* di posisi state sekarang, false jika sebaliknya */

boolean isItemReadyDrop(statePlayer state);
/* mengembalikan true jika item pada tas siap di drop off pada titik p*/
/* false jika sebaliknya */

void MOVE(statePlayer *state, POINT p);
/* I.S sembarang */
/* F.S berpindah lokasi dari yang ada pada state, ke point p */
/* Waktu bertambah satu */

void PICK_UP(statePlayer *state);
/* I.S Sembarang */
/* barang yang ada di p dipickup oleh mobita */

void DROP_OFF(statePlayer *state);
/* I.S Sembarang */
/* F.S barang drop off pada posisi p*/

void displayMAP(statePlayer state);
/* I.S m terdefinisi */
/* F.S m ditampilkan ke layar */

void displayTO_DO(statePlayer state);
/* I.S sembarang */
/* F.S todo list ditampilkan ke layar */

#endif