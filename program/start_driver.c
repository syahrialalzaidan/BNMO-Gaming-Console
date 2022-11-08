
#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "load.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkarfile.h"
#include "ADT/mesinkarkata/mesinkatafile.h"

// gcc program/ADT/mesinkarkata/mesinkarfile.c program/ADT/mesinkarkata/mesinkatafile.c program/ADT/arraydin/arraydin.c program/load.c program/start.c program/start_driver.c -o coba


int main() {
    ArrayDin Games = MakeArrayDin();
    start(&Games);
}