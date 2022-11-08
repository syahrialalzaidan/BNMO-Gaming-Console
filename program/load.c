#include <stdio.h>
#include <stdlib.h>
#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/mesinkarkata/mesinkata.h"
#include "load.h"
// gcc program/ADT/mesinkarkata/mesinkar.c program/ADT/mesinkarkata/mesinkata.c program/ADT/arraydin/arraydin.c program/load.c program/load_driver.c -o load_driver


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

void loadfile(char* filename, ArrayDin* Games) {
    char* filepath = AddPath(filename);
    // LoadPita("./data/config.txt");
    // open config.txt in data folder
    LoadPita(filepath, true);
    STARTWORD();
    int i = WordToInt(currentWord);
    int j = 0;
    while (j < i) {
        ADVWORD();
        char* name = WordToString(currentWord);
        InsertLast(Games, name);
        j++;
    }
    StopLoadPita();
}