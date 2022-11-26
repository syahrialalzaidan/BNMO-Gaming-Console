#include "history.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/mesinkarkata/mesinkata.h"

void PrintHistory(Stack History, int n) {
    Stack tempStack = CopyStack(History);
    int count = 1;
    printf("Berikut adalah daftar Game yang telah dimainkan:\n");
    while (!IsStackEmpty(tempStack)) {
        infotype X;
        Pop(&tempStack, &X);
        if (n > 0) {
            printf("%d. %s\n", count, X);
            n--;
            count++;
        }
    }
}

void ResetHistory(Stack *History) {
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
    STARTWORD();
    while(!isWordSame(currentWord, stringToWord("YA")) && !isWordSame(currentWord, stringToWord("TIDAK"))) {
        printf("Input tidak valid!\n");
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
        STARTWORD();
    }
    if (isWordSame(currentWord, stringToWord("YA"))) {
        while (!IsStackEmpty(*History)) {
            infotype X;
            Pop(History, &X);
        }
    } else {
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        PrintHistory(*History, nbElmtStack(*History));
    }
}