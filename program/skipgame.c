#include "skipgame.h"

/*
#include <stdio.h>
#include "queue.c"
#include "boolean.h"
#include "mesinkata.c"
#include "mesinkar.c"
#include "arraydin.c"
#include <stdlib.h>
#include "queuegame.c"
#include "playgame.c"
#include "skipgame.h"
*/

void skipgame(Queue *qg, int x, ArrayDin array){
    /*CurrentWord di main
    ADVWORD()
    CurrentWord - '0' */

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
                printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
            }
        } else{
            for (i = 0; i < x; i ++){
                dequeue(qg, &a);
            }
            playgame(qg, array);
        }
    }
    
}

/*
int main(){
    Queue q;
    CreateQueue(&q);
    ArrayDin ss = MakeArrayDin();
    ElType as, bc, cc;
    as = "a";
    bc = "b";
    cc = "c";
    InsertFirst(&ss, as);
    InsertLast(&ss, bc);
    InsertLast(&ss, cc);

    ElType a, b, c;
    a = "RNG";
    b = "DINNER DASH";
    c = "RNG";
    int in;
    in = 2;
    enqueue(&q, a);
    enqueue(&q, b);
    enqueue(&q, c);
    skipgame(&q, 2, ss);
    return 0;
}
*/