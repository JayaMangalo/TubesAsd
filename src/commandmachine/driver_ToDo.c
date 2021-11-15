#include "command.h"

List toDo;

int main() {
    CreateList(&toDo);
    // Test bila toDo kosong
    displayToDo(toDo);

    // Test bila toDo tidak kosong
    Order ord1 = newOrder(1,'G','N','N',0);
    Order ord2 = newOrder(1,'M','B','H',0);
    Order ord3 = newOrder(2,'B','M','N',0);
    Order ord4 = newOrder(3,'G','N','H',0);
    Order ord5 = newOrder(3,'F','E','N',0);
    Order ord6 = newOrder(5,'C','D','N',0);
    Order ord7 = newOrder(5,'G','N','P',10);
    Order ord8 = newOrder(10,'P','Q','P',20);

    insertLast(&toDo,ord1);
    insertLast(&toDo,ord2);
    insertLast(&toDo,ord3);
    insertLast(&toDo,ord4);
    insertLast(&toDo,ord5);
    insertLast(&toDo,ord6);
    insertLast(&toDo,ord7);
    insertLast(&toDo,ord8);

    displayToDo(toDo);
    return 0;    
}