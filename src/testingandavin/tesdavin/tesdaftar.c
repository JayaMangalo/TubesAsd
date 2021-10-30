#include "ADT Linked List/list_linked.h"
#include <stdio.h>
#include "ADT Queue/queue.h"

Daftar createDaftar(List td, int time)
{
    Daftar daftar;
    IDX_HEAD(daftar) = IDX_UNDEF;
    IDX_TAIL(daftar) = IDX_UNDEF;
    for (int i=1;i<=time;i++)
    {
        Address current = FIRST(td);
        while(current!=NULL)
        {
            if (TimeIn(INFO(current))==i)
            {
                enqueueDaftar(&daftar, INFO(current));
            }
            current = NEXT(current);
        }
    }
    return daftar;
}

void enqueueDaftar(Daftar *q, Order val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if(IDX_TAIL(*q)==CAPACITY-1) {
        for(i=IDX_HEAD(*q);i<=IDX_TAIL(*q);i++) {
            (*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
        }
        IDX_TAIL(*q) = IDX_TAIL(*q) - IDX_HEAD(*q);
        IDX_HEAD(*q) = 0;
    }
    if(IDX_TAIL(*q)==IDX_UNDEF) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        IDX_TAIL(*q)++;
        TAIL(*q) = val;
    }
};

void dequeueDaftar(Daftar *q, Order *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur";
        q mungkin kosong */
    /* Kamus Lokal */
    /* Algoritma */
    *val = HEAD(*q);
    if(IDX_HEAD(*q)==IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) +=1;
    }
};

void displayDaftar(Daftar q)
{
    if(!isDEmpty(q)) {
        Order val;
        int i = 1;
        while(!isDEmpty(q))
        {
            dequeueDaftar(&q,&val);
            if(TYPE(val)=='N') {
                printf("%d. %c -> %c (Normal Item)\n", i, PickUp(val), DropOff(val));
                i++;
            } else if(TYPE(val)=='H') {
                printf("%d. %c -> %c (Heavy Item)\n", i, PickUp(val), DropOff(val));
                i++;
            } else if(TYPE(val)=='P') {
                printf("%d. %c -> %c (Perishable Item, sisa waktu %d)\n", i, PickUp(val), DropOff(val), TimePerish(val));
                i++;
            }
        }
    }
}

int main() {
    /* KAMUS */
    List toDo;
    Order ord1 = (Order){1,'G','N','N',0};
    Order ord2 = (Order){3,'G','N','H',0};
    Order ord3 = (Order){2,'B','M','N',0};
    Order ord4 = (Order){1,'M','B','H',0};
    Order ord5 = (Order){5,'C','D','N',0};
    Order ord6 = (Order){3,'F','E','N',0};
    Order ord7 = (Order){10,'P','Q','P',20};
    Order ord8 = (Order){5,'G','N','P',10};
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

    Daftar daftar = createDaftar(toDo,10);
    displayDaftar(daftar);

    return 0;
}
