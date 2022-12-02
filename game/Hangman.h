#include "../program/ADT/Map/mapchar.h"
#include "../program/ADT/Set/sethangman.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include "../program/ADT/Set/set.h"
#include "../program/load.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//gcc -o hangman Hangman.c ../program/ADT/Map/mapchar.c ../program/ADT/Set/sethangman.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c ../program/ADT/Set/set.c ../program/load.c ../program/ADT/Stack/stack.c ../program/ADT/Map/map.c ../program/ADT/arraydin/arraydin.c

//void generatemap(MapChar *kamus);
void loadkamus(char* filename, Set* kamus);
/*  Membaca save file yang berisi list game yang dapat dimainkan.
    I.S. : filename terdefinisi dan array games kosong.
    F.S. : Array games terisi dengan list game yang ada pada save file. */

char UpperHuruf(char input);
/*Mengubah semua huruf kecil ke huruf besar*/

char* UpperKata(char* input);
/*Membuat input kata menjadi huruf besar semua*/

void hangmanart();
/*Animasi kekalahan HAHAHA*/

int countkataHM(char *kata);
/*Menghitung panjang kata*/

void hangmanascii();
/*Animasi hangman*/

void playtebakkataHM(float* scoretotal, float* nyawa);
/*Permainan utama*/

boolean isstringequalHM(char *kata1, char *kata2);
/*Fungsi untuk cek apakah dua string yang dimasukkan sama.
Ini dimanfaatkan untuk memvalidasi masukkan pengguna apakah sesuai KJ*/

void Hangman(float *skor, boolean *playtebakkataHM);
//Fungsi utama yang dipanggil
