#include "save.h"
#include "load.h"

void save(ArrayDin *Games, char* filename) {
/*  Menyimpan state game pada sistem BNMO (e.g. ketika ada penambahan game
    menggunakan CREATE GAME).
    I.S. : Array Games yang diinisialisasi di main.c terdefinisi dan merupakan current state pada sistem.
            Nama file terdefinisi.
    F.S. : Isi dari filename akan di-overwrite dengan isi dari array Games. */
    
    FILE *file;
    char* filepath = AddPath(filename); 
    file = fopen(filepath, "w");
    if (file != NULL) {
        fprintf(file, "%d\n", Games->Neff);
        //overwrite file per line with contents of games
        for (int i = 0; i < Games->Neff; i++) {
            if (i == Games->Neff - 1) {
                fprintf(file, "%s", Games->A[i]);
            } else {
                fprintf(file, "%s\n", Games->A[i]);
            }
        }
        printf("Save file berhasil disimpan ^^\n\n");
        fclose(file);
    }
}