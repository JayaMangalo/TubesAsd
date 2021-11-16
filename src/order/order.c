#include "order.h"

Order newOrder(int tArrival, char pick_up_point, char drop_off_point, char type, int tPerishDefault) {
    return (Order){tArrival,pick_up_point,drop_off_point,type,tPerishDefault,tPerishDefault};
};

int fee(Order ord) {
/* Mengembalikan Upah setelah nganter Order ord */
    if(TYPE(ord)=='N') {
        return 200;
    } else if(TYPE(ord)=='H') {
        return 400;
    } else if(TYPE(ord)=='P') {
        return 400;
    }
};


boolean isOrderEqual(Order ord1,Order ord2) {
    /* KAMUS LOKAL */
    boolean equal;
    /* ALGORITMA */
    equal = false;
    if (TimeIn(ord1) == TimeIn(ord2)) {
        if (PickUp(ord1) == PickUp(ord2)){
            if (DropOff(ord1) == DropOff(ord2)) {
                if(TYPE(ord1) == TYPE(ord2)) {
                    if (TimePerish(ord1) == TimePerish(ord2)){
                        equal = true;
                    }
                }
            }
        }
    }

    return equal;
}