#ifndef towerofhanoi_h
#define towerofhanoi_h

#include "../program/ADT/StackHanoi/stackhanoi.h"
#include "../program/ADT/boolean/boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include <unistd.h>
#include <stdio.h>

void printblank(int n);
/* Mencetak spasi. */

void printbintang(int n);
/* Mencetak bintang dengan jumlah sesuai masukan n. */

float optimummove(int n);
// menghasilkan jumlah langkah minimum untuk menyelesaikan tower of hanoi dengan n disk

boolean isAngka(Word W);
// menghasilkan true jika W merupakan kata yang terdiri dari angka saja

void displaytower(int n, Stack tower1, Stack tower2, Stack tower3);
//Menampilkan tower of hanoi dengan n disk

void printart();
//Menampilkan gambar art tower of hanoi

void gameover();
//Menampilkan gambar art game over

void playtowerofhanoi(float *score, boolean *play);
/* Memainkan permainan Tower of Hanoi dan mengubah nilai skor
   I.S. skor sembarang
   F.S. Permainan Tower of Hanoi dimainkan dan skor berubah ketika permainan berakhir. */

#endif