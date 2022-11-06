#include "mesinkar.h"
#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    STARTWORD();
    for (int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
    STARTWORD();
    for (int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    return 0;
}