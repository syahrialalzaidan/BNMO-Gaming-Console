#include "../program/ADT/Map/mapchar.h"
#include "../program/ADT/Set/sethangman.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include "../program/ADT/Set/set.h"
#include "../program/load.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//gcc -o hangman Hangman.c ../program/ADT/Map/mapchar.c ../program/ADT/Set/sethangman.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c ../program/ADT/Set/set.c ../program/load.c ../program/ADT/Stack/stack.c ../program/ADT/Map/map.c ../program/ADT/arraydin/arraydin.c

//void generatemap(MapChar *kamus);
void loadkamus(char* filename, Set* kamus);
char UpperHuruf(char input);
int countkataHM(char *kata);
void playtebakkataHM(float* scoretotal);
boolean isstringequalHM(char *kata1, char *kata2);
void Hangman(float *skor, boolean *playtebakkataHM);
