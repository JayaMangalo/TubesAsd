#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "setup.h"


void setup(int *Row,int *Column, POINT *HQ, ListDin *List_bangunan, Matrix *m ,Daftar *DaftarOrder){
    startWord();

    //GET BANYAK ROW&COLUMN AND CHANGE IT
    *Row = WordToInt(currentWord);
    advWord();
    *Column = WordToInt(currentWord);


    //GET HQ COORDINATES AND CHANGE IT
    int Absis, Ordinat;
    advWord();
    Absis = WordToInt(currentWord);
    advWord();
    Ordinat = WordToInt(currentWord);
    *HQ = MakePOINT(Absis,Ordinat);

    //GET BANYAK BANGUNAN
    int Bangunan_amount;
    advWord();
    Bangunan_amount = WordToInt(currentWord);

    //MAKE LISTDIN BANGUNAN
    CreateListDin(List_bangunan,Bangunan_amount);


    //MAKE POINT OF HQ AND INSERT TO LISTDIN BANGUNAN
    POINT p;
    p = MakePOINT(Absis,Ordinat);
    insertBangunan(List_bangunan, '8' ,p);

    //MAKE POINT OF BANGUNAN AND INSERT TO LISTDIN BANGUNAN (FOR LOOP BANYAK BANGUNAN)
    char bangunan_nama;
    for (int i = 0; i < Bangunan_amount; i++)
    {
        //GET POINT FOR BANGUNAN
        advWord();
        bangunan_nama =  currentWord.contents[0];
        advWord();
        Absis = WordToInt(currentWord);
        advWord();
        Ordinat = WordToInt(currentWord);

        //MAKE POINT OF BANGUNAN AND INSERT TO LISTDIN BANGUNAN
        p = MakePOINT(Absis,Ordinat);
        insertBangunan(List_bangunan, bangunan_nama ,p);
    }

    //GET AND MAKE ADJANCENCY MATRIX
    CreateMatrix(Bangunan_amount+1,Bangunan_amount+1,m);
    for(int i=0;i<ROWS(*m);i++) {
        for(int j=0;j<COLS(*m);j++) {
            advWord();
            ELMT(*m,i,j) = WordToInt(currentWord);
        }
    }

    //GET BANYAK ORDER
    int Order_amount;
    advWord();
    Order_amount = WordToInt(currentWord);

    Order ord;
    for (int i = 0; i < Order_amount; i++)
    {
        advWord();
        TimeIn(ord) = WordToInt(currentWord);
        advWord();
        PickUp(ord) = currentWord.contents[0];
        advWord();
        DropOff(ord) = currentWord.contents[0];
        advWord();
        TYPE(ord) =  currentWord.contents[0];
        if (currentWord.contents[0] == 'P')
        {
            advWord();
            TimePerishDefault(ord) = WordToInt(currentWord);
            TimePerish(ord) = TimePerishDefault(ord);
        }
        else{
            TimePerish(ord) = 0;
            TimePerish(ord) = TimePerishDefault(ord);
        }
        enqueue(DaftarOrder, ord);
    }
    printf("GAME INITIALIZED SUCCESFULLY\n");
}
