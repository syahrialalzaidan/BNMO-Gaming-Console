#include "towerofhanoi.h"
//gcc -o coba towerofhanoi.c ../program/ADT/StackHanoi/stackhanoi.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c

void printblank(int n){
// I.S. n terdefinisi
// F.S. n spasi tercetak
    for (int i = 0; i < n; i++) printf(" ");
}

void printbintang(int n){
/* I.S. n terdefinisi
 * F.S. n bintang tercetak
 */
    for (int i = 0; i < n; i++) printf("*");
}

float optimummove(int n){
// menghasilkan jumlah langkah minimum untuk menyelesaikan tower of hanoi dengan n disk
    int i = 1;
    for (int j = 1; j < n; j++) {
        i *= 2;
        i++;
    }
    return i;
}

boolean isAngka(Word W){
// menghasilkan true jika W merupakan kata yang terdiri dari angka saja
    int i = 0;
    boolean output = true;
    while (i < W.Length && output){
        if (W.TabWord[i] < '0' || W.TabWord[i] > '9') output = false;
        i++;
    }
    return output;
}

void displaytower(int n, Stack tower1, Stack tower2, Stack tower3){
//Menampilkan tower of hanoi dengan n disk
    for(int i = 0; i < n; i++) {
        int value1 = tower1.T[n-i-1], value2 = tower2.T[n-i-1], value3 = tower3.T[n-i-1];
        if (value1 != 0){
            printblank(n - value1);
            printbintang(value1 * 2 - 1);
            printblank(n - value1);
        }
        else {
            printblank(n - value1 -1);
            printf("|");
            if (n % 4 != 0) printblank(n-value1);
            else printblank(n-value1-1);
        }
        printf("\t");
        if (n % 4 ==0) printf("\t");
        if (value2 != 0){
            printblank(n - value2 +1);
            printbintang(value2 * 2 - 1);
            printblank(n - value2);
        }
        else {
            printblank(n - value2);
            printf("|");
            printblank(n-value2);
        }
        printf("\t");
        if (value3 != 0){
            printblank(n - value3+1);
            printbintang(value3 * 2 - 1);
            printblank(n - value3);
        }
        else {
            printblank(n - value3);
            printf("|");
            printblank(n-value3);
        }
        printf("\n");
    }
    printblank(n -1);
    printf("A");
    printblank(n);
    printf("\t");
    printblank(n);
    printf("B");
    printblank(n);
    printf("\t");
    printblank(n);
    printf("C");
    printblank(n);
    printf("\n\n");
}

void printart(){
//Menampilkan gambar art tower of hanoi
    printf("  _____                          __   _  _               _ \n");
    printf(" |_   _|____ __ _____ _ _   ___ / _| | || |__ _ _ _  ___(_)\n");
    printf("   | |/ _ \\ V  V / -_) '_| / _ \\  _| | __ / _` | ' \\/ _ \\ |\n");
    printf("   |_|\\___/\\_/\\_/\\___|_|   \\___/_|   |_||_\\__,_|_||_\\___/_|\n\n");
}

void gameover(){
//Menampilkan gambar art game over
    printf("  _ _  _____          __  __ ______    ______      ________ _____    _ _ \n");
    printf(" | | |/ ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\  | | |\n");
    printf(" | | | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | | | |\n");
    printf(" | | | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /  | | |\n");
    printf(" | | | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\  | | |\n");
    printf(" | | |\\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ | | |\n");
    printf(" |_|_|                                                              |_|_|\n\n");
}


