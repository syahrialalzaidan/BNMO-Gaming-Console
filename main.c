#include <stdio.h>
#include <stdlib.h>
#include "program/ADT/mesinkarkata/mesinkata.h"
#include "program/ADT/arraydin/arraydin.h"
#include "program/ADT/boolean/boolean.h"
#include "program/ADT/queue/queue.h"
#include "program/load.h"
#include "program/start.h"
#include "program/save.h"
#include "program/create_game.h"
#include "program/list_game.h"
#include "program/delete_game.h"
#include "program/queuegame.h"
#include "program/playgame.h"
#include "program/skipgame.h"
#include "program/help.h"
#include "program/ADT/stack/stack.h"
#include "bnmo_pic.h"

//  copy paste below to run main
//  gcc program/ADT/queue/queue.c bnmo_pic.c program/help.c program/skipgame.c program/playgame.c program/queuegame.c program/delete_game.c program/list_game.c program/create_game.c program/save.c program/load.c program/start.c program/ADT/queue/queue.c program/ADT/mesinkarkata/mesinkar.c program/ADT/mesinkarkata/mesinkata.c program/ADT/arraydin/arraydin.c main.c game/dinnerdash.c game/rng.c game/tebakkata.c game/queuedinnerdash.c program/ADT/Map/map.c -o main
//  or try run make main in bin folder

boolean isInputValid(Word kata, int *command)
{
    boolean output;
    if (isWordSame(kata, stringToWord("START"))) {
        output = true;
        *command = 0;
    }
    else if (isWordSame(kata, stringToWord("LOAD"))) {
        output = true;
        *command = 1;
        ADVWORD();
    }
    else if (isWordSame(kata, stringToWord("SAVE"))) {
        output = true;
        *command = 2;
        ADVWORD();
    }
    else if (isWordSame(kata, stringToWord("CREATE")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 3;
        } else {
            output = false;
            *command = 11;
        }
    }
    else if (isWordSame(kata, stringToWord("LIST")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 4;
        } else {
            output = false;
            *command = 11;
        }
    }
    else if (isWordSame(kata, stringToWord("DELETE")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 5;
        } else {
            output = false;
            *command = 11;
        }
    }
    else if (isWordSame(kata, stringToWord("QUEUE")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 6;
        } else {
            output = false;
            *command = 11;
        }
    }
    else if (isWordSame(kata, stringToWord("PLAY")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME")))
        {
            output = true;
            *command = 7;
        } else {
            output = false;
            *command = 11;
        }
    }
    else if (isWordSame(kata, stringToWord("SKIP")))
    {
        ADVWORD();
        if (isWordSame(currentWord, stringToWord("GAME"))){
            output = true;
            *command = 8;
        } else {
            output = false;
            *command = 11;
        }
        ADVWORD();
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
        ADVWORD();
    }
    else
    {
        output = false;
        *command = 11;
    }
    if(! IsEOP()){
        output = false;
        *command = 11;
    }
    while(! IsEOP()) ADVWORD();
    return output;
}

int main() {
    ArrayDin Games = MakeArrayDin();
    Queue queuegames;
    Stack history;
    Map scoreboard;
    CreateQueue(&queuegames);
    CreateEmptyStack(&history);
    char* filename;
    int command;
    bnmo_pic();
    printf("\nPILIHAN MENU:\n=> START\n=> LOAD (filename.txt)\n");
    printf("ENTER COMMAND: ");
    STARTWORD();
    while (IsEmpty(Games)) {
        while (!isInputValid(currentWord, &command)) {
            printf("Command tidak dikenali, silakan masukkan command yang valid.\n\n");
            while (! IsEOP()) ADVWORD();
            printf("ENTER COMMAND: ");
            STARTWORD();
        }
        if (command == 1) {
            filename = WordToString(currentWord);
            load(filename, &Games);
            if (IsEmpty(Games)) {
                printf("File tidak ditemukan, silakan masukkan nama file yang valid.\n\n");
                printf("ENTER COMMAND: ");
                STARTWORD();
            }
        } else if (command == 0) {
            start(&Games);
        }
    }
    
    if (command == 1) {
        printf("\nSave file berhasil dibaca. BNMO berhasil dijalankan ^^\n\n");
    } else if (command == 0) {
        printf("\nFile konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan ^^\n\n");
    }

    printf("PILIHAN MENU:\n=> SAVE (filename.txt)\n=> CREATE GAME\n=> LIST GAME\n=> DELETE GAME\n=> QUEUE GAME\n=> PLAY GAME\n=> SKIP GAME (N)\n=> QUIT\n=> HELP\n");
    printf("(N adalah jumlah game yang ingin dilewat pada queue)\n");

    while (!isWordSame(currentWord, stringToWord("QUIT"))){
        if(command == 2){
            filename = WordToString(currentWord);
            save(&Games, filename);
        }
        else if(command == 3){
            creategame(&Games);
        }
        else if(command == 4){
            listgame(Games);
        }
        else if(command == 5){
            deletegame(&Games, queuegames);
        }
        else if(command == 6){
            queuegame(&queuegames, Games);
        }
        else if(command == 7){
            playgame(&queuegames, Games);
        }
        else if(command == 8){
            int nomor = WordToInt(currentWord);

            skipgame(&queuegames, nomor, Games);
        }
        else if(command == 10){
            help();
        }
        printf("ENTER COMMAND: ");
        STARTWORD();
        boolean cek2 = isInputValid(currentWord, &command);
        while ((command == 11 || command == 0 || command == 1) || (!cek2)) {
            if (command == 1 || command == 0) {
                printf("Sistem sudah membaca file, Kamu bisa memulai ulang sistem untuk membaca file lain.\n\n");
            } else {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n\n");
            }
            printf("ENTER COMMAND: ");
            STARTWORD();
            cek2 = isInputValid(currentWord, &command);
        }
        
    }
    save(&Games, "savefile1.txt");
    CreateQueue(&queuegames);
    printf("Anda Keluar dari game BNMO\nBye byee.........\n");
    return 0;
}