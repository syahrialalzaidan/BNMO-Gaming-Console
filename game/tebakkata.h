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

int countkata(char *kata);

boolean isstringequal(char *kata1, char *kata2);

void playtebakkata(float *score);

#endif
