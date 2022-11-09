#include "playgame.h"

boolean isStringSame(char *c1, char*c2){
    int i=0;
    while (c1[i] != '\0'){
        if (c1[i] != c2[i]){
            return false;
        }
        i++;
    }
    return true;
}
void playgame(Queue *qg, ArrayDin array){
    printf("Berikut adalah daftar game-mu\n");
    if (!isEmpty(*qg)){
        listqueue(qg);
    }

    if (isEmpty(*qg)){
        queuegame(qg, array);
    } else{
        char* katarng = "RNG";
        char* dinnerdash = "Diner DASH";
        char* tebak = "Tebak Kata";
        int i;
        printf("\n");

        if (isStringSame((*qg).buffer[(*qg).idxHead], katarng)){
            printf("Loading RNG ...\n");
            rng();
        } else if(isStringSame((*qg).buffer[(*qg).idxHead], dinnerdash)){
            printf("Loading Dinner Dash ...\n");
            srand(time(0));
            playdinnerdash();
            
            printf("dinner dash");
        } else if(isStringSame((*qg).buffer[(*qg).idxHead], tebak)){
            printf("Loading Tebak Kata\n");
            playtebakkata();
        } else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", (*qg).buffer[(*qg).idxHead]);
            printf("Silahkan pilih game lain.\n");
        }
        printf("\n");

        ElType a;
        dequeue(qg, &a);
    }
}