#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "mesinkar.h"
#include "mesinkata.h"

int wordtoint(Word kata){
    int i = 0;
    int hasil = 0;
    while(i < kata.Length){
        hasil = hasil * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return hasil;
}

int rng() {
/* Fungsi RNG bakal ngereturn score yang diperoleh pemain
 * Jumlah maksimal tebakan adalah 5 kali
 * Fullscore adalah 10 dan akan berkurang 20% seiring dengan berkurangnya guess hingga benar
*/
    //Kamus Lokal
    time_t t;
    srand(time(&t));
    int x = rand() % 30, turn = 9, guess;

    //Algoritma
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    
    STARTWORD();
    guess = wordtoint(currentWord);
    while((guess != x) && turn > 0){
        if (guess > x){
            printf("Lebih kecil\n");
        }
        else {
            printf("Lebih besar\n");
        }
        turn--;
        printf("Tebakan: ");
        STARTWORD();
        guess = wordtoint(currentWord);
    }

    printf("\n");
    if (guess == x){
        printf("Ya, X adalah %d\n", x);
        return (turn+1);
    }
    else{
        printf("Mohon maaf, kesempatan telah habis.\n");
        return 0;
    }
}

// driver buat testing
int main(){
    int x = rng();
    printf("Skor : %d\n", x);
}
