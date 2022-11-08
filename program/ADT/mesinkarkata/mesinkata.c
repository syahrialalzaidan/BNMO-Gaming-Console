#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (((currentChar == BLANK) && (!isFile)) || ((isFile) && (currentChar == '\n'))) {
        ADV();
    } 
}

void STARTWORD() {
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    //IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;
    } else { 
        CopyWord();
        // ADV();
        EndWord = false;
    }
}

void ADVWORD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if ((currentChar == BLANK && !isFile) || (EOP && isFile)) {
        EndWord = true;
    } else { 
        EndWord = false;
        CopyWord();
        if (!isFile) {
            IgnoreBlanks();
        }
    }
}

void CopyWord() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    if (isFile) {
        while ((i < NMax) && (currentChar != '\n') && !IsEOP()) {
            currentWord.TabWord[i] = currentChar;
            ADV();
            i++;
        }
    } else {
        while ((currentChar != BLANK) && (i < NMax) && (currentChar != MARK)) {
            currentWord.TabWord[i] = currentChar;
            ADV();
            i++;
        }
    }
    currentWord.Length = i;
}

/* Word Converter Functions */

int WordToInt(Word W) {
/* Mengubah Word menjadi integer
    I.S. : Word W terdefinisi, integer dest belum terdefinisi
    F.S. : integer dest sudah terdefinisi berdasarkan Word W*/   
    int i;
    int temp = 0;
    for (i = 0; i < W.Length; i++){
        if (W.TabWord[i] != BLANK) {
            temp = temp * 10 + (W.TabWord[i] - '0');
        }
    }
    return temp;
}

char *WordToString(Word W) {
    char *x = malloc(W.Length + 1);
    for (int i = 0; i < W.Length; i++) {
        x[i] = W.TabWord[i];
    }
    x[W.Length] = '\0';
    return x;
}

boolean isWordSame(Word K1, Word K2) {
    if (K1.Length != K2.Length) {
        return false;
    } else {
        int i = 0;
        while (i < K1.Length) {
            if (K1.TabWord[i] != K2.TabWord[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
}

Word stringToWord(char *string) {
    Word word;
    int i = 0;
    while(string[i] != '\0') {
        word.TabWord[i] = string[i];
        i++;
    }
    word.Length = i;
    return word;
}