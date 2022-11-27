#include "stack.c"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"

int main(){
    Stack s;
    CreateEmptyStack(&s);
    if (IsStackEmpty(s)){
        printf("Stack saat ini kosong\n");
    }
    infotype i = "ISI";
    printf("Menambahkan isi stack\n");
    Push(&s, i);
    if (!IsStackEmpty(s)){
        printf("Stack saat ini tidak kosong\n");
    }
    if (!IsStackFull(s)){
        printf("Stack saat ini tidak full\n");
    }
    int jumlah = nbElmtStack(s);
    printf("Jumlah stack saat ini: %d\n", jumlah);
    printf("Menghapus isi stack\n");
    Pop(&s, &i);
    if (IsStackEmpty(s)){
        printf("Stack saat ini kosong");
    }

    return 0;
}