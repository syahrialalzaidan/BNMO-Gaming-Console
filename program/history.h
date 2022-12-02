#include <stdio.h>
#include "ADT/Stack/stack.h"

void PrintHistory(Stack History, int n);
/* Memberikan output n permainan terakhir yang telah dimainkan*/

void ResetHistory(Stack *History);
/* Me-reset history permainan
    I.S.: History terisi 
    F.S.: Setiap elemen di dalam stack history di-pop sampai history kosong. */