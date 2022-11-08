#include "arraydin.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "queue.h"
#include "boolean.h"

boolean findatqueue(Queue queuegame, int indeksgame);
/*I.S. Queue game mungkin kosong*/
/*F.S. Elemen queue ditemukan atau tidak*/

void deletegame(ArrayDin *array, Queue queuegame);
/*I.S. Array game mungkin kosong*/
/*F.S. Nomor games yang ingin dihapus telah hilang dari array*/