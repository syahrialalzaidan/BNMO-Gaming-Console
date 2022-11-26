#include <stdio.h>
#include "set.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S){
    (*S).Count = NilSet;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return S.Count == NilSet;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S){
    return S.Count == MaxElset;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, infotypeset Elmt){
    if (!IsMember(*S, Elmt))
    {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, infotypeset Elmt){
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
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotypeset Elmt){
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

boolean IsSubsetSet(Set SAnswer, Set SKunjaw){
    boolean valid = true;
    int i = 0;
    while (valid && i < SKunjaw.Count)
    {
        if (!IsMember(SAnswer, SKunjaw.Elements[i]))
        {
            valid = false;
        }
        i++;
    }
    return valid;
}
/*Mengembalikan true jika seluruh Elmt SAnswer adalah member dari SKunjaw*/
/*
int main(){
    Set ans, kj;
    CreateEmptySet(&ans);
    CreateEmptySet(&kj);
    char input;
    scanf("%c", &input);
    while (input != 'x')
    {
        InsertSet(&ans, input);
        scanf("%c", &input);
    }

    printf("Sekarang set kunjaw\n");
    scanf("%c", &input);
    printf("%d\n",ans.Count);
    while (input != 'x')
    {
        InsertSet(&kj, input);
        scanf("%c", &input);
        printf("%d\n",ans.Count);
    }
    
    int i = 0;
    printf("Ini isi set answer\n");
    printf("%d\n%d\n", i);
    while (i < ans.Count)
    {
        printf("%c\n", ans.Elements[i]);
        i++;
        printf("%d\n", i);
    }

    return 0;
}
*/