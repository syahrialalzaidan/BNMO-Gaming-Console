#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
    scanf("%d", &guess);
    while((guess != x) && turn > 0){
        if (guess > x){
            printf("Lebih kecil\n");
        }
        else {
            printf("Lebih besar\n");
        }
        turn--;
        printf("Tebakan: ");
        scanf("%d", &guess);
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
