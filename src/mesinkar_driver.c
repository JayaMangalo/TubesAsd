#include <stdio.h>
#include "wordmachine/wordmachine.c"
#include "charmachine/charmachine.c"
#include "listdin/listdin.c"
#include "point/point.c"
#include "matrix/matrix.c"
#include "list_linked/list_linked.h"

int main(){
    startWord();
    
    int Row = WordToInt(currentWord);
    printf("Row: %d\n",Row);

    advWord();

    int Column = WordToInt(currentWord);
    printf("Column: %d\n",Column);
    
    int Absis, Ordinat;

    advWord();

    Absis = WordToInt(currentWord);
    advWord();
    Ordinat = WordToInt(currentWord);

    int Bangunan_amount;
    advWord();
    Bangunan_amount = WordToInt(currentWord);

    ListDin List_bangunan;
    POINT p;
    CreateListDin(&List_bangunan,Bangunan_amount);

    p = MakePOINT(Absis,Ordinat);

    insertBangunan(&List_bangunan, '8' ,p);

    char bangunan_nama;
    for (int i = 0; i < Bangunan_amount; i++)
    {
        advWord();
        bangunan_nama =  currentWord.contents[0];
        advWord();
        Absis = WordToInt(currentWord);
        advWord();
        Ordinat = WordToInt(currentWord);

        p = MakePOINT(Absis,Ordinat);
        insertBangunan(&List_bangunan, bangunan_nama ,p);
    }

    displayList(List_bangunan);

    Matrix m;
    CreateMatrix(Bangunan_amount+1,Bangunan_amount+1,&m);
    for(int i=0;i<ROWS(m);i++) {
        for(int j=0;j<COLS(m);j++) {
            advWord();
            ELMT(m,i,j) = WordToInt(currentWord);
        }
    }
    displayMatrix(m);

    int Order_amount;
    advWord();
    Order_amount = WordToInt(currentWord);

    
    for (int i = 0; i < Order_amount; i++)
    {

        advWord();

        advWord();

        advWord();

        advWord();
    }
    
}