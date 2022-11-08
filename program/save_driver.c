#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "load.h"
#include "ADT/arraydin/arraydin.h"

// gcc program/ADT/mesinkarkata/mesinkarfile.c program/ADT/mesinkarkata/mesinkatafile.c program/load.c program/ADT/arraydin/arraydin.c program/save.c program/save_driver.c -o save_driver

int main () {
    ArrayDin Games = MakeArrayDin();
    loadfile("savefile1.txt", &Games);
    InsertLast(&Games, "VALORANT");
    save(&Games, "savefile1.txt");
}