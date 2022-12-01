#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakinator.h"

// ASLINYA "mesinkarakter.h"

char currentChar;
boolean EOP;
boolean isFileakin = false;
char* filepath;

static FILE *pita;
static int retval;

void LoadPitaAkin(char* filename, boolean isF) {
/*  Membaca pita sesuai dengan tipe yang diinginkan (file atau masukan). 
    I.S. : sembarang
    F.S. : Jika pita berbentuk file, maka isFileakin akan bernilai true 
           dan filepath akan berisi nama file beserta path-nya.
           Jika berbentuk masukan maka isFileakin akan bernilai false. */
    filepath = filename;
    isFileakin = isF;
}

void StopLoadPitaAkin() {
/*  Menghentikan pembacaan file. 
    I.S. : File telah dibaca.
    F.S. : Pembacaan file dihentikan. */
    isFileakin = false;
}

void STARTakin() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    if (isFileakin) {
        pita = fopen(filepath, "r");
        if (pita == NULL) {
            printf("404 FILE NOT FOUND X_X \n");
        } else {
            ADVakin();
        }
    } else {
        pita = stdin;
        ADVakin();
    }
}

void ADVakin() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
    retval = fscanf(pita,"%c",&currentChar);
    EOP = IsEOPakin();
    if (EOP && isFileakin) {
        fclose(pita);
    }
}

char GetCCakin() {
/* Mengirimkan currentChar */
    return currentChar;
}

boolean IsEOPakin() {
/* Mengirimkan true jika currentChar = MARK */
    //check if currentChar is blank and the next character is blank  too
    if (!isFileakin) {
        // if (currentChar == BLANK) {
        //     char nextChar;
        //     retval = fscanf(pita,"%c",&nextChar);
        //     if (nextChar == BLANK) {
        //         return true;
        //     } else {
        //         ungetc(nextChar,pita);
        //         return false;
        //     }
        // } else {
        //     return (currentChar == MARK);
        // }
        return (currentChar == MARK);
    } else {
        return (currentChar == EOF || retval == EOF);
        //return (currentChar == MARK);
    }
}

