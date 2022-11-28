#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkata.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/queue/queue.h"
#include "ADT/boolean/boolean.h"
#include "ADT/Map/map.h"
#include "ADT/Stack/stack.h"
#include "list_game.h"

boolean IsInQueue(Queue queuegame, char* elQ);
/* Mengembalikan nilai true jika elemen ada di dalam queue. */

void deletegame(ArrayDin *array, Queue queuegame, Stack *History, ListMap *scoreboard);
/*  Menghapus sebuah game dari daftar game.
    I.S. Array game tidak mungkin kosong.
    F.S. Game yang ingin dihapus telah hilang dari array jika 
         game tersebut tidak ada di dalam daftar game pada
         file konfigurasi default. */