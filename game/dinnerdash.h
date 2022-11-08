#ifndef DINNERDASH_H
#define DINNERDASH_H

#include <time.h>
#include<stdio.h>
#include<stdlib.h>
#include "boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include "queuedinnerdash.h"

void generatemenu();
boolean isCook(Word kata);
boolean isSkip(Word kata);
boolean isCommandValid(Word kata);
boolean isdigitvalid(Word kata);
int getID(Word kata);
void serve(Queue *q1, Queue *q2, int i, int *saldo, int *count, boolean *sukses);
void playdinnerdash();


#endif