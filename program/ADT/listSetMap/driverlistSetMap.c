#include <stdio.h>
#include <stdlib.h>
#include "listSetMap.c"
#include "../Set/set.c"
#include "../Map/map.c"
#include "../mesinkarkata/mesinkar.c"
#include "../mesinkarkata/mesinkata.c"

int main(){
    Map m;
    CreateEmpty(&m);
    keytype k = "kunci";
    valuetype v = 10.5;
    Insert(&m, k, v);

    Set s;
    CreateEmptySet(&s);
    char* x = "ISI";
    InsertSet(&s, x);

    ListSetMap l;
    printf("Membuat ListSetMap baru \n");
    CreateEmptyLSM(&l);
    if (IsLSMEmpty(l)){
        printf("ListSetMap kosong\n");
    }

    printf("Memasukkan isi ListSetMap\n");
    InsertAtLSM(&l, 0, k, v);
    if (!IsLSMEmpty(l)){
        printf("ListSetMap tidak kosong\n");
    }
    if (!IsLSMFull(l)){
        printf("ListSetMap tidak full\n");
    }
    printf("Menghapus isi ListSetMap\n");
    DeleteAtLSM(&l, 0);
    if (IsLSMEmpty(l)){
        printf("ListSetMap kosong\n");
    }

    return 0;
}