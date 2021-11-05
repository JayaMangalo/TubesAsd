#include "ADT Linked List/list_linked.h"
#include<stdio.h>

void displayToDo(List td) {
    /* Kamus Lokal */
    Address p;
    int i=1;
    /* Algoritma */
    if(!isEmpty(td)) {
        p = FIRST(td);
        while(p!=NULL) {
            if(TYPE(INFO(p))=='N') {
                printf("%d. %c -> %c (Normal Item)\n", i, PickUp(INFO(p)), DropOff(INFO(p)));
                i++;
                p = NEXT(p);
            } else if(TYPE(INFO(p))=='H') {
                printf("%d. %c -> %c (Heavy Item)\n", i, PickUp(INFO(p)), DropOff(INFO(p)));
                i++;
                p = NEXT(p);
            } else if(TYPE(INFO(p))=='P') {
                printf("%d. %c -> %c (Perishable Item, sisa waktu %d)\n", i, PickUp(INFO(p)), DropOff(INFO(p)), TimePerish(INFO(p)));
                i++;
                p = NEXT(p);
            }
        }
    } else {
        // tulis pesan sedang tidak ada yang harus dikerjakan
    }
}

// void updToDo(List *td, PrioQueue *dp, int curTime)
// I.S. dp berisi daftar pesanan dengan TimeIn >= curTime
// F.S. pesanan dengan TimeIn == curTime telah dimasukkan ke to do list

int main() {
    /* KAMUS */
    List toDo;
    Order ord1 = (Order){1,'G','N','N',0};
    Order ord2 = (Order){1,'M','B','H',0};
    Order ord3 = (Order){2,'B','M','N',0};
    Order ord4 = (Order){3,'G','N','H',0};
    Order ord5 = (Order){3,'F','E','N',0};
    Order ord6 = (Order){5,'C','D','N',0};
    Order ord7 = (Order){5,'G','N','P',10};
    Order ord8 = (Order){10,'P','Q','P',20};
    /* ALGORITMA */
    CreateList(&toDo);

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