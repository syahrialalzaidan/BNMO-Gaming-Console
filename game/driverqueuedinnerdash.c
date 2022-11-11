#include "queuedinnerdash.h"

int main() {
    Queue menu,masak;
    CreateQueue(&menu);
    ElType menu1, menu2,menu3;
    menu1.durasi  = 2;
    menu1.id = 1;
    menu1.harga = 15000;
    menu1.ketahanan = 3;
    menu2.durasi  = 3;
    menu2.id = 2;
    menu2.harga = 20000;
    menu2.ketahanan = 5;

    enqueue(&menu, menu1);
    enqueue(&menu, menu2);
    CreateQueue(&masak);
    daftarserve(masak, menu);
}