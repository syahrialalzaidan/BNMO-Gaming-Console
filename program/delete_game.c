#include <stdio.h>
#include "delete_game.h"

boolean IsInQueue(Queue queuegame, char* elQ) {
/* Mengembalikan nilai true jika elemen ada di dalam queue. */
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
/*  Menghapus sebuah game dari daftar game.
    I.S. Array game tidak mungkin kosong.
    F.S. Game yang ingin dihapus telah hilang dari array jika 
         game tersebut tidak ada di dalam daftar game pada
         file konfigurasi default. */
    listgame (*array);
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD();
    int input = WordToInt(currentWord);
    IdxType i = input;
    char* el = array->A[i-1];
    printf("Game yang akan dihapus: %s\n", el);
    if (i > 6 && !IsInQueue(queuegame, el)) {
        DeleteAt(array, i-1);
        printf("Game berhasil dihapus\n");
    }
    else{
        printf("Game gagal dihapus\n");
    }
}