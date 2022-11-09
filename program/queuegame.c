#include "queuegame.h"

void queuegame(Queue *queuegame, ArrayDin array){
    int x;
    printf("Berikut adalah daftar antrian game-mu\n");
    if (!isEmpty(*queuegame)){
        listqueue(queuegame);
    }
    printf("\n");

    listgame(array);
    printf("\n");

    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTWORD();
    x = currentWord.TabWord[0] - '0';
    printf("\n");
    if ((x > array.Neff) || (x < 1)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    } else{
        enqueue(queuegame, array.A[x - 1]);
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}

void listqueue(Queue *queuegame){
    int i;
    for (i = (*queuegame).idxHead; i < (*queuegame).idxTail + 1; i++){
        printf("%d. %s\n", i+1,(*queuegame).buffer[i]);
    }
}