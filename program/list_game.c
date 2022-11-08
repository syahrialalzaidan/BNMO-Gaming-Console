#include <stdio.h>
#include "list_game.h"

void listgame (ArrayDin array){
/* I.S. Ada daftar array game yang dimiliki user BNMO */
/* F.S. Menampilkan daftar game yang dimiliki sistem ke layar. Isi Game mungkin kosong */
    printf("Berikut adalah daftar game yang tersedia :\n");
    for (int i=0; i != array.Neff; i++)
    {
        printf("%d. %s\n", i+1, array.A[i]);
    }
}