#include "stackhanoi.c"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"

int main(){
    Stack s;
    CreateEmptyHanoi(&s);
    setNol(&s);
    if (IsEmptyHanoi(s)){
        printf("Stack saat ini kosong\n");
    }
    infotype i = 1;
    printf("Menambahkan isi stack\n");
    PushHanoi(&s, i);
    if (!IsEmptyHanoi(s)){
        printf("Stack saat ini tidak kosong\n");
    }
    if (!IsFullHanoi(s)){
        printf("Stack saat ini tidak full\n");
    }
    int x = gettop(s);
    printf("Top saat ini: %d\n", x);

    int jumlah = lengthS(s);
    printf("Jumlah stack saat ini: %d\n", jumlah);
    printf("Menghapus isi stack\n");
    PopHanoi(&s, &i);
    if (IsEmptyHanoi(s)){
        printf("Stack saat ini kosong");
    }

    return 0;
}