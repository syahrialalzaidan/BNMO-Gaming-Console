#include "playgame.h"

boolean isStringSame(char *c1, char*c2){
/* Mengembalikan true jika string sama */
    int i=0;
    while (c1[i] != '\0'){
        if (c1[i] != c2[i]){
            return false;
        }
        i++;
    }
    return true;
}

void play(Queue *qg, ArrayDin array){
/* Memainkan sebuah permainan tanpa menuliskan daftar game
    I.S. Array game tidak mungkin kosong
    F.S. Game yang berada di posisi Head akan dimainkan */
    char* katarng = "RNG";
    char* dinnerdash = "Diner DASH";
    char* tebak = "Tebak Kata";
    char* dinosaur = "DINOSAUR IN EARTH";
    char* rise = "RISEWOMAN";
    char* eiffel = "EIFFEL TOWER";
    char* toh = "Tower of Hanoi";
    char* som = "Snake on Meteor";
    char* hangman = "Hangman";
    char* akinator = "Akinator";

    printf("\n");

    if (isStringSame((*qg).buffer[(*qg).idxHead], katarng)){
        printf("Loading RNG ...\n");
        rng();
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], dinnerdash)){
        printf("Loading Dinner Dash ...\n");
        srand(time(0));
        playdinnerdash();
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], tebak)){
        printf("Loading Tebak Kata ...\n");
        playtebakkata();
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], dinosaur) || isStringSame((*qg).buffer[(*qg).idxHead], rise) || isStringSame((*qg).buffer[(*qg).idxHead], eiffel)){
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", (*qg).buffer[(*qg).idxHead]);
        printf("Silahkan pilih game lain.\n");
    /* } else if(isStringSame((*qg).buffer[(*qg).idxHead], hangman)){
        printf("Loading Hangman ...\n");
        //hangman();
        //playtebakkata();
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], toh)){
        printf("Loading Tower of Hanoi ...\n");
        //towerofhanoi();
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], som)){
        printf("Loading Snake on Meteor ...\n");
        //snakeonmeteor();
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], akinator)){
        printf("Loading Akinator ...\n");
        //akinator();
    */
    } else {
        printf("GAME OVER\n");
        printf("Your score = %d\n", rand()%1000);
    }
    printf("\n");

    ElType a;
    dequeue(qg, &a);
}

void playgame(Queue *qg, ArrayDin array){
/*  Memainkan sebuah permainan.
    I.S. Array game mungkin kosong.
    F.S. Menuliskan daftar game dan game yang berada di posisi Head akan dimainkan. */
    printf("Berikut adalah daftar antrian game-mu:\n");
    if (isEmpty(*qg)){
        printf("\n");
        printf("Antrian game-mu kosong, tambahkan game terlebih dahulu.\n");
        queuegame(qg, array);
    } else{
        printqueue(*qg);
        play(qg, array);
    }
}