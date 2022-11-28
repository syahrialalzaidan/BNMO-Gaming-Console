#ifndef DINNERDASH_H
#define DINNERDASH_H

#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include "../program/ADT/boolean/boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include "queuedinnerdash.h"

void generatemenu();
/* I.S sembarang 
 * F.S terdapat menu baru pada Queue q */

boolean isCook(Word kata);
/* Mengecek apakah kata merupakan perintah cook */

boolean isSkip(Word kata);
/* Mengecek apakah kata merupakan perintah skip */

boolean isCommandValid(Word kata);
/* Mengecek apakah kata merupakan perintah yang valid */

boolean isdigitvalid(Word kata);
/* Mengecek apakah kata merupakan digit yang valid */

int getID(Word kata);
/* Mengembalikan ID dari kata */

void serve(Queue *q1, Queue *q2, int i, int *saldo, int *count, boolean *sukses);
/* I.S. q1 terdefinisi, q2 terdefinisi, i terdefinisi, saldo terdefinisi, count terdefinisi, sukses terdefinisi
 * F.S. q1 terdefinisi, q2 terdefinisi, i terdefinisi, saldo terdefinisi, count terdefinisi, sukses terdefinisi */

void playdinnerdash(float *score);
/* I.S. sembarang
 * F.S. Permainan dijalankan, score terdefinisi */


#endif