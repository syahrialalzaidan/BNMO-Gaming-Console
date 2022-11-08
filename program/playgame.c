#include "playgame.h"

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