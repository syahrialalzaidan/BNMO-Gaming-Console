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

void namahewan(char* hewan[41]){
    LoadPitaAkin("./game/DataAkinator/hewan.txt", true);
    STARTWORDakin();
    hewan[0] = WordToStringakin(currentWordakin);
    int i;
    for (i = 1; i < 41; i++){
        ADVWORDakin();
        hewan[i] = WordToStringakin(currentWordakin);
    }
}

void jawab(char* jawaban[41], int nomer[41]){
    LoadPitaAkin("./game/DataAkinator/jawaban.txt", true);
    STARTWORDakin();
    jawaban[0] = WordToStringakin(currentWordakin);
    nomer[0] = currentWordakin.Length;
    int i;
    for (i = 1; i < 41; i++){
        ADVWORDakin();
        jawaban[i] = WordToStringakin(currentWordakin);
        nomer[i] = currentWordakin.Length;
    }
}

void printakinator(){
    printf("  /$$$$$$  /$$       /$$                       /$$                        \n");
    printf(" /$$__  $$| $$      |__/                      | $$                        \n");
    printf("| $$  \ $$| $$   /$$ /$$ /$$$$$$$   /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ \n");
    printf("| $$$$$$$$| $$  /$$/| $$| $$__  $$ |____  $$|_  $$_/   /$$__  $$ /$$__  $$\n");
    printf("| $$__  $$| $$$$$$/ | $$| $$  \ $$  /$$$$$$$  | $$    | $$  \ $$| $$  \__/\n");
    printf("| $$  | $$| $$_  $$ | $$| $$  | $$ /$$__  $$  | $$ /$$| $$  | $$| $$      \n");
    printf("| $$  | $$| $$ \  $$| $$| $$  | $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$      \n");
    printf("|__/  |__/|__/  \__/|__/|__/  |__/ \_______/   \___/   \______/ |__/     \n\n");
}

void playakinator(float *skor){
    printakinator();

    LoadPitaAkin("./game/DataAkinator/akinator.txt", true);
    // LoadPitaAkin("C:/Users/Iskandar/Documents/GitHub/TUBES-ALSTRUKDAT-KELOMPOK-10/game/DataAkinator/akinator.txt", true);
    //char* filepathakin = "akinator.txt";
    //isFileakin = true;
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
    namahewan(hewan);
    jawab(jawaban, panjangjawaban);

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
        char* input = WordToStringakin(currentWordakin);
        //scanf("%d", &input);

        while (((!isStringSameakin(Y, input)) && (!isStringSameakin(N, input))) || (currentWordakin.Length != 1)){
            printf("\n");
            printf("\nJawaban yang diterima hanya y atau n\n\n");
            printf("Hewan yang kamu harus tebak adalah %s\n", tebakan);
            printf("%s\n", INFO(*akinator));
            printf("Yes (y) / No (n): ");
            //scanf("%d", &input);
            STARTWORDakin();
            input = WordToStringakin(currentWordakin);
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
        printf("Skor: %f\n", hasil);
    } else{
        printf("salah\n");
        printf("Skor: %f\n", hasil);
    }
    *skor = hasil;
   
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