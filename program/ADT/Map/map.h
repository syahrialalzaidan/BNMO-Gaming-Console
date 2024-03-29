#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean/boolean.h"
#include "../mesinkarkata/mesinkata.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define NilMap 0
#define MaxEl 100
#define Undefined -999

// typedef int bool;
typedef char *keytype;
typedef float valuetype;
typedef int addressMap;

typedef struct {
	keytype Key;
	valuetype Value;
} infotypeMap;

typedef struct {
	infotypeMap Elements[MaxEl];
	addressMap Count;
} Map;

typedef struct {
	Map Elmt[MaxEl];
	addressMap Neff;
} ListMap;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

void CreateEmptyLM(ListMap *LM);

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsLMEmpty(ListMap LM);

boolean IsFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void InsertMapAt(ListMap *LM, Map M, addressMap i);

void Delete(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

void DeleteMapAt(ListMap *LM, addressMap i);

boolean IsMemberMap(Map M, keytype k);

void sortmapdesc(Map *M);

#endif