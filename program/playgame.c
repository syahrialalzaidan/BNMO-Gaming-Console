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

void play(Queue *qg, ArrayDin array, float *skor){
/* Memainkan sebuah permainan tanpa menuliskan daftar game
    I.S. Array game tidak mungkin kosong
    F.S. Game yang berada di posisi Head akan dimainkan */
    char* katarng = "RNG";
    char* dinnerdash = "Diner DASH";
    char* tebak = "Tebak Kata";
    char* dinosaur = "DINOSAUR IN EARTH";
    char* rise = "RISEWOMAN";
    char* eiffel = "EIFFEL TOWER";
    char* toh = "TOWER OF HANOI";
    char* som = "SNAKE ON METEOR";
    char* hangmanword = "HANGMAN";
    char* akinator = "Akinator";

    printf("\n");

    if (isStringSame((*qg).buffer[(*qg).idxHead], katarng)){
        printf("Loading RNG ...\n");
        rng(skor);
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], dinnerdash)){
        printf("Loading Dinner Dash ...\n");
        srand(time(0));
        playdinnerdash(skor);
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], tebak)){
        printf("Loading Tebak Kata ...\n");
        playtebakkata(skor);
    // } else if(isStringSame((*qg).buffer[(*qg).idxHead], dinosaur) || isStringSame((*qg).buffer[(*qg).idxHead], rise) || isStringSame((*qg).buffer[(*qg).idxHead], eiffel)){
    //     printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", (*qg).buffer[(*qg).idxHead]);
    //     printf("Silahkan pilih game lain.\n");
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], hangmanword)){
        printf("Loading Hangman ...\n");
        Hangman(skor);
    //     //playtebakkata();
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], toh)){
        printf("Loading Tower of Hanoi ...\n");
        playtowerofhanoi(skor);
    } else if(isStringSame((*qg).buffer[(*qg).idxHead], som)){
        printf("Loading Snake on Meteor ...\n");
        PlaySnakeOnMeteor(skor);
    // } else if(isStringSame((*qg).buffer[(*qg).idxHead], akinator)){
    //     printf("Loading Akinator ...\n");
    //     //srand(time(0));
    //     //akinator();
    
    } else {
        printf("GAME OVER\n");
        srand(time(NULL));
        *skor = rand()%1000;
        printf("Your score = %.0f\n", *skor);
    }
    printf("\n");
    char* temp = HEAD(*qg);
    ElType a;
    dequeue(qg, &a);
}

void playgame(Queue *qg, ArrayDin array, float *skor){
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
        play(qg, array, skor);
    }
}