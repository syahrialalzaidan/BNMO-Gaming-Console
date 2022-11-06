#include <stdio.h>
#include "queue.h"
#include "arraydin.h"

void queuegame(Queue *queuegame, ArrayDin array){
    int i, j, x;
    printf("Berikut adalah daftar antrian game-mu\n")
    if (!isEmpty(*queuegame)){
        for (i = (*queuegame).idxHead; i < (*queuegame).idxTail + 1; i++){
            printf("%s\n", (*queuegame).buffer[i]);
        }
    }
    printf("\n");
    listgame(array);
    printf("\n");
    scanf("Nomor Game yang mau ditambahkan ke antrian : %d", &x);
    /*gaboleh scanf, pake stdin, fscanf*/
    printf("\n");
    if ((x > array.Neff) || (x < 1)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n")
    } else{
        enqueue(*queuegame, array.A[x - 1]);
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}