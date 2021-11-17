#include <stdio.h>
#include "list_linked.h"

int main(){
    List list;
    Order ord;
    CreateList(&list);

    ord = newOrder(1,'A','B','N',0);
    insertFirstLL(&list,ord);
    ord = newOrder(1,'D','B','N',0);
    insertFirstLL(&list,ord);
    ord = newOrder(1,'C','B','N',0);
    insertLasttLL(&list,ord);
    ord = newOrder(1,'D','E','N',0);
    insertAtLL(&list,ord,1);

    displayList(list);

    deleteAtLL(&list,&ord,1);
    deleteFirstLL(&list,&ord);
    displayList(list);
    deleteLastLL(&list,&ord);
    deleteFirstLL(&list,&ord);
    displayList(list);  

    return 0;
}
