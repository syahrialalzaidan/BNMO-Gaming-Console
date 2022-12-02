#include "save.h"
#include "load.h"

void save(ArrayDin *Games, Stack *History, ListMap *Scoreboard, char* filename) {
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
        fprintf(file, "\n%d", nbElmtStack(*History));
        infotype e;
        Stack CopyHistory = ReversedStack(*History);
        if (nbElmtStack(*History) > 0) {
            for (int i = 0; i < nbElmtStack(*History); i++) {
                Pop(&CopyHistory, &e);
                if (i == nbElmtStack(*History) - 1) {
                    fprintf(file, "%s", e);
                } else if (i == 0) {
                    fprintf(file, "\n%s\n", e);
                } else {
                    fprintf(file, "%s\n", e);
                }
            }
        }
        if (Games->Neff != 0) {
            for (int i = 0; i < Games->Neff; i++) {
                if (i == Games->Neff - 1 && Scoreboard->Elmt[i].Count == 0) {
                    fprintf(file, "%d", Scoreboard->Elmt[i].Count);
                } else if (i == 0) { 
                    fprintf(file, "\n%d\n", Scoreboard->Elmt[i].Count);
                } else {
                    fprintf(file, "%d\n", Scoreboard->Elmt[i].Count);
                }
                for(int j = 0; j < Scoreboard->Elmt[i].Count; j++) {
                    if (j == Scoreboard->Elmt[i].Count - 1 && i == Games->Neff - 1) {
                        fprintf(file, "%s ", Scoreboard->Elmt[i].Elements[j].Key);
                        float el = Scoreboard->Elmt[i].Elements[j].Value;
                        int el1 = (int) el * 100;
                        if (el1 == el * 100) {
                            fprintf(file, "%.0f", el);
                        } else {
                            fprintf(file, "%.2f", el);
                        }
                    } else {
                        fprintf(file, "%s ", Scoreboard->Elmt[i].Elements[j].Key);
                        float el = Scoreboard->Elmt[i].Elements[j].Value;
                        int el1 = (int) el * 100;
                        if (el1 == el * 100) {
                            fprintf(file, "%.0f\n", el);          
                        } else {
                            fprintf(file, "%.2f\n", el);
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < Games->Neff; i++) {
                if (i == Games->Neff - 1) {
                    fprintf(file, "%d", 0);
                } else {
                    fprintf(file, "%d\n", 0);
                }
            }
        }
        printf("Save file berhasil disimpan ^^\n\n");
        fclose(file);
    }
}