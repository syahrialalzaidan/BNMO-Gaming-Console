#ifndef set_H
#define set_H
#include <stdio.h>
#include "../boolean/boolean.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilSet 0
#define MaxElset 100

typedef char* infotypeset;
typedef int address;

typedef struct
{
    infotypeset Elements[MaxElset];
    address Count;
} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, infotypeset Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, infotypeset Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotypeset Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

boolean IsSubsetSet(Set SAnswer, Set SKunjaw);
/*Mengembalikan true jika seluruh Elmt S1 adalah member dari S2*/

#endif