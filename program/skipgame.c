#include "skipgame.h"

void skipgame(Queue *qg, int x, ArrayDin array) {
/*  Melewatkan permainan sebanyak n.
    I.S. Array game tidak mungkin kosong.
         Queue game mungkin kosong.
    F.S. Jika game ke-(n+1) ada di dalam queue, sistem akan 
            memainkan game ke-(n+1) pada queue.
         Jika game ke-(n+1) tidak terdefinisi, maka queue akan kosong. */
    if (isEmpty(*qg)){
        queuegame(qg, array);
    } else{
        int j;
        printqueue(*qg);
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