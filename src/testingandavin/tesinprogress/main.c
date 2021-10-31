#include <stdio.h>
#include <stdlib.h>
#include "ADT Linked List/list_linked.h"
#include "order.h"

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

void displayInProg(List ip) {
    Address p;
    int i=1;
    if(!isEmpty(ip)) {
        p = FIRST(ip);
        while(p!=NULL) {
            if(TYPE(INFO(p))=='N') {
                printf("%d. Normal Item (Tujuan: %c)\n", i,DropOff(INFO(p)));
                i++;
                p = NEXT(p);
            } else if(TYPE(INFO(p))=='H') {
                printf("%d. Heavy Item (Tujuan: %c)\n", i,DropOff(INFO(p)));
                i++;
                p = NEXT(p);
            } else if(TYPE(INFO(p))=='P') {
                printf("%d. Perishable Item (Tujuan: %c)\n", i,DropOff(INFO(p)));
                i++;
                p = NEXT(p);
            }
        }
    } else {
        printf("Belum ada yang perlu diantarkan.\n");
    }
}

void DeliverItem(List *ip, char lokasi)
{
    Address current;
    current = FIRST(*ip);
    Order val;
    int i = 0;
    while(current!=NULL)
    {
        if(DropOff(INFO(current))==lokasi)
        {
            deleteAt(ip, i, &val);
            current = FIRST(*ip);
            i = 0;
            if(TYPE(val)=='N') {
                printf("Normal Item telah diantar ke %c\n", lokasi);
            } else if(TYPE(val)=='H') {
                printf("Heavy Item telah diantar ke %c\n", lokasi);
            } else if(TYPE(val)=='P') {
                printf("Perishable Item telah diantar ke %c\n", lokasi);
            }
        } else {
            current = NEXT(current);
            i ++;
        }
    }

}

void PickUpItem(List *td, List *ip, char lokasi)
{
    Address current;
    current = FIRST(*td);
    Order val;
    int i = 0;
    while(current!=NULL)
    {
        if(PickUp(INFO(current))==lokasi)
        {
            deleteAt(td, i, &val);
            insertLast(ip, val);
            current = FIRST(*td);
            i = 0;
        } else {
            current = NEXT(current);
            i ++;
        }
    }
}

int main()
{
    /* KAMUS */
    List toDo,inProg;
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

    CreateList(&inProg);
    PickUpItem(&toDo, &inProg, 'G');
    displayInProg(inProg);
    DeliverItem(&inProg, 'N');
    displayInProg(inProg);
    return 0;
}
