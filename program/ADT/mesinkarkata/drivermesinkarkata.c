#include "mesinkata.h"
#include<stdio.h>

int main(){
    STARTWORD();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
    ADVWORD();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
    ADVWORD();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    return 0;
}