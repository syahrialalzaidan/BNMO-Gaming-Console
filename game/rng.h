#ifndef RNG_H
#define RNG_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../program/ADT/mesinkarkata/mesinkata.h"
//gcc -o rng rng.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c


void rng(float *score);

/* Fungsi RNG bakal ngereturn score yang diperoleh pemain
 * Jumlah maksimal tebakan adalah 5 kali
 * Fullscore adalah 10 dan akan berkurang 20% seiring dengan berkurangnya guess hingga benar
*/


#endif