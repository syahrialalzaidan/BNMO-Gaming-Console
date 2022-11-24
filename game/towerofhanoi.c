#include "towerofhanoi.h"
//gcc -o coba towerofhanoi.c ../program/ADT/Stack/stack.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c
// 

void printblank(int n){
    for (int i = 0; i < n; i++) printf(" ");
}

void printbintang(int n){
    for (int i = 0; i < n; i++) printf("*");
}

float optimummove(int n){
    int i = 1;
    for (int j = 1; j < n; j++) {
        i *= 2;
        i++;
    }
    return i;
}

boolean isAngka(Word W){
    int i = 0;
    boolean output = true;
    while (i < W.Length && output){
        if (W.TabWord[i] < '0' || W.TabWord[i] > '9') output = false;
        i++;
    }
    return output;
}

void displaytower(int n, Stack tower1, Stack tower2, Stack tower3){
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

float playtowerofhanoi(){
    Stack tower1, tower2, tower3, temp;
    int temp1, temp2, info1, info2, info3;
    float skor, count = 0, optimal;
    boolean valid = false;

    CreateEmpty(&tower1);
    setNol(&tower1);
    CreateEmpty(&tower2);
    setNol(&tower2);
    CreateEmpty(&tower3);
    setNol(&tower3);
    while(!valid){
        printf("Masukkan jumlah piringan: ");
        STARTWORD();
        valid = isAngka(currentWord);
        if (currentWord.Length < 1 || WordToInt(currentWord) == 0) valid = false;
        if (!valid) printf("MASUKAN SALAH!\n");
        while(! IsEOP()) ADVWORD();
    }
    printf("\n");
    float n;
    n = WordToInt(currentWord);
    optimal = optimummove(n);
    while(! IsEOP()) ADVWORD;
    for(int i = n; i > 0; i--){
        Push(&tower1, i);
        Push(&tower2, 0);
        Push(&tower3, 0);
    }
    temp = tower1;
    while(! isStackSama(tower3, temp)){
        displaytower(n, tower1, tower2, tower3);
        printf("TOWER ASAL: ");
        STARTWORD();
        temp1 = WordConverter(currentWord);
        if(currentWord.Length != 1) temp1 = 9;
        ADVWORD();
        if(! IsEOP()) temp1 = 9;
        while(! IsEOP()) ADVWORD();
        printf("TOWER TUJUAN: ");
        STARTWORD();
        printf("\n");
        temp2 = WordConverter(currentWord);
        if(currentWord.Length != 1) temp2 = 9;
        ADVWORD();
        if (! IsEOP()) temp2 = 9;
        while(! IsEOP()) ADVWORD();
        info1 = InfoTop(tower1);
        info2 = gettop(tower2);
        info3 = gettop(tower3);

        if (temp1 == 1 && info1 != 0){
            if (temp2 == 2){
                if (info1 < info2 || info2 == 0){
                    Pop(&tower1, &temp1);
                    Push(&tower2, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan!!\n");
            }
            else if (temp2 == 3){
                if (info1 < info3 || info3 == 0){
                    Pop(&tower1, &temp1);
                    Push(&tower3, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan!!\n");
            }
            else printf("Input INVALID!\n");
        }
        else if (temp1 == 2 && info2 != 0){
            if (temp2 == 1){
                if (info2 < info1 || info1 == 0){
                    Pop(&tower2, &temp1);
                    Push(&tower1, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan!!\n");
                
            }
            else if (temp2 == 3){
                if (info2 < info3 || info3 == 0){
                    Pop(&tower2, &temp1);
                    Push(&tower3, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan!!\n");
            }
            else printf("Input INVALID!\n");
        }
        else if (temp1 == 3 && info3 != 0){
            if (temp2 == 1){
                if (info3 < info1 || info1 == 0){
                    Pop(&tower3, &temp1);
                    Push(&tower1, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan!!\n");
                
            }
            else if (temp2 == 2){
                if (info3 < info2 || info2 == 0){
                    Pop(&tower3, &temp1);
                    Push(&tower2, temp1);
                    count++;
                }
                else printf("Tidak bisa dipindahkan!!\n");
            }
            else printf("Input INVALID!\n");
        }
        else printf("Input INVALID!\n");
    }
    displaytower(n, tower1, tower2, tower3);
    printf("Selamat anda berhasil menyelesaikan permainan ini!!\n");
    printf("Skor : %.2f\n", (optimal / count) * 10 * (n/5));
    return ((optimal / count) * 10 * (n/5));
}

int main() {
    float x = playtowerofhanoi();
    printf("%.2f\n", x);
    return 0;
}