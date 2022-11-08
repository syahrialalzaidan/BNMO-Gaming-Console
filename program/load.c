#include <stdio.h>
#include <stdlib.h>
#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkarfile.h"
#include "ADT/mesinkarkata/mesinkatafile.h"
#include "load.h"
// gcc program/ADT/mesinkarkata/mesinkarfile.c program/ADT/mesinkarkata/mesinkatafile.c program/ADT/arraydin/arraydin.c program/load.c program/load_driver.c -o load_driver


char* AddPath(char* filename) {
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

char *WordToString(Word W) {
    char *x = malloc(W.Length + 1);
    for (int i = 0; i < W.Length; i++) {
        x[i] = W.TabWord[i];
    }
    x[W.Length] = '\0';
    return x;
}

void WordToInt(int *x, Word W) {
/* Mengubah Word menjadi integer
    I.S. : Word W terdefinisi, integer dest belum terdefinisi
    F.S. : integer dest sudah terdefinisi berdasarkan Word W*/   
    int i;
    int temp = 0;
    for (i = 0; i < W.Length; i++){
        if (W.TabWord[i] != BLANK) {
            temp = temp * 10 + (W.TabWord[i] - '0');
        }
    }
    *x = temp;
}

void loadfile(char* filename, ArrayDin* Games) {
    char* filepath = AddPath(filename);
    // LoadPita("./data/config.txt");
    // open config.txt in data folder
    LoadPita(filepath);
    STARTWORD();
    int i = 0;
    WordToInt(&i, currentWord);
    int j = 0;
    while (j < i) {
        ADVWORD();
        char* name = WordToString(currentWord);
        InsertLast(Games, name);
        j++;
    }
}