#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkata.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/Map/map.h"

char* concat(char* s1, char* s2);
/* Mengembalikan hasil konkatenasi s1 dan s2 */

int strLen(char* str);
/* Mengembalikan panjang string */

void creategame (ArrayDin *array, ListMap *scoreboard);
/*  Menambahkan game baru pada daftar game 
    I.S. Array games terdefinisi dan terisi.
    F.S. Game yang baru ditambahkan jika game belum ada di daftar game. */