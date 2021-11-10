#include <stdio.h>
#include "setup/setup.h"

int main(){
    printf("gay\n");
    int Row,Column;
    POINT HQ;
    ListDin List_bangunan;
    Matrix m;
    Daftar DaftarOrder;
    startCommand();
    setup(&Row, &Column, &HQ,  &List_bangunan, &m,&DaftarOrder);
        printf("Row: %d\n",Row);
        printf("Column: %d\n",Column);
        TulisPOINT(HQ);
        displayList(List_bangunan);
        displayMatrix(m);
        displayDaftar(DaftarOrder);
}