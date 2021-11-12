#ifndef ORDER_H
#define ORDER_H

typedef struct {
    int tArrival; /* Waktu pesanan masuk */
    char pick_up_point; /* Bangunan lokasi pick up */
    char drop_off_point; /* Bangunan lokasi drop off */
    char type; /* jenis item */
    int tPerishDefault; /* Durasi hangus semula bila itemnya Perishable item */
    int tPerish; /* sisa durasi hangus bila itemnya Perishable item */
} Order;

/* Selektor */
#define TimeIn(ord) (ord).tArrival
#define PickUp(ord) (ord).pick_up_point
#define DropOff(ord) (ord).drop_off_point
#define TYPE(ord) (ord).type
#define TimePerishDefault(ord) (ord).tPerishDefault
#define TimePerish(ord) (ord).tPerish

Order newOrder(int tArrival, char pick_up_point, char drop_off_point, char type, int tPerishDefault);
int fee(Order ord);
/* Mengembalikan Upah setelah nganter Order ord */

/*
Contoh inisialisasi pesanan pertama
Order ord = newOrder(1,'G','N','N',0)  // tPerishDefault bebas diisi berapa kalo bukan Perishable item
*/

#endif