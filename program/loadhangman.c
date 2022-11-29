#include <stdio.h>
#include <stdlib.h>
#include "ADT/Set/set.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/mesinkarkata/mesinkata.h"
#include "load.h"

void loadkamus(char* filename, Set* kamus) {
/*  Membaca save file yang berisi list game yang dapat dimainkan.
    I.S. : filename terdefinisi dan array games kosong.
    F.S. : Array games terisi dengan list game yang ada pada save file. */
    char* filepath = AddPath(filename);
    char* name;
    float score;
    // LoadPita("./data/config.txt");
    LoadPita(filepath, true);
    // load games
    STARTWORD();
    int jmlGame = WordToInt(currentWord);
    int j = 0;
    while (j < jmlGame) {
        ADVWORD();
        char* name = WordToString(currentWord);
        InsertSet(kamus, name);
        j++;
    }
    StopLoadPita();
}