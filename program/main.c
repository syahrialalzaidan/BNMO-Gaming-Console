#include <stdio.h>
#include "ADT/mesinkarkata/mesinkata.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/boolean/boolean.h"
//gcc program/ADT/mesinkarkata/mesinkar.c program/ADT/mesinkarkata/mesinkata.c program/ADT/arraydin/arraydin.c program/main.c -o main


Word stringToWord(char *string) {
    Word word;
    int i = 0;
    while(string[i] != '\0') {
        word.TabWord[i] = string[i];
        i++;
    }
    word.Length = i;
    return word;
}

//convert string to word
void WordToString(char x[100], Word W){
/* Mengubah Word menjadi string
    I.S. : Word W terdefinisi, string dest belum terdefinisi
    F.S. : string dest sudah terdefinisi berdasarkan Word W*/   
    int i;
    for (i = 0; i < W.Length; i++){
        x[i] = W.TabWord[i];
    }
    x[i] = '\0';
}

boolean isWordSame(Word K1, Word K2) {
    if (K1.Length != K2.Length) {
        return false;
    } else {
        int i = 0;
        while (i < K1.Length) {
            if (K1.TabWord[i] != K2.TabWord[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
}

int main() {
    ArrayDin Games = MakeArrayDin();
    printf("Welcome to BNMO!\n");
    printf("================\n");
    printf("ENTER COMMAND: ");
    STARTWORD();
    //print word with for loop
    while ((!isWordSame(currentWord, stringToWord("START"))) && (!isWordSame(currentWord, stringToWord("LOAD"))) && 
    (!isWordSame(currentWord, stringToWord("SAVE"))) && (!isWordSame(currentWord, stringToWord("CREATEGAME"))) && 
    (!isWordSame(currentWord, stringToWord("LISTGAME"))) && (!isWordSame(currentWord, stringToWord("DELETEGAME"))) && 
    (!isWordSame(currentWord, stringToWord("QUEUEGAME"))) && (!isWordSame(currentWord, stringToWord("PLAYGAME"))) && 
    (!isWordSame(currentWord, stringToWord("SKIPGAME"))) && (!isWordSame(currentWord, stringToWord("HELP")))){
        printf("commandnya gaada ini mah\n");
        printf("Masukkan command yang benernya ya, kalau perlu bantuan bisa panggil HELP: ");
        STARTWORD();
    }

    if(isWordSame(currentWord, stringToWord("LOAD"))) {
        ADVWORD();
        char filename[100];
        WordToString(filename, currentWord);
        printf("Loading game from %s...\n", filename);
    } else if (isWordSame(currentWord, stringToWord("START"))) {
        printf("Game's starting!\n");
    }
    return 0;
}