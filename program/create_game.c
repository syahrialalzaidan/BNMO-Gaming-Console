#include <stdio.h>
#include <stdlib.h>
#include "create_game.h"

char* concat(char* s1, char* s2){
/* Mengembalikan hasil konkatenasi s1 dan s2 */
    int i = 0, j = 0;
    int lenS1 = strLen(s1), lenS2 = strLen(s2);
    char* str = (char*) malloc(100*sizeof(char));
    while (i < lenS1){
        str[i] = s1[i];
        i++;
    }
    str[i] =' ';
    i++;
    while (j < lenS2){
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}

int strLen(char* str) {
/* Mengembalikan panjang string */
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

Word concatword(Word w1, Word w2) {
    int i = 0, j = 0;
    int lenS1 = w1.Length, lenS2 = w2.Length;
    char* str = (char*) malloc((lenS1+lenS2+1)*sizeof(char));
    while (i < lenS1){
        str[i] = w1.TabWord[i];
        i++;
    }
    i++;
    while (j < lenS2){
        str[i] = w2.TabWord[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return stringToWord(str);
}

void creategame (ArrayDin *array, ListMap *scoreboard) {
/*  Menambahkan game baru pada daftar game 
    I.S. Array games terdefinisi dan terisi.
    F.S. Game yang baru ditambahkan jika game belum ada di daftar game. */

    char* string, *string1;
    Word temp;
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    string = WordToString(currentWord);

    while (!IsEOP()) {
        ADVWORD();
        string1 = WordToString(currentWord);
        string = concat(string, string1);
    }
    
    printf("\n");
    
    if (SearchArrayDin(*array, string) == -1)
    {
        printf(" ____ \n");
        printf("|,--.| \n");
        printf("||__||\n");
        printf("|+  o|  Game %s berhasil ditambahkan ^^\n", string);
        printf("|,'o | \n");
        printf("`---- \n");
        InsertLastArray(array, string);
        scoreboard->Neff++;
        CreateEmpty(&scoreboard->Elmt[scoreboard->Neff - 1]);
    }
    else{
        printf("Game telah tersedia\n\n");
    }
}
