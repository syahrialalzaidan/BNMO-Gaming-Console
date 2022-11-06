#include <stdio.h>
#include "arraydin.h"
#include "mesinkata.h"
#include "mesinkar.h"

void creategame (ArrayDin *array){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

    char* string;
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    string = currentWord.TabWord;
    printf("Game berhasil ditambahkan\n");
    


    //printf("Tes %s", string);

    //printf("%d", currentWord.Length);
    InsertLast(&array, *string);
    printf("Tes %s", (*array).A[(*array).Neff]);
}

int main()
{
    ArrayDin S;
    S = MakeArrayDin();
    creategame(&S);
}