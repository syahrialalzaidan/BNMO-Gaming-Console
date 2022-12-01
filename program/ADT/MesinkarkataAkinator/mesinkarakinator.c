#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakinator.h"

// ASLINYA "mesinkarakter.h"

char currentCharakin;
boolean EOPakin;
boolean isFileakin = false;
char* filepathakin;

static FILE *pitaakin;
static int retvalakin;

void LoadPitaAkin(char* filenameakin, boolean isFakin) {
/*  Membaca pita sesuai dengan tipe yang diinginkan (file atau masukan). 
    I.S. : sembarang
    F.S. : Jika pita berbentuk file, maka isFile akan bernilai true 
           dan filepathakin akan berisi nama file beserta path-nya.
           Jika berbentuk masukan maka isFile akan bernilai false. */
    filepathakin = filenameakin;
    isFileakin = isFakin;
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
   F.S. : currentCharakin adalah karakter pertama pada pita
          Jika currentCharakin != MARK maka EOP akan padam (false)
          Jika currentCharakin = MARK maka EOP akan menyala (true) */
    if (isFileakin) {
        pitaakin = fopen(filepathakin, "r");
        if (pitaakin == NULL) {
            printf("404 FILE NOT FOUND X_X \n");
        } else {
            ADVakin();
        }
    } else {
        pitaakin = stdin;
        ADVakin();
    }
}

void ADVakin() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharakin, currentCharakin != MARK
   F.S. : currentCharakin adalah karakter berikutnya dari currentCharakin yang lama,
          currentCharakin mungkin = MARK
          Jika  currentCharakin = MARK maka EOP akan menyala (true) */
    retvalakin = fscanf(pitaakin,"%c",&currentCharakin);
    EOPakin = IsEOPakin();
    if (EOPakin && isFileakin) {
        fclose(pitaakin);
    }
}

char GetCCakin() {
/* Mengirimkan currentCharakin */
    return currentCharakin;
}

boolean IsEOPakin() {
/* Mengirimkan true jika currentCharakin = MARK */
    //check if currentCharakin is blank and the next character is blank  too
    if (!isFileakin) {
        // if (currentCharakin == BLANK) {
        //     char nextChar;
        //     retvalakin = fscanf(pita,"%c",&nextChar);
        //     if (nextChar == BLANK) {
        //         return true;
        //     } else {
        //         ungetc(nextChar,pita);
        //         return false;
        //     }
        // } else {
        //     return (currentCharakin == MARK);
        // }
        return (currentCharakin == MARKakin);
    } else {
        return (currentCharakin == EOF || retvalakin == EOF);
        //return (currentCharakin == MARK);
    }
}

