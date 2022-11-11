#include "map.c"
#include <stdio.h>
#include "../boolean/boolean.h"

int main(){
    printf("Membuat map\n");
    Map m;
    CreateEmpty(&m);
    printf("Map terbuat\n");
    if (IsMapEmpty(m)){
        printf("Map saat ini kosong\n\n");
    }

    keytype k = "kunci";
    valuetype v = "isi";
    
    printf("Insert map\n");
    Insert(&m, k, v);
    if (!IsMapEmpty(m)){
        printf("Map saat ini tidak kosong\n");
    }
    if (!IsFull(m)){
        printf("Map saat ini tidak full\n");
    }

    printf("\nMengambil value\n");
    valuetype vv = Value(m, k);
    printf("Value: %s\n", vv);

    printf("\nMenghapus di map\n");
    Delete(&m, k);
    if (IsMapEmpty(m)){
        printf("Map saat ini kosong\n");
    }
    return 0;
}