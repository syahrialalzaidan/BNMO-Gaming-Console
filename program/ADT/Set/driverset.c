#include "set.c"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"

int main(){
    Set s;
    printf("Membuat set\n");
    CreateEmptySet(&s);
    if (IsEmptySet(s)){
        printf("Saat ini set kosong\n");
    }
    if (!IsFullSet(s)){
        printf("Saat ini set tidak full\n");
    }
    char* x = "ISI";
    printf("Memasukkan isi ke set\n");
    InsertSet(&s, x);
    if (!IsEmptySet(s)){
        printf("Saat ini set tidak kosong\n");
    }
    if (IsMember(s, x)){
        printf("ISI merupakan member dari set\n");
    }
    printf("Menghapus ISI dari set\n");
    DeleteSet(&s, x);
    if (IsEmptySet(s)){
        printf("Set saat ini kosong\n");
    }

    return 0;
}