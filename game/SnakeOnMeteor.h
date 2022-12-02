#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../program/ADT/boolean/boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include "../program/ADT/mesinkarkata/mesinkar.h"
#include "../program/ADT/listdp/listdp.h"

boolean isInputValid(Word kata, int *command);
/* Mengembalikan nilai true jika input valid. */

void addBody(List *L);
/* Menambahkan badan pada snake. */

void makeSnake(List *L);
/* Men-generate snake. 
   I.S.: Snake kosong (belum mempunyai head dan body).
   F.S.: Head dan 2 badan awal di-generate. */

void CutBody(List *L, int MetX, int MetY);
/* Memotong tubuh snake.
   I.S.: Badan snake utuh.
   F.S.: Badan snake berkurang 1. */

void SpawnFood(List snake, int *FoodX, int *FoodY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y);
/* Menghasilkan titik koordinat food secara random. 
   I.S.: Titik koordinat food sembarang.
   F.S.: Titik koordinat food di-generate secara random dengan syarat:
          - Titik koordinat food tidak sama dengan titik koordinat head dan badan snake.
          - Titik koordinat food tidak sama dengan titik koordinat obstacles. 
          Jika tidak memenuhi syarat di atas, maka akan di-generate ulang. */

void SpawnMeteor(List snake, int *MetX, int *MetY, int FoodX, int FoodY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y);
/* Menghasilkan titik koordinat meteor secara random. 
   I.S.: Titik koordinat meteor sembarang.
   F.S.: Titik koordinat meteor di-generate secara random dengan syarat:
          - Titik koordinat meteor tidak sama dengan titik koordinat food. 
          - Titik koordinat meteor tidak sama dengan titik koordinat obstacles. 
          Jika tidak memenuhi syarat di atas, maka akan di-generate ulang. */

void SpawnObstacles(List Snake, int *Obs1X, int *Obs1Y, int *Obs2X, int *Obs2Y, int FoodX, int FoodY);
/*  Menghasilkan titik koordinat obstacles secara random. 
    I.S.: Titik koordinat obstacles sembarang.
    F.S.: Titik koordinat obstacles di-generate secara random dengan syarat:
            - Titik koordinat obstacles tidak sama dengan titik koordinat head dan badan snake. 
            - Titik koordinat obstacles tidak sama dengan titik koordinat food. 
            Jika tidak memenuhi syarat di atas, maka akan di-generate ulang. */

boolean isHit(List snake, int MetX, int MetY);
/* Mengembalikan true jika badan atau head snake terkena meteor. */

void MoveSnake(int command, List *snake, int *FoodX, int *FoodY, int MetX, int MetY, boolean *isHitBody, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y, boolean *isHitObs);
/* Menggerakkan snake.
   I.S.: Snake terletak di dalam map. 
   F.S.: Snake bergerak satu unit bergantung pada masukan:
        - Apabila masukan 'w', maka snake bergerak satu unit ke atas.
        - Apabila masukan 'a', maka snake bergerak satu unit ke kiri.
        - Apabila masukan 's', maka snake bergerak satu unit ke bawah.
        - Apabila masukan 'd', maka snake bergerak satu unit ke kanan.*/

boolean isMoveToBody(int command, List L);
/*  Mengembalikan nilai true jika snake bergerak ke badan snake. */

boolean isMoveToMeteor(int command, List L, int MetX, int MetY);
/*  Mengembalikan nilai true jika snake bergerak ke meteor. */

boolean isSurrounded(List L);
/*  Mengembalikan nilai true jika snake dikelilingi oleh badan sendiri. */

void PrintMapSnake(List L, int FoodX, int FoodY, int MetX, int MetY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y);
/*  Mencetak map snake sesuai titik koordinat dari food, meteor, snake, dan obstacles. */

boolean isGameOver(List snake, int MetX, int MetY, boolean isHitBody, boolean isHitObs);
/*  Mengembalikan nilai true jika permainan berakhir. */

void print_logo_snake();
/* Mencetak logo permainan Snake on Meteor. */

void PlaySnakeOnMeteor(float *skor);
/* Memainkan permainan Snake on Meteor dan mengubah nilai skor
   I.S. skor sembarang
   F.S. Permainan Snake on Meteor dimainkan dan skor berubah ketika permainan berakhir. */