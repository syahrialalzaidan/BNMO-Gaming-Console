#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    if (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD(){
    /* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (IsEOP()){
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWord();
    }
}


void ADVWORD() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;
    }
    else{
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(){
    int i = 0;
    while (! IsEOP() && currentChar != BLANK && i < NMax) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax) {
        currentWord.Length = NMax;
    }
    else{
        currentWord.Length = i;
    }
}