#ifndef tebakkata_H
#define tebakkata_H

#include "../program/ADT/Map/mapchar.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//gcc -o tebakkata tebakkata.c ../program/ADT/Map/mapchar.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c


void generatemap(MapChar *kamus);
/*  Memasukkan key dan value ke dalam kamus. 
    I.S.: kamus kosong.
    F.S.: kamus terisi. */

int countkata(char *kata);
/*  Mengembalikan jumlaha karakter dalam suatu kata. */

boolean isstringequal(char *kata1, char *kata2);
/* Mengembalikan nilai true jika kata1 dan kata2 sama. */

void playtebakkata(float *score);
/*  Memainkan permainan tebak kata.
    I.S.: score sembarang.
    F.S.: Permainan tebak kata dimainkan dan score berubah. */

#endif
