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

void play(Queue *qg, ArrayDin array, float *skor, boolean *play){
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
    if (isStringSame(katarng, (*qg).buffer[(*qg).idxHead])){
        printf("Loading RNG ...\n");
        rng(skor);
    } else if(isStringSame(dinnerdash, (*qg).buffer[(*qg).idxHead])){
        printf("Loading Dinner Dash ...\n");
        srand(time(0));
        playdinnerdash(skor);
    } else if(isStringSame(tebak, (*qg).buffer[(*qg).idxHead])){
        printf("Loading Tebak Kata ...\n");
        playtebakkata(skor);
    // } else if(isStringSame((*qg).buffer[(*qg).idxHead], dinosaur) || isStringSame((*qg).buffer[(*qg).idxHead], rise) || isStringSame((*qg).buffer[(*qg).idxHead], eiffel)){
    //     printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", (*qg).buffer[(*qg).idxHead]);
    //     printf("Silahkan pilih game lain.\n");
    } else if(isStringSame(hangmanword,(*qg).buffer[(*qg).idxHead])){
        printf("Loading Hangman ...\n");
        Hangman(skor, play);
    //     //playtebakkata();
    } else if(isStringSame(toh, (*qg).buffer[(*qg).idxHead])){
        printf("Loading Tower of Hanoi ...\n");
        playtowerofhanoi(skor, play);
    } else if(isStringSame(som, (*qg).buffer[(*qg).idxHead])){
        printf("Loading Snake on Meteor ...\n");
        PlaySnakeOnMeteor(skor);
    } else if(isStringSame(akinator, (*qg).buffer[(*qg).idxHead])){
        printf("Loading Akinator ...\n");
        srand(time(0));
        playakinator(skor);
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

void playgame(Queue *qg, ArrayDin array, float *skor, boolean *found){
/*  Memainkan sebuah permainan.
    I.S. Array game mungkin kosong.
    F.S. Menuliskan daftar game dan game yang berada di posisi Head akan dimainkan. */
    if (HEAD(*qg) != NULL) printf("Berikut adalah daftar antrian game-mu:\n");
    if (isEmpty(*qg)){
        printf("\n");
        printf("Antrian game-mu kosong, tambahkan game terlebih dahulu.\n");
        queuegame(qg, array);
        *found = false;
    } else{
        printqueue(*qg);
        *found = true;
        play(qg, array, skor, found);
    }
}