#include "tebakkata.h"

void generatemap(Map *kamus){
    Insert(kamus, "mayornaufal", "K01tertampan");
    Insert(kamus, "gibeh", "dinosaurus");
    Insert(kamus, "nikolas", "ahok");
}

int countkata(char *kata){
    int i=0;
    while (kata[i] != '\0'){
        i++;
    }
    return i;
}

boolean isstringequal(char *kata1, char *kata2){
    int i=0;
    if (countkata(kata1) != countkata(kata2)){
        return false;
    }
    while (kata1[i] != '\0'){
        if (kata1[i] != kata2[i]){
            return false;
        }
        i++;
    }
    return true;
}

void playtebakkata(){
    time_t t;
    srand(time(&t));
    Map kamus;
    CreateEmpty(&kamus);
    generatemap(&kamus);
    boolean win = false;
    int angka = rand() % 3;
    printf("Tebak Kata dengan benar!\n");
    printf("Clue : %s\n", Value(kamus, kamus.Elements[angka].Key));
    for(int i=0; i<countkata(kamus.Elements[angka].Key); i++){
        printf("_ ");
    }
    printf("\n");
    printf("Masukkan jawaban : ");
    
    STARTWORD();
    while (! win){
        char *guess;
        guess = WordToString(currentWord);
        while(! IsEOP()) ADVWORD();
        boolean found = false;
        found = isstringequal(guess, kamus.Elements[angka].Key);
        if (found){
            printf("Selamat jawaban anda benar!\n");
            win = true;
        }
        else {
            printf("Jawaban anda salah!\n");
            printf("Masukkan jawaban : ");
            STARTWORD();
        }
    }
}

/*
int main(){
    playtebakkata();
    srand(0);
    return 0;
}
*/