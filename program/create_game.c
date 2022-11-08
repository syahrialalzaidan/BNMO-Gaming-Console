#include <stdio.h>
#include "create_game.h"

void creategame (ArrayDin *array){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

    char* string;
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    string = WordToString(currentWord);
    if (SearchArrayDin(*array, string) == -1)
    {
        printf("Game berhasil ditambahkan\n");
        InsertLast(array, string);
    }
    else{
        printf("Game telah tersedia\n");
    }

    //printf("Tes %s", string);

    //printf("%d", currentWord.Length);
    
    //printf("Tes %s", (*array).A[(*array).Neff]);
}

// int main()
// {
//     ArrayDin S;
//     S = MakeArrayDin();
//     creategame(&S);
// }