void playtowerofhanoi(float *score, boolean *play){
//Memainkan game tower of hanoi
    Stack tower1, tower2, tower3, temp;
    int temp1, temp2, info1, info2, info3;
    float count = 0, optimal, n;
    boolean valid = false;
    printart();
    CreateEmptyHanoi(&tower1);
    setNol(&tower1);
    CreateEmptyHanoi(&tower2);
    setNol(&tower2);
    CreateEmptyHanoi(&tower3);
    setNol(&tower3);
    while(!valid){
        printf("Masukkan jumlah piringan: ");
        STARTWORD();
        valid = isAngka(currentWord);
        if (currentWord.Length < 1 || WordToInt(currentWord) == 0) valid = false;
        n = WordToInt(currentWord);
        optimal = optimummove(n);
        if(! IsEOP()) valid = false;
        if (!valid) printf("MASUKAN SALAH!\n");
        while(! IsEOP()) ADVWORD();
    }
    printf("\n");
    while(! IsEOP()) ADVWORD();
    for(int i = n; i > 0; i--){
        PushHanoi(&tower1, i);
        PushHanoi(&tower2, 0);
        PushHanoi(&tower3, 0);
    }
    temp = tower1;
    printf("Menyiapkan tower of hanoi.");
    printf(" .");
    printf(" .\n");
    clear();
    printf("Ketik 'Q' untuk keluar dari permainan\n\n");
    displaytower(n, tower1, tower2, tower3);
    while(! isStackSama(tower3, temp)){
        printf("TOWER ASAL: ");
        STARTWORD();
        if (currentWord.TabWord[0] == 'Q' && currentWord.Length == 1) break;
        temp1 = WordConverter(currentWord);
        if(currentWord.Length != 1) temp1 = 9;
        if(! IsEOP()) temp1 = 9;
        ADVWORD();
        while(! IsEOP()) ADVWORD();
        printf("TOWER TUJUAN: ");
        STARTWORD();
        printf("\n");
        if (currentWord.TabWord[0] == 'Q' && currentWord.Length == 1) break;
        temp2 = WordConverter(currentWord);
        if(currentWord.Length != 1) temp2 = 9;
        if (! IsEOP()) temp2 = 9;
        ADVWORD();
        while(! IsEOP()) ADVWORD();
        info1 = InfoTop(tower1);
        info2 = gettop(tower2);
        info3 = gettop(tower3);

        if (temp1 == 1 && info1 != 0){
            if (temp2 == 2){
                if (info1 < info2 || info2 == 0){
                    PopHanoi(&tower1, &temp1);
                    PushHanoi(&tower2, temp1);
                    count++;
                    printf("Memindahkan ke tower B . ");
                    printf(". ");
                    printf(".\n\n");
                    clear();
                    displaytower(n, tower1, tower2, tower3);
                }
                else printf("Tidak bisa dipindahkan!!\n\n");
            }
            else if (temp2 == 3){
                if (info1 < info3 || info3 == 0){
                    PopHanoi(&tower1, &temp1);
                    PushHanoi(&tower3, temp1);
                    count++;
                    printf("Memindahkan ke tower C . ");
                    printf(". ");
                    printf(".\n\n");
                    clear();
                    displaytower(n, tower1, tower2, tower3);
                }
                else printf("Tidak bisa dipindahkan!!\n\n");
            }
            else printf("Input INVALID!\n\n");
        }
        else if (temp1 == 2 && info2 != 0){
            if (temp2 == 1){
                if (info2 < info1 || info1 == 0){
                    PopHanoi(&tower2, &temp1);
                    PushHanoi(&tower1, temp1);
                    count++;
                    printf("Memindahkan ke tower A . ");
                    printf(". ");
                    printf(".\n\n");
                    clear();
                    displaytower(n, tower1, tower2, tower3);
                }
                else printf("Tidak bisa dipindahkan!!\n\n");
                
            }
            else if (temp2 == 3){
                if (info2 < info3 || info3 == 0){
                    PopHanoi(&tower2, &temp1);
                    PushHanoi(&tower3, temp1);
                    count++;
                    printf("Memindahkan ke tower C . ");
                    printf(". ");
                    printf(".\n\n");
                    clear();
                    displaytower(n, tower1, tower2, tower3);
                }
                else printf("Tidak bisa dipindahkan!!\n\n");
            }
            else printf("Input INVALID!\n\n");
        }
        else if (temp1 == 3 && info3 != 0){
            if (temp2 == 1){
                if (info3 < info1 || info1 == 0){
                    PopHanoi(&tower3, &temp1);
                    PushHanoi(&tower1, temp1);
                    count++;
                    printf("Memindahkan ke tower A . ");
                    printf(". ");
                    printf(".\n\n");
                    clear();
                    displaytower(n, tower1, tower2, tower3);
                }
                else printf("Tidak bisa dipindahkan!!\n\n");
                
            }
            else if (temp2 == 2){
                if (info3 < info2 || info2 == 0){
                    PopHanoi(&tower3, &temp1);
                    PushHanoi(&tower2, temp1);
                    count++;
                    printf("Memindahkan ke tower B . ");
                    printf(". ");
                    printf(".\n\n");
                    clear();
                    displaytower(n, tower1, tower2, tower3);
                }
                else printf("Tidak bisa dipindahkan!!\n\n");
            }
            else printf("Input INVALID!\n\n");
        }
        else printf("Input INVALID!\n\n");
    }
    
    *score = ((optimal / count) * 10 * (n/5));
    if (count >= optimal){
        gameover();
        printf("Selamat Anda berhasil menyelesaikan permainan ini!!\n");
        printf("Skor : %.2f\n", *score);
        *play = true;
    }
    else {
        gameover();
        printf("Kok nyerah??\n");
        *play = false;
    }
}

/* Driver
int main() {
    float x = 0;
    playtowerofhanoi(&x);
    printf("Skor akhir : %.2f\n", x);
    return 0;
}
*/