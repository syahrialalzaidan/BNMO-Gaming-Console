#include "stackhanoi.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyHanoi(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyHanoi(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S) == Nil);
}
boolean IsFullHanoi(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == (MaxEl-1));
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushHanoi(Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    boolean found = false;
    int i = 0;
    while (!found){
        if((*S).T[i] == 0){
            (*S).T[i] = X;
            found = true;
        }
        else i++;
    }
    Top(*S)++;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopHanoi(Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    boolean found = false;
    int i = 0;
    while (! found){
        if ((*S).T[(*S).TOP - i] != 0){
            *X = (*S).T[(*S).TOP - i];
            (*S).T[(*S).TOP - i] = 0;
            Top(*S)--;
            found = true;
        }
        else i++;
    }
}

int lengthS(Stack S){
/* Mencari panjang dari stack
   I.S. S mungkin kosong
   F.S. Panjang dari S*/
    int i = 0;
    while (i <= Top(S)){
        if (InfoTop(S) != 0) i++;
    }
    return i;
}

void setNol(Stack *S){
/* Membuat S isinya 0 semua*/
    for (int i = 0; i < MaxEl; i++){
        (*S).T[i] = 0;
    }
}

boolean isStackSama(Stack s1, Stack s2){
/* Mengembalikan true jika stack sama*/
    boolean sama = true;
    int i = 0;
    while (i <= Top(s1) && sama){
        if (s1.T[i] != s2.T[i]) sama = false;
        else i++;
    }
    return sama;
}

int gettop (Stack S){
/* Mengambil top pada stack*/
    boolean found = false;
    int i = 0, x = 0;
    while (! found){
        if ((S).T[(S).TOP - i] != 0){
            x = (S).T[(S).TOP - i];
            found = true;
        }
        else i++;
    }
    if (x == 10 && (S).T[(S).TOP] == 0) x = 0;
    return x;
}