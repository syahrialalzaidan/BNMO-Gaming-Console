#include <stdio.h>
#include "../boolean/boolean.h"
#include "map.h"


/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong :  count bernilai Nil */
    (*M).Count = NilMap;
}

void CreateEmptyLM(ListMap *LM){
    (*LM).Neff = NilMap;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M){
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
    return (M.Count == NilMap);
}

boolean IsLMEmpty(ListMap LM) {
    return (LM.Neff == NilMap);
}
boolean IsFull(Map M){
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
    return (M.Count == MaxEl);
}
/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */ 
    valuetype output = Undefined;
    boolean found = false;
    int i = 0;
    while (i < M.Count && !found) {
        if (isWordSame(stringToWord(M.Elements[i].Key), stringToWord(k))) {
            found = true;
            output = (M.Elements[i]).Value;
        }
        else {
            i++;
        }
    }
    return output;
    
}

void Insert(Map *M, keytype k, valuetype v){
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsMemberMap(*M,k)) {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v; 
        (*M).Count++;
    }
}  

// void InsertMapAt(ListMap *LM, Map M, addressMap i) {
//     if (i < MaxEl) {
//         (*LM).Elmt[i] = M;
//         (*LM).Neff++;
//     }
// }

void DeleteMap(Map *M, keytype k){
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    boolean found = false;
    int i = 0;
    while (i < (*M).Count && !found) {
        if (((*M).Elements[i]).Key == k){
            found = true;
        }
        else {
            i++;
        }
    }
    for(i; i < (*M).Count-1; i++){
        (*M).Elements[i] = (*M).Elements[i+1];
    }
    (*M).Count--;
}

void DeleteMapAt(ListMap *LM, addressMap i) {
    for (i; i < (*LM).Neff-1; i++) {
        (*LM).Elmt[i] = (*LM).Elmt[i+1];
    }
    (*LM).Neff--;
}

boolean IsMemberMap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    return Value(M, k) != Undefined;
}

void sortmapdesc(Map *M){
    int i, j;
    infotypeMap temp;
    for (i = 0; i < (*M).Count; i++) {
        for (j = i+1; j < (*M).Count; j++) {
            if ((*M).Elements[i].Value < (*M).Elements[j].Value) {
                temp = (*M).Elements[i];
                (*M).Elements[i] = (*M).Elements[j];
                (*M).Elements[j] = temp;
            }
        }
    }
}