#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int rng() {
/* Fungsi RNG bakal ngereturn score yang diperoleh pemain
 * Jumlah maksimal tebakan adalah 5 kali
 * Fullscore adalah 10 dan akan berkurang 20% seiring dengan berkurangnya guess hingga benar
*/
    //Kamus Lokal
    int x = rand() % 30, turn = 4, guess;

    //Algoritma
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    scanf("%d", &guess);
    while((guess != x) && turn > 0){
        if (guess > x){
            printf("Lebih kecil\n");
        }
        else {
            printf("Lebih besar\n");
        }
        turn--;
        scanf("%d", &guess);
    }
    printf("\n");
    if (guess == x){
        printf("Ya, X adalah %d\n", x);
        return (turn+1) * 2;
    }
    else{
        printf("Mohon maaf, kesempatan telah habis.\n");
        return 0;
    }
}

/* driver buat testing
int main(){
    int x = rng();
    printf("Skor : %d\n", x);
}
*/
