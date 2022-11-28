#include <stdio.h>
#include "../boolean/boolean.h"
#include "mapchar.h"


/* Definisi MapChar M kosong : M.Count = Nil */
/* M.Count = jumlah element MapChar */
/* M.Elements = tempat penyimpanan element MapChar */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyChar(MapChar *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah MapChar M kosong berkapasitas MaxEl */
/* Ciri MapChar kosong :  count bernilai Nil */
    (*M).Count = NilMap;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapCharEmptyChar(MapChar M){
/* Mengirim true jika MapChar M kosong*/
/* Ciri MapChar kosong : count bernilai Nil */
    return (M.Count == NilMap);
}
boolean IsFullChar(MapChar M){
/* Mengirim true jika MapChar M penuh */
/* Ciri MapChar penuh : count bernilai MaxEl */
    return (M.Count == maxEl);
}
/* ********** Operator Dasar MapChar ********* */
valuetypechar ValueChar(MapChar M, keytype k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */ 
    valuetypechar output = "Undefined";
    boolean found = false;
    int i = 0;
    while (i < M.Count && !found) {
        if ((M.Elements[i]).Key == k){
            found = true;
            output = (M.Elements[i]).Value;
        }
        else {
            i++;
        }
    }
    return output;
    
}

void InsertChar(MapChar *M, keytype k, valuetypechar v){
/* Menambahkan Elmt sebagai elemen MapChar M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsMemberChar(*M,k)) {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v; 
        (*M).Count ++;
    }
}  

void DeleteChar(MapChar *M, keytype k){
/* Menghapus Elmt dari MapChar M. */
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

boolean IsMemberChar(MapChar M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    return ValueChar(M, k) != "Undefined";
}

void sortMapCharchardesc(MapChar *M){
    int i, j;
    infotypeMC temp;
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