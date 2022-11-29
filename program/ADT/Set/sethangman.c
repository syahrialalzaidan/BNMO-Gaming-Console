#include <stdio.h>
#include "sethangman.h"

/* MODUL SetChar
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

/* Definisi SetChar S kosong : S.Count = Nil */
/* S.Count = jumlah element SetChar */
/* S.Elements = tempat penyimpanan element SetChar */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySetChar(SetChar *S){
    (*S).Count = NilSetChar;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah SetChar S kosong berkapasitas MaxEl */
/* Ciri SetChar kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetCharChar(SetChar S){
    return S.Count == NilSetChar;
}
/* Mengirim true jika SetChar S kosong*/
/* Ciri SetChar kosong : count bernilai Nil */

boolean IsFullSetCharChar(SetChar S){
    return S.Count == MaxElsetChar;
}
/* Mengirim true jika SetChar S penuh */
/* Ciri SetChar penuh : count bernilai MaxEl */

/* ********** Operator Dasar SetChar ********* */
void InsertSetChar(SetChar *S, infotypesetchar Elmt){
    if (!IsMemberSetChar(*S, Elmt))
    {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen SetChar S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetChar(SetChar *S, infotypesetchar Elmt){
    boolean exist = false;
    int i = 0;
    while (!exist && i < (*S).Count)
    {
        if ((*S).Elements[i] == Elmt)
        {
            exist = true;
        }
        i++;
    }

    if (exist)
    {
        
        for (i; i<(*S).Count; i++)
        {
            (*S).Elements[i-1] = (*S).Elements[i];
        }
        (*S).Count--;
    }
}
/* Menghapus Elmt dari SetChar S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSetChar(SetChar S, infotypesetchar Elmt){
    boolean exist = false;
    int i = 0;
    while (!exist && i < S.Count)
    {
        if (S.Elements[i] == Elmt)
        {
            exist = true;
        }
        i++;
    }
    return exist;
}
/* Mengembalikan true jika Elmt adalah member dari S */

boolean IsSubsetSetChar(SetChar SAnswer, SetChar SKunjaw){
    boolean valid = true;
    int i = 0;
    while (valid && i < SKunjaw.Count)
    {
        if (!IsMemberSetChar(SAnswer, SKunjaw.Elements[i]))
        {
            valid = false;
        }
        i++;
    }
    return valid;
}

void PrintSetChar(SetChar S){
    for (int i = 0; i<S.Count; i++)
    {
        printf("%c ", S.Elements[i]);
    }
    printf("\n");
}
/*Mencetak isi set*/
