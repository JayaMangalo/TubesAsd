#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "../order/order.h"

typedef Order node_El;
typedef struct node* Address;
typedef struct node {
    node_El info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(node_El val);


#endif