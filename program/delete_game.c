#include <stdio.h>
#include "delete_game.h"

boolean findatqueue(Queue queuegame, char* string){
/*I.S. Queue game mungkin kosong*/
/*F.S. Elemen queue ditemukan atau tidak*/
    char* temp;
    dequeue(&queuegame, &temp);
    while (temp != string && !isEmpty(queuegame))
    {   
        dequeue(&queuegame, &temp);
    }
    return temp == string;
}

void deletegame(ArrayDin *array, Queue queuegame){
/*I.S. Array game mungkin kosong*/
/*F.S. Asumsi nomor game input pasti valid. Nomor games yang ingin dihapus telah hilang dari array*/
    listgame (*array);
    printf("Masukkan nomor game yang akan dihapus: ");
    START();
    char input = currentChar - '0';
    IdxType i = input;
    if (i > 5 && findatqueue(queuegame, (*array).A[i])){
        DeleteAt(array, i-1);
        printf("Game berhasil dihapus");
    }
    else{
        printf("Game gagal dihapus");
    }
}