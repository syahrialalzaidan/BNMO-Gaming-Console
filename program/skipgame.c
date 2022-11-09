#include "skipgame.h"

void skipgame(Queue *qg, int x, ArrayDin array){
    if (isEmpty(*qg)){
        queuegame(qg, array);
    } else{
        int j;
        listqueue(qg);
        printf("\n");

        int i;
        ElType a;
        if (x > ((*qg).idxTail - (*qg).idxHead + 1)){
            for (i = 0; i < (*qg).idxTail - (*qg).idxHead + 1; i++){
                dequeue(qg, &a);
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        } else{
            for (i = 0; i < x; i ++){
                dequeue(qg, &a);
            }
            playgame(qg, array);
        }
    }
}  