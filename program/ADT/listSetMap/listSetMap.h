#ifndef ListSetMap_H
#define ListSetMap_H
#include <stdio.h>
#include "../boolean/boolean.h"
#include "../Set/set.h"
#include "../Map/map.h"

#define NilSM 0
#define MaxElSM 100
#define UndefinedLSM -999
typedef int address;

typedef struct {
    Set S;
    Map M;
} infotypeLSM;

typedef struct {
    infotypeLSM Elements[MaxEl];
    address Count;
} ListSetMap;


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyLSM(ListSetMap *SM);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsLSMEmpty(ListSetMap SM);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsLSMFull(ListSetMap SM);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype ValueLSM(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertAtLSM(ListSetMap *SM, int idx, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteAtLSM(ListSetMap *SM, int idx);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

#endif
