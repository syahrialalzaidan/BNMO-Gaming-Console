#ifndef mapChar_H
#define mapChar_H
#include <stdio.h>
#include "../boolean/boolean.h"
#include "../mesinkarkata/mesinkata.h"
/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define NilMap 0
#define maxEl 10
#define Undefined -999

// typedef int bool;
typedef char *keytype;
typedef char *valuetypechar;
typedef int addressMap;

typedef struct {
	keytype Key;
	valuetypechar Value;
} infotypeMC;

typedef struct {
	infotypeMC Elements[maxEl];
	addressMap Count;
} MapChar;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyChar(MapChar *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmptyChar(MapChar M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullChar(MapChar M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetypechar ValueChar(MapChar M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertChar(MapChar *M, keytype k, valuetypechar v);
/* Menambahkan Elmt sebagai elemen MapChar M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteChar(MapChar *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberChar(MapChar M, keytype k);
/* Mengirim true jika k adalah key yang terdapat pada M */

void sortmapchardesc(MapChar *M);
/* I.S. M tidak kosong */
/* F.S. M terurut secara descending berdasarkan value */


#endif