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
