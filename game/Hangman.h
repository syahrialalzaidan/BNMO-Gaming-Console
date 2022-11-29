#include "../program/ADT/Map/mapchar.h"
#include "../program/ADT/Set/sethangman.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void generatemap(MapChar *kamus);
char UpperHuruf(char input);
int countkata(char *kata);
void playtebakkata(int* scoretotal);
boolean isstringequal(char *kata1, char *kata2);
