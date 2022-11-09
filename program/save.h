#include "ADT/arraydin/arraydin.h"
#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void save(ArrayDin *Games, char* filename);
/*  Menyimpan state game pada sistem BNMO (e.g. ketika ada penambahan game
    menggunakan CREATE GAME).
    I.S. : Array Games yang diinisialisasi di main.c terdefinisi dan merupakan current state pada sistem.
            Nama file terdefinisi.
    F.S. : Isi dari filename akan di-overwrite dengan isi dari array Games. */