#include "tebakkata.h"
//gcc 

void generatemap(Map *kamus){
    InsertChar(kamus, "mayornaufal", "K01tertampan");
    InsertChar(kamus, "gibeh", "dinosaurus");
    InsertChar(kamus, "argentina", "messi");
    InsertChar(kamus, "swedia", "negara dengan pulau terbanyak");
    InsertChar(kamus, "alstrukdat", "matkul favorit ariq");
    InsertChar(kamus, "kalimantan", "pulau terbesar di indonesia");
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

void playtebakkata(float *score){
    time_t t;
    srand(time(&t));
    Map kamus;
    CreateEmptyChar(&kamus);
    generatemap(&kamus);
    boolean win = false;
    int angka = rand() % 6;
    printf("Tebak Kata dengan benar! (DALAM HURUF KECIL)\n");
    printf("Clue : %s\n", ValueChar(kamus, kamus.Elements[angka].Key));
    int n = 0;
    for(int i=0; i < countkata(kamus.Elements[angka].Key); i++){
        printf("_ ");
        n++;
    }
    printf("(%d huruf)", n);
    printf("\n");
    printf("Masukkan jawaban : ");
    int count = 9;
    STARTWORD();
    while (! win && count > 0){
        char *guess;
        guess = WordToString(currentWord);
        while(! IsEOP()) ADVWORD();
        boolean found = false;
        found = isstringequal(guess, kamus.Elements[angka].Key);
        if (found){
            printf("Selamat jawaban anda benar!\n");
            printf("Anda mendapatkan %d poin!\n", count+1);
            *score += (count+1);
            win = true;
        }
        else {
            printf("Jawaban anda salah!\n");
            printf("Tries remaining : %d\n", count);
            for(int i=0; i < countkata(kamus.Elements[angka].Key); i++){
                printf("_ ");
            }
            printf("(%d huruf)", n);
            printf("\n");
            printf("Masukkan jawaban : ");
            STARTWORD();
        }
        count--;
        
    }
    if (! win) printf("Mohon maaf, kesempatan habis.\nJawaban benar: %s\n",kamus.Elements[angka].Key);
}

/*
int main(){
    playtebakkata();
    srand(0);
    return 0;
}
*/
