#include <stdio.h>
#include "ADT/mesinkarkata/mesinkatafile.h"
#include "ADT/mesinkarkata/mesinkarfile.h"
#include "ADT/arraydin/arraydin.h"

char* AddPath(char* filename);

void load(char* filename, ArrayDin* Games);
/*  Membaca save file yang berisi list game yang dapat dimainkan.
    I.S. : filename terdefinisi dan array games kosong.
    F.S. : Array games terisi dengan list game yang ada pada save file. */