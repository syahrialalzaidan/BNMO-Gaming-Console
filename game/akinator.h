#ifndef AKINATOR_H
#define AKINATOR_H

#include "../program/ADT/MesinkarkataAkinator/mesinkataakinator.h"
#include "../program/ADT/tree/tree.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"

boolean isStringSameakin(char *c1, char*c2);
/* Mengembalikan true jika string sama */

void namahewan(char* hewan[41]);
/* Membaca nama-nama hewan yang tersedia*/

void jawab(char* jawaban[41], int nomer[41]);
/* Membaca jawaban yang benar*/

void printakinator();
/* Menampilkan tulisan akinator*/

boolean inputcheck(Wordakin W);
/* Mengecek input*/

void playakinator(float *skor); 
/* Program utama untuk menjalankan game*/

#endif