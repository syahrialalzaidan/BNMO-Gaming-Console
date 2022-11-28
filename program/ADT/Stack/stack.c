#include <stdio.h>
#include "stack.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S) 
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == NilStack;
}

boolean IsStackFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == MaxElStack - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}

/* ************ Mengcopy Stack ************ */
Stack CopyStack(Stack stack) {
/* Mengirimkan salinan dari Stack*/
    Stack newStack, tempStack;
    CreateEmptyStack(&newStack);
    CreateEmptyStack(&tempStack);
    while (!IsStackEmpty(stack)) {
        infotype X;
        Pop(&stack, &X);
        Push(&tempStack, X);
    }
    while (!IsStackEmpty(tempStack)) {
        infotype X;
        Pop(&tempStack, &X);
        Push(&stack, X);
        Push(&newStack, X);
    }
    return newStack;
}

Stack ReversedStack(Stack S) {
/* Mengirimkan salinan dari Stack dengan urutan elemen terbalik*/
    Stack newStack, tempStack;
    CreateEmptyStack(&newStack);
    CreateEmptyStack(&tempStack);
    while (!IsStackEmpty(S)) {
        infotype X;
        Pop(&S, &X);
        Push(&newStack, X);
        Push(&tempStack, X);
    }
    while (!IsStackEmpty(tempStack)) {
        infotype X;
        Pop(&tempStack, &X);
        Push(&S, X);
    }
    return newStack;
}

/* ************ Menghitung elemen dari stack ************ */
int nbElmtStack(Stack S) {
/*Menghitung jumlah element dalam stack */
    int count = 0;
    Stack tempStack = CopyStack(S);
    while (!IsStackEmpty(tempStack)) {
        infotype X;
        Pop(&tempStack, &X);
        count++;
    }
    return count;
}
