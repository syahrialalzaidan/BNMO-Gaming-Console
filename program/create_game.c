#include <stdio.h>
#include <stdlib.h>
#include "create_game.h"

char* concat(char* s1, char* s2){
    int i = 0, j = 0;
    int lenS1 = strLen(s1), lenS2 = strLen(s2);
    char* str = (char*) malloc((lenS1+lenS2+1)*sizeof(char));
    while (i < lenS1){
        str[i] = s1[i];
        i++;
    }
    i++;
    while (j < lenS2){
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}

int strLen(char* str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

Word concatword(Word w1, Word w2){
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

void creategame (ArrayDin *array){
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

    char* string, *string1;
    Word temp;
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    string = WordToString(currentWord);
    ADVWORD();
    string1 = WordToString(currentWord);
    string = concat(string, " ");
    string = concat(string, string1);
    printf("%s", string);
    
    printf("\n");
    // while (!IsEOP()) {
    //     ADVWORD();
    //     string1 = WordToString(currentWord);
    //     string = concat(string, string1);
    //     printf("STRING = %s\n", string);
    // }
    if (SearchArrayDin(*array, string) == -1)
    {
        printf(" ____ \n");
        printf("|,--.| \n");
        printf("||__||\n");
        printf("|+  o|  Game berhasil ditambahkan ^^\n");
        printf("|,'o | \n");
        printf("`---- \n");
        InsertLast(array, string);
    }
    else{
        printf("Game telah tersedia\n\n");
    }

    //printf("Tes %s", string);

    //printf("%d", currentWord.Length);
    
    //printf("Tes %s", (*array).A[(*array).Neff]);
}

// int main()
// {
//     ArrayDin S;
//     S = MakeArrayDin();
//     creategame(&S);
// }