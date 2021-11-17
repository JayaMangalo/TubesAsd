#include "setup/setup.h"

List toDo;
Daftar DaftarOrdertest;
Time Ttest;

int main() {
    startWord();
    CreateList(&toDo);
    // Test bila toDo kosong
    displayToDo(toDo);
    CreatePrioQueue(&DaftarOrdertest);
    CreateTime(&Ttest);
    // Test bila toDo tidak kosong
    /*
    Order ord1 = newOrder(1,'G','N','N',0);
    Order ord2 = newOrder(0,'M','B','H',0);
    Order ord3 = newOrder(0,'B','M','N',0);
    Order ord4 = newOrder(3,'G','N','H',0);
    Order ord5 = newOrder(0,'F','E','N',0);
    Order ord6 = newOrder(0,'C','D','N',0);
    Order ord7 = newOrder(2,'G','N','P',10);
    Order ord8 = newOrder(10,'P','Q','P',20);
    
    enqueue(&DaftarOrdertest, ord1);
    enqueue(&DaftarOrdertest, ord2);
    enqueue(&DaftarOrdertest, ord3);
    enqueue(&DaftarOrdertest, ord4);
    enqueue(&DaftarOrdertest, ord5);
    enqueue(&DaftarOrdertest, ord6);
    enqueue(&DaftarOrdertest, ord7);
    enqueue(&DaftarOrdertest, ord8);
    */
    Order ord;
    ord = newOrder(1,'G','N','N',0);
    enqueue(&DaftarOrdertest, ord);
    ord = newOrder(0,'M','B','H',0);
    enqueue(&DaftarOrdertest, ord);
    ord = newOrder(0,'B','M','N',0);
    enqueue(&DaftarOrdertest, ord);
    ord = newOrder(3,'G','N','H',0);
    enqueue(&DaftarOrdertest, ord);
    ord = newOrder(0,'F','E','N',0);
    enqueue(&DaftarOrdertest, ord);
    ord = newOrder(0,'C','D','N',0);
    enqueue(&DaftarOrdertest, ord);
    ord = newOrder(2,'G','N','P',10);
    enqueue(&DaftarOrdertest, ord);
    ord = newOrder(10,'P','Q','P',20);
    enqueue(&DaftarOrdertest, ord);

    updToDo(&toDo,&DaftarOrdertest, &Ttest);
    AddTimeByMove(&Ttest);
    updToDo(&toDo,&DaftarOrdertest, &Ttest);
    AddTimeByMove(&Ttest);
    updToDo(&toDo,&DaftarOrdertest, &Ttest);
    /*
    insertLastLL(&toDo,ord1);
    insertLastLL(&toDo,ord2);
    insertLastLL(&toDo,ord3);
    insertLastLL(&toDo,ord4);
    insertLastLL(&toDo,ord5);
    insertLastLL(&toDo,ord6);
    insertLastLL(&toDo,ord7);
    insertLastLL(&toDo,ord8);
    */
    displayToDo(toDo);
    return 0;    
}