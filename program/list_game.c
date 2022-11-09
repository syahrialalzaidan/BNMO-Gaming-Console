#include <stdio.h>
#include "list_game.h"

void listgame (ArrayDin array){
/*  Menampilkan daftar game yang disediakan oleh sistem.
    I.S. Array games tidak mungkin kosong.
    F.S. Menampilkan daftar game yang dimiliki sistem ke layar. */
    printf("\nBerikut adalah daftar game yang tersedia:\n");
    for (int i=0; i != array.Neff; i++)
    {
        printf("%d. %s\n", i+1, array.A[i]);
    }
    printf("\n");
}