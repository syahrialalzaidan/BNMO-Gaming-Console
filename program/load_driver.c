#include <stdio.h>
#include <stdlib.h>
#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkarfile.h"
#include "ADT/mesinkarkata/mesinkatafile.h"
#include "load.h"

int main() {
    ArrayDin Games = MakeArrayDin();
    loadfile("config.txt", &Games);
}