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
int getID(Word kata);
void serve(Queue *q1, Queue *q2, int i, int *saldo, int *count, boolean *sukses);
void playdinnerdash(float *skor);


#endif