#include "SnakeOnMeteor.h"
#include <stdio.h>
//gcc snake_driver.c SnakeOnMeteor.c ../program/ADT/listdp/listdp.c ../program/ADT/mesinkarkata/mesinkar.c ../program/ADT/mesinkarkata/mesinkata.c -o ular
int main() {
    int skor = 0;
    PlaySnakeOnMeteor(&skor);
    printf("Skor: %d\n", skor);
}