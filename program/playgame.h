#ifndef PLAYGAME_H
#define PLAYGAME_H

#include "queuegame.h"

#include "../game/dinnerdash.h"
#include "../game/queuedinnerdash.h"
#include "../game/rng.h"
#include "../game/tebakkata.h"
#include "../game/SnakeOnMeteor.h"
#include "../game/towerofhanoi.h"
#include "../game/Hangman.h"
#include "ADT/boolean/boolean.h"

boolean isStringSame(char *c1, char*c2);
/* Mengembalikan true jika string sama */

void play(Queue *qg, ArrayDin array, float *skor);
/* Memainkan sebuah permainan tanpa menuliskan daftar game
    I.S. Array game tidak mungkin kosong
    F.S. Game yang berada di posisi Head akan dimainkan */

void playgame(Queue *qg, ArrayDin array, float *skor, boolean *found);
/*  Memainkan sebuah permainan.
    I.S. Array game mungkin kosong.
    F.S. Menuliskan daftar game dan game yang berada di posisi Head akan dimainkan. */



#endif