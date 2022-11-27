#include "listSetMap.h"
// gcc -o listSetMap ADT/listSetMap/listSetMap.c ADT/Map/map.c ADT/Set/set.c
/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyLSM(ListSetMap *SM) {
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
    (*SM).Count = NilSM;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsLSMEmpty(ListSetMap SM) {
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
    return SM.Count == NilSM;
}

boolean IsLSMFull(ListSetMap SM) {
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
    return SM.Count == MaxElSM;
}

/* ********** Operator Dasar Map ********* */
valuetype ValueLSM(Map M, keytype k) {
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    return Value(M, k);
}

void InsertAtLSM(ListSetMap *SM, int idx, keytype k, valuetype v) {
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsMemberMap((*SM).Elements[idx].M, k)) {
        (*SM).Elements[idx].M.Elements[(*SM).Elements[idx].M.Count].Key = k;
        (*SM).Elements[idx].M.Elements[(*SM).Elements[idx].M.Count].Value = v;
        (*SM).Elements[idx].S.Elements[(*SM).Elements[idx].S.Count] = k;
        (*SM).Elements[idx].S.Count++;
        (*SM).Elements[idx].M.Count++;
    }
}

void DeleteAtLSM(ListSetMap *SM, int idx) {
/* Menghapus Element ke-idx pada LSM */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    int i = idx;
    while (i < (*SM).Count) {
        (*SM).Elements[i] = (*SM).Elements[i+1];
        i++;
    }
    (*SM).Count--;
}

