#include <stdio.h>
#include "prioqueue.h"

int main(){
    Daftar q;
    Order ord;
    CreatePrioQueue(&q);

    ord = newOrder(1,'A','B','N',0);
    enqueue(&q,ord);
    ord = newOrder(1,'D','B','N',0);
    enqueue(&q,ord);
    ord = newOrder(1,'C','B','N',0);
    enqueue(&q,ord);
    ord = newOrder(1,'D','E','N',0);
    enqueue(&q,ord);

    displayDaftar(q);

    dequeue(&q,&ord);
    dequeue(&q,&ord);
    displayDaftar(q);
    dequeue(&q,&ord);
    dequeue(&q,&ord);
    displayDaftar(q);
    return 0;
}
