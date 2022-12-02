#ifndef towerofhanoi_h
#define towerofhanoi_h

#include "../program/ADT/StackHanoi/stackhanoi.h"
#include "../program/ADT/boolean/boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include <unistd.h>
#include <stdio.h>

void printblank(int n);
// I.S. n terdefinisi
// F.S. n spasi tercetak

void printbintang(int n);
/* I.S. n terdefinisi
 * F.S. n bintang tercetak
 */

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
//Memainkan game tower of hanoi




#endif