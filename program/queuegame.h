#ifndef QUEUEGAME_H
#define QUEUEGAME_H

#include <stdio.h>
#include <stdlib.h>
#include "ADT/queue/queue.h"
#include "ADT/mesinkarkata/mesinkata.h"
#include "ADT/arraydin/arraydin.h"
#include "list_game.h"

void queuegame();
/* Mendaftarkan permainan ke dalam list queue.
/* I.S. Queue game mungkin kosong. */
/* F.S. Game ditambahkan ke queue. */

void printqueue(Queue queuegame);
/*  Menampilkan daftar game yang ada di queue ke layar. */

#endif