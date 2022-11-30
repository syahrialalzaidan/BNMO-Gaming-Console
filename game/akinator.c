#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "akinator.h"

boolean isStringSameakin(char *c1, char*c2){
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

void namahewan(char* file,char* hewan[41]){
    LoadPitaAkin("DataAkinator/hewan.txt", true);
    STARTWORDakin();
    hewan[0] = WordToStringakin(currentWord);
    int i;
    for (i = 1; i < 41; i++){
        ADVWORDakin();
        hewan[i] = WordToStringakin(currentWord);
    }
}

void jawab(char* file, char* jawaban[41], int nomer[41]){
    LoadPitaAkin("DataAkinator/jawaban.txt", true);
    STARTWORDakin();
    jawaban[0] = WordToStringakin(currentWord);
    nomer[0] = currentWord.Length;
    int i;
    for (i = 1; i < 41; i++){
        ADVWORDakin();
        jawaban[i] = WordToStringakin(currentWord);
        nomer[i] = currentWord.Length;
    }
}

void printakinator(){
    printf("  /$$$$$$  /$$       /$$                       /$$                        \n");
    printf(" /$$__  $$| $$      |__/                      | $$                        \n");
    printf("| $$  \$$| $$   /$$ /$$ /$$$$$$$   /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ \n");
    printf("| $$$$$$$$| $$  /$$/| $$| $$__  $$ |____  $$|_  $$_/   /$$__  $$ /$$__  $$\n");
    printf("| $$__  $$| $$$$$$/ | $$| $$  \ $$  /$$$$$$$  | $$    | $$  \ $$| $$  \__/\n");
    printf("| $$  | $$| $$_  $$ | $$| $$  | $$ /$$__  $$  | $$ /$$| $$  | $$| $$      \n");
    printf("| $$  | $$| $$ \\$$| $$| $$  | $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$      \n");
    printf("|__/  |__/|__/  \\__/|__/|__/  |__/ \_______/   \___/   \______/ |__/     \n\n");
}

void playakinator(float *score){
    printakinator();

    LoadPitaAkin("./DataAkinator/akinator.txt", true);
    STARTWORDakin();

    Tree pohon, root, akinator;
    addresst p, pp, ppp;
    int stop = 0;

    CreateTree(&pohon, p);
    CreateTree(&root, pp);
    CreateTree(&akinator, ppp);
    BuildTree(&pohon, &root, stop);
    akinator = root;

    char* hewan[41];
    char* jawaban[41];
    int panjangjawaban[41];
    namahewan("DataAkinator/hewan.txt", hewan);
    jawab("DataAkinator/jawaban.txt", jawaban, panjangjawaban);

    time_t t;
    srand(time(&t));
    int idx = rand() % 40;

    int x;
    char* tebakan = hewan[idx];
    int kode = atoi(jawaban[idx]);
    int kodeA = kode;

    boolean valid = true;
    int sum = 0;

    printf("Hewan yang kamu harus tebak adalah %s\n", tebakan);
    while ((RIGHT(akinator) != NILakin) && (valid)){
        // char* input;
        char* Y = "y";
        char* N = "n";
        // int input;
        printf("%s\n", INFO(*akinator));
        printf("Yes (y) / No (n): ");
        isFileakin = false;
        STARTWORDakin();
        char* input = WordToStringakin(currentWord);
        //scanf("%d", &input);

        while (((!isStringSameakin(Y, input)) && (!isStringSameakin(N, input))) || (currentWord.Length != 1)){
            printf("\n");
            printf("Jawaban yang diterima hanya y atau n\n\n");
            printf("Hewan yang kamu harus tebak adalah %s\n", tebakan);
            printf("%s\n", INFO(*akinator));
            printf("Yes (y) / No (n): ");
            //scanf("%d", &input);
            STARTWORDakin();
            input = WordToStringakin(currentWord);
        }

        kodeA = kode%10;
        kode = kode/10;

        if (isStringSameakin(input, Y)){
            root = RIGHT(akinator);
            akinator = root;
            x = 1;
        } else if (isStringSameakin(input, N)){
            root = LEFT(akinator);
            akinator = root;
            x = 0;
        }

        if (kodeA != x){
            valid = false;
        } else{
            sum++;
        }
    }

    char* jawab;
    float hasil, ssum, pj;
    ssum = sum;
    pj = panjangjawaban[idx];
    jawab = INFO(*akinator);
    hasil = (ssum/pj) * 100;

    printf("Jawaban kamu ");
    if (isStringSameakin(tebakan, jawab)){
        printf("benar semua\n");
        printf("Skor: %d\n", hasil);
    } else{
        printf("salah\n");
        printf("Skor: %d\n", hasil);
    }

    *score = hasil;
   
   /*
    printf("%s\n", INFO(*akinator));
    akinator = RIGHT(akinator);
    printf("%s\n", INFO(*akinator));
    akinator = LEFT(akinator);
    printf("%s\n", INFO(*akinator));
    akinator = RIGHT(akinator);
    printf("%s\n", INFO(*akinator));
    akinator = LEFT(akinator);
    printf("%s\n", INFO(*akinator));
    akinator = RIGHT(akinator);
    printf("%s\n", INFO(*akinator));
    */
}