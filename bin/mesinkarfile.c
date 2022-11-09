#include <stdio.h>
#include <stdlib.h>
#include "mesinkarfile.h"

// ASLINYA "mesinkarakter.h"

char currentChar;
boolean EOP;
char* filepath;

static FILE *pita;
static int retval;

void LoadPita(char* filename) {
    filepath = filename;
}

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    // LoadPita(filepath);
    pita = fopen(filepath, "r");
    if (pita == NULL) {
        printf("File tidak ditemukan\n");
    } else {
        ADV();
    }

}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
    retval = fscanf(pita,"%c",&currentChar);
    EOP = IsEOP();
    if (EOP) {
        ungetc(currentChar, pita);
        fclose(pita);
    }
}

char GetCC() {
/* Mengirimkan currentChar */
    return currentChar;
}

boolean IsEOP() {
/* Mengirimkan true jika currentChar = MARK */
    //check if currentChar is EOF
    return (currentChar == EOF || retval == EOF);
}

// function makeword to unite currentchar and the next character
