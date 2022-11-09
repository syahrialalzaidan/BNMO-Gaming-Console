#include "start.h"
#include "load.h"

void start(ArrayDin *Games) {
/*  Membaca file konfigurasi default yang berisi list game yang dapat dimainkan
    I.S. : Array Games kosong.
    F.S. : Array games terisi dengan game-game yang ada di dalam file konfigurasi default. */
    load("config.txt", Games);
}