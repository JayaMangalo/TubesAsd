#ifndef ORDER_H
#define ORDER_H

typedef struct {
    int tArrival; /* Waktu pesanan masuk */
    char pick_up_point; /* Bangunan lokasi pick up */
    char drop_off_point; /* Bangunan lokasi drop off */
    char type; /* jenis item */
    int tPerish; /* durasi hangus bila itemnya Perishable item */
} Order;

/* Selektor */
#define TimeIn(ord) (ord).tArrival
#define PickUp(ord) (ord).pick_up_point
#define DropOff(ord) (ord).drop_off_point
#define TYPE(ord) (ord).type
#define TimePerish(ord) (ord).tPerish

/*
Contoh inisialisasi pesanan pertama
Order ord = (Order){1,'G','N','N',0}  // tPerish bebas diisi berapa kalo bukan Perishable item
*/

#endif