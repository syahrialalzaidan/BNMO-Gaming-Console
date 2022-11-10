#ifndef PLAYGAME_H
#define PLAYGAME_H

#include "queuegame.h"

#include "../game/dinnerdash.h"
#include "../game/queuedinnerdash.h"
#include "../game/rng.h"
#include "../game/tebakkata.h"

boolean isStringSame(char *c1, char*c2);
/* Mengembalikan true jika string sama */

void playgame();
/*  Memainkan sebuah permainan.
    I.S. Array game tidak mungkin kosong.
    F.S. Game yang berada di posisi Head akan dimainkan. */


#endif