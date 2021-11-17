#include <stdio.h>
#include "stack.h"

int main(){
    Stack tas;
    Order ord;
    CreateStack(&tas);

    ord = newOrder(1,'A','B','N',0);
    pushStack(&tas,ord);
    ord = newOrder(1,'D','B','N',0);
    pushStack(&tas,ord);
    ord = newOrder(1,'C','B','N',0);
    pushStack(&tas,ord);
    ord = newOrder(1,'D','E','N',0);
    pushStack(&tas,ord);

    popStack(&tas,&ord);
    printf("%d\n",ord.tArrival);
    popStack(&tas,&ord);
    printf("%d\n",ord.tArrival);
    popStack(&tas,&ord);
    printf("%d\n",ord.tArrival);
    popStack(&tas,&ord);
    printf("%d\n",ord.tArrival);
    return 0;
}
