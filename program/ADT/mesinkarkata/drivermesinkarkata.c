#include "mesinkata.h"
#include<stdio.h>

int main(){
    STARTWORD();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
    if(IsEOP()) printf("EOP\n");
    else printf("Not EOP\n");
    ADVWORD();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
    if(IsEOP()) printf("EOP\n");
    else printf("Not EOP\n");
    ADVWORD();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    if(IsEOP()) printf("EOP\n");
    else printf("Not EOP\n");
    ADVWORD();
    return 0;
}