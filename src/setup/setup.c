#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "setup.h"

void setup(){
    startWord();
    
    //GET BANYAK ROW&COLUMN
    int Row = WordToInt(currentWord);
    printf("Row: %d\n",Row);
    advWord();
    int Column = WordToInt(currentWord);
    printf("Column: %d\n",Column);
    
    //GET HQ COORDINATES
    int Absis, Ordinat;
    advWord();
    Absis = WordToInt(currentWord);
    advWord();
    Ordinat = WordToInt(currentWord);

    //GET BANYAK BANGUNAN
    int Bangunan_amount;
    advWord();
    Bangunan_amount = WordToInt(currentWord);

    //MAKE LISTDIN BANGUNAN
    ListDin List_bangunan;
    CreateListDin(&List_bangunan,Bangunan_amount);


    //MAKE POINT OF HQ AND INSERT TO LISTDIN BANGUNAN
    POINT p;
    p = MakePOINT(Absis,Ordinat);
    insertBangunan(&List_bangunan, '8' ,p);

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
        insertBangunan(&List_bangunan, bangunan_nama ,p);
    }
    displayList(List_bangunan);

    //GET AND MAKE ADJANCENCY MATRIX
    Matrix m;
    CreateMatrix(Bangunan_amount+1,Bangunan_amount+1,&m);
    for(int i=0;i<ROWS(m);i++) {
        for(int j=0;j<COLS(m);j++) {
            advWord();
            ELMT(m,i,j) = WordToInt(currentWord);
        }
    }
    displayMatrix(m);

    //GET BANYAK ORDER
    int Order_amount;
    advWord();
    Order_amount = WordToInt(currentWord);

    //MAKE ORDER AND INSERT TO QUEUE BANGUNAN (FOR LOOP BANYAK BANGUNAN)
    //WORK IN PROGRESS
    //TODO: REMAKE ADT QUEUE
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
            TimePerish(ord) = WordToInt(currentWord);
        }
        else{
            TimePerish(ord) = 0;
        }
        
        //TODO: MASUKIN KE QUEUE DAFTAR PESANAN
    }
}

// int main(){
//     setup();
// }