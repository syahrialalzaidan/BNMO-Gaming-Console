#include <stdio.h>
#include "delete_game.h"

boolean IsInQueue(Queue queuegame, char* elQ) {
/*I.S. Queue game mungkin kosong*/
/*F.S. Elemen queue ditemukan atau tidak*/
    int i;
    boolean found = false;
    Word K1 = stringToWord(elQ);
    while (i <= IDX_TAIL(queuegame) && !found) {
        Word K2 = stringToWord(queuegame.buffer[i]);
        if (isWordSame(K1, K2)) {
            found = true;
        }
        i++;
    }
    return found;
}

void deletegame(ArrayDin *array, Queue queuegame){
/*I.S. Array game mungkin kosong*/
/*F.S. Asumsi nomor game input pasti valid. Nomor games yang ingin dihapus telah hilang dari array*/
    listgame (*array);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD();
    int input = WordToInt(currentWord);
    IdxType i = input;
    char* el = array->A[i-1];
    printf("Game yang akan dihapus: %s\n", el);
    if (i > 5 && !IsInQueue(queuegame, el)) {
        DeleteAt(array, i-1);
        printf("Game berhasil dihapus\n");
    }
    else{
        printf("Game gagal dihapus");
    }
}