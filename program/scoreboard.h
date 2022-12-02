#include <stdio.h>
#include "ADT/Map/map.h"
#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/mesinkarkata/mesinkata.h"

int StringLength(char* string);
/* Mengembalikan nilai panjang suatu string */

int CountDigits(float n);
/* Mengembalikan nilai panjang suatu float */

void PrintScoreboard(Map M);
/* Menampilkan Scoreboard yang ada ke layar. */

void ResetScoreboard(ListMap *LM, ArrayDin G);
/* Me-reset scoreboard
    I.S.: Scoreboard terisi
    F.S.: Scoreboard suatu/semua permainan di-reset, tergantung masukan user. */