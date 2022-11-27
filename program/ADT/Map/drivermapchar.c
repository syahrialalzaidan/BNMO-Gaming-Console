#include "mapchar.c"
#include <stdio.h>
#include "../boolean/boolean.h"

int main(){
    printf("Membuat map\n");
    Map m;
    CreateEmptyChar(&m);
    printf("Map terbuat\n");
    if (IsMapEmptyChar(m)){
        printf("Map saat ini kosong\n\n");
    }

    keytype k = "kunci";
    valuetypechar v = "i";
    
    printf("Insert map\n");
    InsertChar(&m, k, v);
    if (!IsMapEmptyChar(m)){
        printf("Map saat ini tidak kosong\n");
    }
    if (!IsFullChar(m)){
        printf("Map saat ini tidak full\n");
    }

    printf("\nMengambil value\n");
    valuetypechar vv = ValueChar(m, k);
    printf("Value: %s\n", vv);

    printf("\nMenghapus di map\n");
    DeleteChar(&m, k);
    if (IsMapEmptyChar(m)){
        printf("Map saat ini kosong\n");
    }
    return 0;
}