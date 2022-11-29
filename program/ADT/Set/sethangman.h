#ifndef sethangman_H
#define sethangman_H
#include "../boolean/boolean.h"

/* MODUL SetChar
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilSetChar 0
#define MaxElsetChar 100

typedef char infotypesetchar;
typedef int addressSetchar;

typedef struct
{
    infotypesetchar Elements[MaxElsetChar];
    addressSetchar Count;
} SetChar;

/* Definisi SetChar S kosong : S.Count = Nil */
/* S.Count = jumlah element SetChar */
/* S.Elements = tempat penyimpanan element SetChar */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySetChar(SetChar *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah SetChar S kosong berkapasitas MaxEl */
/* Ciri SetChar kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetChar(SetChar S);
/* Mengirim true jika SetChar S kosong*/
/* Ciri SetChar kosong : count bernilai Nil */

boolean IsFullSetChar(SetChar S);
/* Mengirim true jika SetChar S penuh */
/* Ciri SetChar penuh : count bernilai MaxEl */

/* ********** Operator Dasar SetChar ********* */
void InsertSetChar(SetChar *S, infotypesetchar Elmt);
/* Menambahkan Elmt sebagai elemen SetChar S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetChar(SetChar *S, infotypesetchar Elmt);
/* Menghapus Elmt dari SetChar S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSetChar(SetChar S, infotypesetchar Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

boolean IsSubsetSetChar(SetChar SAnswer, SetChar SKunjaw);
/*Mengembalikan true jika seluruh Elmt S1 adalah member dari S2*/

void PrintSetChar(SetChar S);
/*Mencetak isi set*/

#endif