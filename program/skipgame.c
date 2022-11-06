#include <stdio.h>
#include "queue.h"

void skipgame(Queue *queuegame){
    /* mengambil nomor akhir x*/
    if (isEmpty(*queuegame)){
        queuegame();
    } else{
        int j;
        for (j = (*queuegame).idxHead; j < (*queuegame).idxTail + 1; j++){
            printf("%s\n", (*queuegame).buffer[j]);
        }
        printf("\n");

        int i;
        Eltype a;
        if (x > ((*queuegame).idxTail - (*queuegame).idxHead + 1)){
            for (i = 0; i < (*queuegame).idxTail - (*queuegame).idxHead + 1; i++){
                dequeue(*queuegame, &a);
                printf("Tidak ada permainan lagi dalam daftar game-mu.\n")
            }
        } else{
            for (i = 0; i < x; i ++){
                dequeue(*queuegame, &a);
            }
            playgame();
        }
    }
    
}