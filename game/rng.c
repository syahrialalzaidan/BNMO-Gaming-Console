#include"rng.h"


void rng(float *score) {
/* Fungsi RNG bakal ngereturn score yang diperoleh pemain
 * Jumlah maksimal tebakan adalah 10 kali
 * Fullscore adalah 10 dan akan berkurang 10% seiring dengan berkurangnya guess hingga benar
*/
    //Kamus Lokal
    time_t t;
    srand(time(&t));
    int x = rand() % 30, guess;
    float turn = 9;

    //Algoritma
    printf("______ _   _ _____ \n");
    printf("| ___ \\ \\ | |  __ \\ \n");
    printf("| |_/ /  \\| | |  \\/ \n");
    printf("|    /| . ` | | __ \n");
    printf("| |\\ \\| |\\  | |_\\ \\ \n");
    printf("\\_| \\_\\_| \\_/\\____/\n");
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    STARTWORD();
    guess = WordToInt(currentWord);
    while((guess != x) && turn > 0){
        if (guess > x) printf("Lebih kecil\n");
        
        else printf("Lebih besar\n");
        turn--;
        printf("Tebakan: ");
        STARTWORD();
        guess = WordToInt(currentWord);
    }
    printf("\n");
    if (guess == x){
        printf("Ya, X adalah %d\n", x);
        printf("Skor Anda: %.0f\n", turn + 1);
    } else printf("Mohon maaf, kesempatan telah habis.\n");
    *score = (turn + 1);
}

// driver buat testing
/*
int main(){
    float score = 0;
    rng(&score);
    printf("%.0f", score);
    return 0;
}
*/

