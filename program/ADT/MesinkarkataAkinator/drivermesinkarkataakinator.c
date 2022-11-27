#include "mesinkataakinator.c"
#include "mesinkarakinator.c"
#include <stdio.h>

int main(){
    STARTWORDakin();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
    if(IsEOPakin()) printf("EOP\n");
    else printf("Not EOP\n");
    ADVWORDakin();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
    if(IsEOPakin()) printf("EOP\n");
    else printf("Not EOP\n");
    ADVWORDakin();
    for (int i =0; i< currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
    if(IsEOPakin()) printf("EOP\n");
    else printf("Not EOP\n");
    ADVWORDakin();
    return 0;
}