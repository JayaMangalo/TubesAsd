/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(node_El val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}