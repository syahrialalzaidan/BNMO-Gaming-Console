#include <stdio.h>
#include <stdlib.h>
#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/mesinkarkata/mesinkata.h"
#include "load.h"
// gcc program/ADT/mesinkarkata/mesinkar.c program/ADT/mesinkarkata/mesinkata.c program/ADT/arraydin/arraydin.c program/load.c program/load_driver.c -o load_driver


char* AddPath(char* filename) {
/*  Fungsi untuk menambahkan file path untuk setiap masukan filename untuk kemudian dibaca pada load. */
    char* path = "./data/";
    // count length of path
    int i = 0;
    while (path[i] != '\0') {
        i++;
    }
    // count length of filename
    int j = 0;
    while (filename[j] != '\0') {
        j++;
    }
    // allocate memory for the new string
    char* newpath = malloc(i + j + 1);
    // copy path to newpath
    int k = 0;
    while (k < i) {
        newpath[k] = path[k];
        k++;
    }
    // copy filename to newpath
    int l = 0;
    while (l < j) {
        newpath[k] = filename[l];
        k++;
        l++;
    }
    // add null terminator
    newpath[k] = '\0';
    return newpath;
}

void SeparateWords(Word W, Word *W1, Word *W2) {
    int i = 0;
    while (W.TabWord[i] != BLANK) {
        W1->TabWord[i] = W.TabWord[i];
        i++;
    }
    W1->Length = i;
    i++;
    int j = 0;
    while (i < W.Length) {
        W2->TabWord[j] = W.TabWord[i];
        i++;
        j++;
    }
    W2->Length = j;
}

void load(char* filename, ArrayDin* Games, Stack *History, ListSetMap *Scoreboard) {
/*  Membaca save file yang berisi list game yang dapat dimainkan.
    I.S. : filename terdefinisi dan array games kosong.
    F.S. : Array games terisi dengan list game yang ada pada save file. */
    char* filepath = AddPath(filename);
    char* name;
    float score;
    // LoadPita("./data/config.txt");
    LoadPita(filepath, true);
    // load games
    STARTWORD();
    int jmlGame = WordToInt(currentWord);
    int j = 0;
    while (j < jmlGame) {
        ADVWORD();
        char* name = WordToString(currentWord);
        InsertLastArray(Games, name);
        j++;
    }

    // load history
    //PrintArrayDin(*Games);
    ADVWORD();
    if (!IsEOP()) {
        int i = WordToInt(currentWord);
        j = 0;
        while (j < i) {
            ADVWORD();
            char* name = WordToString(currentWord);
            Push(History, name);
            j++;
        }
    }
    // load scoreboard
    ADVWORD();

    if (!IsEOP()) {
        j = 0;
        while (j < jmlGame) {
            int jmlScoreboard = WordToInt(currentWord);
            int k = 0;
            while (k < jmlScoreboard) {
                ADVWORD();
                //separate
                Word W1, W2;
                SeparateWords(currentWord, &W1, &W2);
                name = WordToString(W1);
                score = WordToFloat(W2);
                InsertAtLSM(Scoreboard, j, name, score);
                k++;
            }
            Scoreboard->Count++;
            ADVWORD();
            j++;
        }
    }
        
    StopLoadPita();
}