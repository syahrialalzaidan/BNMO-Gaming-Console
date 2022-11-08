#include <stdio.h>
#include <stdlib.h>
#include "program/ADT/mesinkarkata/mesinkata.h"
#include "program/ADT/arraydin/arraydin.h"
#include "program/ADT/boolean/boolean.h"
#include "program/ADT/queue/queue.h"
#include "program/queuegame.h"
#include "program/load.h"
#include "program/start.h"
#include "program/save.h"
//gcc program/save.c program/load.c program/start.c program/ADT/queue/queue.c program/ADT/mesinkarkata/mesinkar.c program/ADT/mesinkarkata/mesinkata.c program/ADT/arraydin/arraydin.c main.c -o main


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
// void WordToString(char x[100], Word W){
// /* Mengubah Word menjadi string
//     I.S. : Word W terdefinisi, string dest belum terdefinisi
//     F.S. : string dest sudah terdefinisi berdasarkan Word W*/   
//     int i;
//     for (i = 0; i < W.Length; i++){
//         x[i] = W.TabWord[i];
//     }
//     x[i] = '\0';
// }
// char *WordToString(Word W) {
//     char *x = malloc(W.Length + 1);
//     for (int i = 0; i < W.Length; i++) {
//         x[i] = W.TabWord[i];
//     }
//     x[W.Length] = '\0';
//     return x;
// }
// char *WordToString(Word W) {
//     char *x = malloc(W.Length + 1);
//     for (int i = 0; i < W.Length; i++) {
//         x[i] = W.TabWord[i];
//     }
//     x[W.Length] = '\0';
//     return x;
// }

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
        *command = 11;
    }

    return output;
}

int main() {
    ArrayDin Games = MakeArrayDin();
    char* filename;
    int command;
    printf("Welcome to BNMO!\n");
    printf("========================\n");
    printf("ENTER COMMAND: ");

    Queue queuegames;
    CreateQueue(&queuegames);
    STARTWORD();
    while (!isCommandValid(currentWord, &command)) {
        printf("command = %d\n", command);
        printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        printf("ENTER COMMAND: ");
        STARTWORD();
    }
    while (IsEmpty(Games)) {
        if (command == 1) {
            ADVWORD();
            filename = WordToString(currentWord);
            printf("Loading game from %s...\n", filename);
            //loadfile(filename, &Games);
        } else if (command == 0) {
            printf("Starting new game...\n");
            start(&Games);
        }
    }
    //print array games
    printf("Game yang tersedia:\n");
    for (int i = 0; i < Games.Neff; i++) {
        printf("%d. %s\n", i+1, Games.A[i]);
    }
    while (!isWordSame(currentWord, stringToWord("QUIT"))){
        if(command == 2){
            ADVWORD();
            filename = WordToString(currentWord);
            save(&Games, filename);
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
            /* printf("QUEUE GAME\n"); */
            //queuegame(&queuegames, Games);
        }
        else if(command == 7){
            //PLAY_GAME();
            /* printf("PLAY GAME\n"); */
            //playgame(&queuegames, Games);
        }
        else if(command == 8){
            //SKIPGAME();
            /* printf("SKIPGAME\n"); */
            ADVWORD();
            int nomor;
            nomor = currentWord.TabWord[0] - '0';
            //skipgame(&queuegames, nomor, Games);
        }
        else if(command == 10){
            //HELP();
            printf("HELP\n");
        }
        printf("ENTER COMMAND: ");
        STARTWORD();
        isCommandValid(currentWord, &command);
        while (command == 11 || command == 0 || command == 1) {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("ENTER COMMAND: ");
            STARTWORD();
            isCommandValid(currentWord, &command);
        }
    }
    //QUIT();
    return 0;
}