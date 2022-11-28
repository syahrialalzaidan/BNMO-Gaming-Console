#ifndef SKIPGAME_H
#define SKIPGAME_H

#include "playgame.h"

void skipgame(Queue *qg, int x, ArrayDin array, float *skor);
/* Melewatkan permainan sebanyak n. */
/* I.S. Array game tidak mungkin kosong. Queue game mungkin kosong.*/
/* F.S. Jika game ke-(n+1) ada di dalam queue, sistem akan memainkan game ke-(n+1) pada queue.
Jika game ke-(n+1) tidak terdefinisi, maka queue akan kosong. */

#endif