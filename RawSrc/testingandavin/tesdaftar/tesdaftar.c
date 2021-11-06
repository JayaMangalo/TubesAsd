#include "ADT Linked List/list_linked.h"
#include <stdio.h>
#include "ADT Queue/prioqueue.h"
#include "ADT Mesin Kata/wordmachine.h"
#include <string.h>

int main() {
    /* KAMUS */
    Order ord1 = (Order){1,'G','N','N',0};
    Order ord2 = (Order){3,'G','N','H',0};
    Order ord3 = (Order){2,'B','M','N',0};
    Order ord4 = (Order){1,'M','B','H',0};
    Order ord5 = (Order){5,'C','D','N',0};
    Order ord6 = (Order){3,'F','E','N',0};
    Order ord7 = (Order){10,'P','Q','P',20};
    Order ord8 = (Order){5,'G','N','P',10};
    // Nanti bakal implementasi jadi pake mesin kata
    /* ALGORITMA */
    Daftar d;
    CreatePrioQueue(&d);
    enqueue(&d, ord1);
    enqueue(&d, ord2);
    enqueue(&d, ord3);
    enqueue(&d, ord4);
    enqueue(&d, ord5);
    enqueue(&d, ord6);
    enqueue(&d, ord7);
    enqueue(&d, ord8);
    // Buat list sementara untuk semua pesanan (tidak berurut berdasarkan Time-in gapapa)
    // Mengubah dan Mengurutkan list sebelumnya menjadi queue
    displayDaftar(d);
    return 0;
}
