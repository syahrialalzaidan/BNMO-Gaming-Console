#include "playgame.h"
/*
#include <stdio.h>
#include "queue.c"
#include "boolean.h"
#include "mesinkata.c"
#include "mesinkar.c"
#include "arraydin.c"
#include <stdlib.h>
#include "queuegame.c"
#include "playgame.h"
*/

void playgame(Queue *qg, ArrayDin array){
    printf("Berikut adalah daftar game-mu\n");
    if (!isEmpty(*qg)){
        listqueue(qg);
    }

    if (isEmpty(*qg)){
        queuegame(qg, array);
    } else{
        char* rng = "RNG";
        char* dinnerdash = "DINNER DASH";
        char* tictactoe = "TIC TAC TOE";
        int i;
        printf("\n");

        if ((*qg).buffer[(*qg).idxHead] == rng){
            printf("Loading RNG ...");
            /*
            rng();
            */
            printf("rng()");
        } else if((*qg).buffer[(*qg).idxHead] == dinnerdash){
            printf("Loading Dinner Dash ...");
            /* 
            srand(time(0));
            playdinnerdash();
            */
            printf("dinner dash");
        } else if((*qg).buffer[(*qg).idxHead] == tictactoe){
            printf("Loading Tic-Tac-Toe");
            /*
            playtictactoe;
            */
            printf("tictactoe");
        } else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", (*qg).buffer[(*qg).idxHead]);
            printf("Silahkan pilih game lain.\n");
        }
        printf("\n");

        ElType a;
        dequeue(qg, &a);
    }
}

/*
int main(){
    Queue q;
    CreateQueue(&q);
    ArrayDin a = MakeArrayDin();
    ElType as, bc, cc;
    as = "a";
    bc = "b";
    cc = "c";
    InsertFirst(&a, as);
    InsertLast(&a, bc);
    InsertLast(&a, cc);

    ElType y, b, c;
    
    y = "RNG";
    b = "DINNER DASH";
    c = "LALALA";'

    enqueue(&q, y);
    enqueue(&q, b);

    enqueue(&q, c);
    playgame(&q, a);
    return 0;
}
*/