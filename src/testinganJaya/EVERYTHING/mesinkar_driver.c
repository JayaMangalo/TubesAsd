#include <stdio.h>
#include "wordmachine.c"
#include "charmachine.c"
#include "listdin.c"
#include "listdin.h"

int main(){
    startWord();
    
    int Row = WordToInt(currentWord);
    printf("Row: %d\n",Row);

    advWord();

    int Column = WordToInt(currentWord);
    printf("Column: %d\n",Column);

    int AbsisHQ, OrdinatHQ;

    advWord();
    AbsisHQ = WordToInt(currentWord);
    advWord();
    OrdinatHQ = WordToInt(currentWord);

    int Bangunan_amount;
    advWord();
    Bangunan_amount = WordToInt(currentWord);

    ListDin List_Bangunan;
    Point p;
    CreateListDin(&List_Bangunan);
    
    for (int i = 0; i < Bangunan_amount; i++)
    {
        advWord();
            
        advWord();

        advWord();
    }
    
}