/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(node_El val) {
    printf("gay2\n");
    Address p = (Address) malloc(sizeof(Node));
    printf("gay2\n");
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}