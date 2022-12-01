#include <stdio.h>
#include <stdlib.h>
#include "mesinkataakinator.h"

boolean EndWordakin;
Wordakin currentWordakin;

void IgnoreBlanksakin() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (((currentCharakin == BLANK) && (!isFileakin)) || ((isFileakin) && (currentCharakin == ',')) || ((isFileakin) && (currentCharakin == BLANK))) {
        ADVakin();
    } 
}

void STARTWORDakin() {
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    STARTakin();
    //IgnoreBlanks();
    if (IsEOPakin()) {
        EndWordakin = true;
    } else { 
        CopyWordakin();
        // ADV();
        EndWordakin = false;
    }
}

void ADVWORDakin() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanksakin();
    if ((currentCharakin == BLANK && !isFileakin) || (EOPakin && isFileakin)) {
        EndWordakin = true;
    } else { 
        EndWordakin = false;
        CopyWordakin();
        if (!isFileakin) {
            IgnoreBlanksakin();
        }
    }
}

void CopyWordakin() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    if (isFileakin) {
        while ((i < NMax) && (currentCharakin != ',') && !IsEOPakin()) {
            currentWord.TabWord[i] = currentCharakin;
            ADVakin();
            i++;
        }
    } else {
        char y = 'y';
        char n = 'n';
        while ((currentCharakin != BLANK) && (i < NMax) && (currentCharakin != MARK)) {
            currentWord.TabWord[i] = currentCharakin;
            ADVakin();
            i++;
        }
    }
    currentWordakin.Length = i;
}

/* Word Converter Functions */

int WordToIntakin(Wordakin W) {
/* Fungsi mengubah Word ke integer */  
    int i;
    int temp = 0;
    for (i = 0; i < W.Length; i++){
        if (W.TabWord[i] != BLANK) {
            temp = temp * 10 + (W.TabWord[i] - '0');
        }
    }
    return temp;
}

char *WordToStringakin(Wordakin W) {
/* Fungsi mengubah Word ke string */
    char *x = malloc(W.Length + 1);
    for (int i = 0; i < W.Length; i++) {
        x[i] = W.TabWord[i];
    }
    x[W.Length] = '\0';
    return x;
}

boolean isWordSameakin(Wordakin W1, Wordakin W2) {
/* Fungsi untuk membandingkan apakah dua kata sama. */
    if (W1.Length != W2.Length) {
        return false;
    } else {
        int i = 0;
        while (i < W1.Length) {
            if (W1.TabWord[i] != W2.TabWord[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
}

Wordakin stringToWordakin(char *s) {
/* Fungsi mengubah string ke Word */
    Wordakin W;
    int i = 0;
    while (s[i] != '\0') {
        W.TabWord[i] = s[i];
        i++;
    }
    W.Length = i;
    return W;
}