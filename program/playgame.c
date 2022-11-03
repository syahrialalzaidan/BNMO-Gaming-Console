#include <stdio.h>
#include "queue.h"

void playgame(Queue *queuegame){
    printf("Berikut adalah daftar game-mu\n");
    if (isEmpty(*queuegame)){
        queuegame();
    } else{
        char *rng = "RNG";
        char *dinnerdash = "Dinner Dash";
        char *... = "...";
        int i;
        for (i = (*queuegame).idxHead; i < (*queuegame).idxTail + 1; i++){
            printf("%s\n", (*queuegame).buffer[i]);
        }
        printf("\n");
        if ((*queuegame).buffer[(*queuegame).idxHead] == "RNG"){
            printf("Loading RNG ...");
            playrng;
        } else if((*queuegame).buffer[(*queuegame).idxHead] == "Dinner Dash"){
            printf("Loading Dinner Dash ...");
            playdinnerdash;
        } else if((*queuegame).buffer[(*queuegame).idxHead] == "..."){
            printf("Loading ... ...");
            play ...;
        } else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", (*queuegame).buffer[(*queuegame).idxHead]);
            printf("Silahkan pilih game lain.\n");
        }
        printf("\n");
        ElType a;
        dequeue(queuegame, &a);
    }
