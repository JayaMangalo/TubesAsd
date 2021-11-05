
#include <stdio.h>
#include "stateplayer.h"

/* NOTE : MASIH BELUM DI TES */
/* BUAT GAMBARAN */
/* SEBAGIAN FUNGSI MASIH BELUM DIIMPLEMENTASI */

ListDin getAccessible(statePlayer state){
    int i,j;
    Matrix m = MAT(MAP(state)) //matriks adjacency
    POINT p = POSITION(state);
    ListDin l1 = getLokasi(MAP(state));
    ListDin l2;
    i = Absis(p);
    CreateListDin(&l2, 20);
    for (j = 0;j < COLS(m);j++) {
        if (ELMT(m,i,j) == 1) {
            ElTypel val = ELMTl(l1,j);
            char c = getNamaBangunan(l1,j);
            POINT p = getPosisiBangunan(l1,j);
            insertBangunan(&l2,c,p);
        }
    }

    return l2;
}

boolean isAccessible(statePlayer state, POINT p2){
    int i,j;
    boolean acc = false;
    Matrix m = MAT(MAP(state)) //matriks adjacency
    POINT p = POSITION(state);
    ListDin l1 = getLokasi(MAP(state));
    ListDin l2;
    i = Absis(p);
    for (j = 0;j <= COLS(m);j++) {
        if (ELMT(m,i,j) == 1) {
            if (EQ(p2,ELMTl(l1,j).posisi)) {
                acc = true;
            }
        }
    }

    if (acc) {
        return true;
    }
    else {
        return false;
    }
}

boolean isItemReadyPickUp(statePlayer state){
    int i = 0;
    boolean ready = false;
    Map m = MAP(state);
    POINT p = POSITION(state);
    ListDin l = LOC(m);
    char c;
    //get nama bangunan
    for (i = 0;i <= NEFF(l);i++) {
        if (EQ(p,ELMTl(l,i).posisi)) {
            c = ELMTl(l,i).name;
            break;
        }
    }

    dealocate(&l);
    l = ORDER(state);
    for (i = 0;i <= NEFF(l);i++) {
        if (PickUp(ELMTl(l,i).name == c)) {
            ready = true;
            break;
        }
    }
    dealocate(&l);
    if (ready) {
        return true;
    }
    else {
        return false;
    }
}

boolean isItemReadyDrop(statePlayer state){
        int i = 0;
    boolean ready = false;
    Map m = MAP(state);
    POINT p = POSITION(state);
    ListDin l = LOC(m);
    char c;
    //get nama bangunan
    for (i = 0;i <= NEFF(l);i++) {
        if (EQ(p,ELMTl(l,i).posisi)) {
            c = ELMTl(l,i).name;
            break;
        }
    }

    dealocate(&l);
    l = ORDER(state);
    for (i = 0;i <= NEFF(l);i++) {
        if (DropOff(ELMTl(l,i).name == c)) {
            ready = true;
            break;
        }
    }
    dealocate(&l);
    if (ready) {
        return true;
    }
    else {
        return false;
    }
}


void MOVE(statePlayer *state, POINT p){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    AddTimeByMove(&(TIME(*state)));
    POSITION(*state) = p;
}

void PICK_UP(statePlayer *state) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    char item = getItem(*state,POSITION(*state));
    push(&TAS(*state),item);
}

