/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATAAKINATOR_H__
#define __MESINKATAAKINATOR_H__

#include "../boolean/boolean.h"
#include "mesinkarakinator.h"

#define NMaxakin 50
// #define BLANK ' '

typedef struct
{
   char TabWord[NMaxakin]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Wordakin;

/* State Mesin Kata */
extern boolean EndWordakin;
extern Wordakin currentWordakin;

void IgnoreBlanksakin();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORDakin();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDakin();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordakin();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int WordToIntakin(Wordakin W);
/* Fungsi mengubah Word ke integer */

char *WordToStringakin(Wordakin W);
/* Fungsi mengubah Word ke string */

boolean isWordSameakin(Wordakin W1, Wordakin W2);
/* Fungsi untuk membandingkan apakah dua kata sama. */

Wordakin stringToWordakin(char *s);
/* Fungsi mengubah string ke Word */

#endif