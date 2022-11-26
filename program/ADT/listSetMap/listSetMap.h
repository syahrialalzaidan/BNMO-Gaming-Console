#include <stdio.h>
#include "../boolean/boolean.h"

#define NilSet 0
#define MaxElset 100

typedef char infotypeset;
typedef int addressSet;

typedef struct
{
    infotypeset Elements[MaxElset];
    addressSet Count;
} Set;

#define NilMap 0
#define MaxEl 10
#define Undefined -999

typedef char *keytype;
typedef char *valuetype;
typedef int addressMap;

typedef struct {
	keytype Key;
	valuetype Value;
} infotype;

typedef struct {
	infotype Elements[MaxEl];
	addressMap Count;
} Map;

typedef struct {
    Set S;
    Map M;
    address Count
} ListSetMap;


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyLSM(ListSetMap *SM);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsLSMEmpty(ListSetMap M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsLSMFull(ListSetMap M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertLSM(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteLSM(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
