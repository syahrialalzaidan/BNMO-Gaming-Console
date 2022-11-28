#include <stdio.h>
#include "ADT/mesinkarkata/mesinkata.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/Stack/stack.h"
#include "ADT/listSetMap/listSetMap.h"

char* AddPath(char* filename);

void load(char* filename, ArrayDin* Games, Stack *History, ListSetMap *Scoreboard);
/*  Membaca save file yang berisi list game yang dapat dimainkan.
    I.S. : filename terdefinisi dan array games kosong.
    F.S. : Array games terisi dengan list game yang ada pada save file. */