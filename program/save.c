#include "save.h"
#include "load.h"

void save(ArrayDin *Games, Stack *History, ListSetMap *Scoreboard, char* filename) {
/* Menyimpan state game pada sistem BNMO (e.g. ketika ada penambahan game menggunakan CREATE GAME). */
/* I.S. : Array Games yang diinisialisasi di main.c terdefinisi dan merupakan current state pada sistem.
        Nama file terdefinisi. */
/* F.S. : Isi dari filename akan di-overwrite dengan isi dari array Games. */
    
    FILE *file;
    char* filepath = AddPath(filename); 
    file = fopen(filepath, "w");
    if (file != NULL) {
        fprintf(file, "%d\n", Games->Neff);
        for (int i = 0; i < Games->Neff; i++) {
            if (i == Games->Neff - 1) {
                fprintf(file, "%s", Games->A[i]);
            } else {
                fprintf(file, "%s\n", Games->A[i]);
            }
        }
        fprintf(file, "\n%d\n", nbElmtStack(*History));
        infotype e;
        for (int i = 0; i < nbElmtStack(*History); i++) {
            if (i == nbElmtStack(*History) - 1) {
                fprintf(file, "%s", InfoTop(*History));
            } else {
                fprintf(file, "%s\n", InfoTop(*History));
            }
            Pop(History, &e);
        }
        for (int i = 0; i < Games->Neff; i++) {
            if (i == Games->Neff - 1) {
                fprintf(file, "%d", Scoreboard->Elements[i].M.Count);
            } else if (i == 0) { 
                fprintf(file, "\n%d\n", Scoreboard->Elements[i].M.Count);
            } else {
                fprintf(file, "%d\n", Scoreboard->Elements[i].M.Count);
            }
            for(int j = 0; j < Scoreboard->Elements[i].M.Count; j++) {
                if (i == Scoreboard->Count - 1) {
                    fprintf(file, "%s ", Scoreboard->Elements[i].M.Elements[j].Key);
                    float el = Scoreboard->Elements[i].M.Elements[j].Value;
                    int el1 = (int) el * 100;
                    if (el1 == el * 100) {
                        fprintf(file, "%.0f", el);
                    } else {
                        fprintf(file, "%.2f", el);
                    }
                } else {
                    fprintf(file, "%s ", Scoreboard->Elements[i].M.Elements[j].Key);
                    float el = Scoreboard->Elements[i].M.Elements[j].Value;
                    int el1 = (int) el * 100;
                    if (el1 == el * 100) {
                        fprintf(file, "%.0f\n", el);
                    } else {
                        fprintf(file, "%.2f\n", el);
                    }
                }
            }
        }
        printf("Save file berhasil disimpan ^^\n\n");
        fclose(file);
    }
}