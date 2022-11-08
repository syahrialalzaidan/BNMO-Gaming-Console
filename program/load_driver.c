#include <stdio.h>
#include <stdlib.h>
#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkarfile.h"
#include "ADT/mesinkarkata/mesinkatafile.h"
#include "load.h"


// gcc program/ADT/mesinkarkata/mesinkar.c program/ADT/mesinkarkata/mesinkata.c program/ADT/arraydin/arraydin.c program/load.c program/load_driver.c -o load_driver
int main() {
    ArrayDin Games = MakeArrayDin();
    loadfile("config.txt", &Games);
    //print array games
    int i = 0;
    while (i < Games.Neff) {
        i++;
    }
    //print games array
    for (int i = 0; i < Games.Neff; i++) {
        printf("%d. %s\n", i+1, Games.A[i]);
    }
}