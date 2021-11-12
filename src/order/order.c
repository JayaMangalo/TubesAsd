#include "order.h"

Order newOrder(int tArrival, char pick_up_point, char drop_off_point, char type, int tPerishDefault) {
    return (Order){tArrival,pick_up_point,drop_off_point,type,tPerishDefault,tPerishDefault};
};