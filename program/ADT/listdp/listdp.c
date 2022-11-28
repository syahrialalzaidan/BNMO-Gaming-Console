#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* 
NIM             :18221043 
Nama            : Attariq Muhammad Azhar
Tanggal         : 15 Oktober 2022
Topik praktikum : Variasi List Linier
Deskripsi       : Implementasi listdp.h
*/

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (First(L) == NilListDP);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L) {
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = NilListDP;
    Last(*L) = NilListDP;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotypeList X, infotypeList Y) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    address P = (address) malloc (sizeof(ElmtList));
    if (P != NULL) {
        InfoX(P) = X;
        InfoY(P) = Y;
        Next(P) = NilListDP;
        Prev(P) = NilListDP;
    }
    return P;
}

void Dealokasi (address P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotypeList X, infotypeList Y) {
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    while (P != NilListDP && (InfoX(P) != X || InfoY(P) != Y)) {
        P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeList X, infotypeList Y) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X, Y);
    if (P != NilListDP) {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotypeList X, infotypeList Y) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X, Y);
    if (P != NilListDP) {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeList *X, infotypeList *Y) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P = First(*L);
    *X = InfoX(P);
    *Y = InfoY(P);
    DelFirst(L, &P);
    Dealokasi(P);
}

void DelVLast (List *L, infotypeList *X, infotypeList *Y) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P = Last(*L);
    *X = InfoX(P);
    *Y = InfoY(P);
    DelLast(L, &P);
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLast (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Prec == Last(*L)) {
        InsertLast(L, P);
    } else {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
        Prev(P) = Prec;
    }
}

void InsertBefore (List *L, address P, address Succ) {
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    if (Succ == First(*L)) {
        InsertFirst(L, P);
    } else {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
        Next(P) = Succ;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (Next(*P) == NilListDP) {
        CreateEmptyList(L);
    } else {
        First(*L) = Next(*P);
        Prev(First(*L)) = NilListDP;
        Next(*P) = NilListDP;
    }
}

void DelLast (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P = Last(*L);
    if (Prev(*P) == NilListDP) {
        CreateEmptyList(L);
    } else {
        Last(*L) = Prev(*P);
        Next(Last(*L)) = NilListDP;
        Prev(*P) = NilListDP;
    }
}

void DelP (List *L, infotypeList X, infotypeList Y) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X, Y);
    if (P != NilListDP) {
        if (P == First(*L)) {
            DelFirst(L, &P);
        } else if (P == Last(*L)) {
            DelLast(L, &P);
        } else {
            Prev(Next(P)) = Prev(P);
            Next(Prev(P)) = Next(P);
            Next(P) = NilListDP;
            Prev(P) = NilListDP;
        }
        Dealokasi(P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (*Pdel == Last(*L)) {
        DelLast(L, Pdel);
    } else {
        Next(Prec) = Next(*Pdel);
        Prev(Next(*Pdel)) = Prec;
        Next(*Pdel) = NilListDP;
        Prev(*Pdel) = NilListDP;
    }
}

void DelBefore (List *L, address *Pdel, address Succ) {
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Prev(Succ);
    if (*Pdel == First(*L)) {
        DelFirst(L, Pdel);
    } else {
        Prev(Succ) = Prev(*Pdel);
        Next(Prev(*Pdel)) = Succ;
        Next(*Pdel) = NilListDP;
        Prev(*Pdel) = NilListDP;
    }
}

int LengthList(List L) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count = 0;
    address P = First(L);
    while (P != NilListDP) {
        count++;
        P = Next(P);
    }
    return count;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = First(L);
    printf("[");
    while (P != NilListDP) {
        printf("<%d, %d>", InfoX(P), InfoY(P));
        P = Next(P);
        if (P != NilListDP) {
            printf(",");
        }
    }
    printf("]");
}

void PrintBackward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = Last(L);
    printf("[");
    while (P != NilListDP) {
        printf("<%d, %d>", InfoX(P), InfoY(P));
        P = Prev(P);
        if (P != NilListDP) {
            printf(",");
        }
    }
    printf("]");
}
