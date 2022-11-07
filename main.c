#include <stdio.h>
#include "game/mesinkata.h"
#include "program/ADT/arraydin/arraydin.h"
#include "program/ADT/boolean/boolean.h"
//gcc game/mesinkar.c game/mesinkata.c program/ADT/arraydin/arraydin.c main.c -o main


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
boolean isCommandValid(Word kata, int *command)
{
    boolean output;
    if (isWordSame(kata, stringToWord("START"))) {
        output = true;
        *command = 0;
    }
    else if (isWordSame(kata, stringToWord("LOAD"))) {
        output = true;
        *command = 1;
    }
    else if (isWordSame(kata, stringToWord("SAVE"))) {
        output = true;
        *command = 2;
    }
    else if (isWordSame(kata, stringToWord("CREATE")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 3;
        }
    }
    else if (isWordSame(kata, stringToWord("LIST")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 4;
        }
    }
    else if (isWordSame(kata, stringToWord("DELETE")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 5;
        }
    }
    else if (isWordSame(kata, stringToWord("QUEUE")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 6;
        }
    }
    else if (isWordSame(kata, stringToWord("PLAY")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 7;
        }
    }
    else if (isWordSame(kata, stringToWord("SKIPGAME")))
    {
        output = true;
        *command = 8;
    }
    else if (isWordSame(kata, stringToWord("QUIT")))
    {
        output = true;
        *command = 9;
    }
    else if (isWordSame(kata, stringToWord("HELP")))
    {
        output = true;
        *command = 10;
    }
    else
    {
        output = false;
    }

    return output;
}

int main() {
    ArrayDin Games = MakeArrayDin();
    int command;
    printf("Welcome to BNMO!\n");
    printf("========================\n");
    printf("ENTER COMMAND: ");
    STARTWORD();
    while (!isWordSame(currentWord, stringToWord("QUIT"))){
        while (!isCommandValid(currentWord, &command)) {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("ENTER COMMAND: ");
            STARTWORD();
        }
        if (command == 0){
            //START();
            printf("START\n");
        }
        else if(command == 1){
            //LOAD();
            printf("LOAD\n");
        }
        else if(command == 2){
            //SAVE();
            printf("SAVE\n");
        }
        else if(command == 3){
            //CREATE_GAME();
            printf("CREATE GAME\n");
        }
        else if(command == 4){
            //LIST_GAME();
            printf("LIST GAME\n");
        }
        else if(command == 5){
            //DELETE_GAME();
            printf("DELETE GAME\n");
        }
        else if(command == 6){
            //QUEUE_GAME();
            printf("QUEUE GAME\n");
        }
        else if(command == 7){
            //PLAY_GAME();
            printf("PLAY GAME\n");
        }
        else if(command == 8){
            //SKIPGAME();
            printf("SKIPGAME\n");
        }
        else if(command == 10){
            //HELP();
            printf("HELP\n");
        }
        printf("ENTER COMMAND: ");
        STARTWORD();
    }
    //QUIT();
    return 0;
}