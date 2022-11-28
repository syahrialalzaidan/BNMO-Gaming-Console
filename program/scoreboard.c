#include <stdio.h>
#include "scoreboard.h"
//gcc -o scoreboard scoreboard.c ADT/Map/mapscore.c

int StringLength(char* string) {
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

int CountDigits(float n) {
    int i = (int) n * 100;
    int count = 0;
    while (i != 0) {
        i /= 10.00;
        count++;
    }
    return count+1;
}

boolean isZero (float n) {
/* Fungsi untuk memeriksa apakah bilangan belakang koma adalah 0 */
    int i = (int) n * 100;
    if (i == n * 100) {
        return true;
    } else {
        return false;
    }
}

void PrintScoreboard(Map M) {
    if (!IsMapEmpty(M)) {
        int i = 0;
        //find the longest name
        int maxNameLength = 0, maxScoreLength;
        while (i < M.Count) {
            if (StringLength(M.Elements[i].Key) > maxNameLength) {
                maxNameLength = StringLength(M.Elements[i].Key);
            }
            i++;
        }
        if (maxNameLength < 4) maxNameLength = 4;
        
        //find the longest score
        i = 0;
        int maxScore = M.Elements[0].Value;
        maxScoreLength = CountDigits(maxScore);
        if (maxScoreLength < 4) {
            maxScoreLength = 4;
        }
        i = 0;
        printf("+");
        for (int j = 0; j < maxNameLength + 3; j++) {
            printf("-");
        }
        printf("+");
        for (int j = 0; j < maxScoreLength + 3; j++) {
            printf("-");
        }
        printf("+\n");
        printf("| NAMA");
        for (int j = 0; j < maxNameLength - 4; j++) {
            printf(" ");
        }
        printf("  | SKOR");
        for (int j = 0; j < maxScoreLength - 4; j++) {
            printf(" ");
        }
        printf("  |\n");
        printf("+");
        for (int j = 0; j < maxNameLength + 3; j++) {
            printf("-");
        }
        printf("+");
        for (int j = 0; j < maxScoreLength + 3; j++) {
            printf("-");
        }
        printf("+\n");
        while (i < M.Count)  {
            printf("| %s", M.Elements[i].Key);
            for (int j = 0; j < maxNameLength - StringLength(M.Elements[i].Key) + 2; j++) {
                printf(" ");
            }
            // if 2 digits behind decimal point is 0 then print int
            if (isZero(M.Elements[i].Value)) {
                printf("| %d", (int) M.Elements[i].Value);
                for (int j = 0; j < maxScoreLength - CountDigits(M.Elements[i].Value)+3; j++) {
                    printf(" ");
                }
            } else {
                printf("| %.2f", M.Elements[i].Value);
                for (int j = 0; j < maxScoreLength - CountDigits(M.Elements[i].Value); j++) {
                    printf(" ");
                }
            }
            printf("  |\n");
            i++;
        }
        printf("+");
        for (int j = 0; j < maxNameLength + 3; j++) {
            printf("-");
        }
        printf("+");
        for (int j = 0; j < maxScoreLength + 3; j++) {
            printf("-");
        }
        printf("+\n");
    } else {
        printf("+-------------+------------+\n");
        printf("| NAMA        | SKOR       |\n");
        printf("+-------------+------------+\n");
        printf("—--- SCOREBOARD KOSONG —----\n");
    }
}

void ResetScoreboard(ListMap *LM, ArrayDin G) {
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. All\n");
    for (int i = 0; i < G.Neff; i++) {
        printf("%d. %s\n", i + 1, G.A[i]);
    }
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    STARTWORD();
    int idx = WordToInt(currentWord);
    while (idx < 0 || idx > G.Neff) {
        printf("INPUT TIDAK VALID\n");
        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        STARTWORD();
        idx = WordToInt(currentWord);
    }
    char* str;
    if (idx == 0) {
        str = "All";
    } else {
        str = Get(G, idx-1);
    }
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", Get(G, idx-1));
    STARTWORD();
    while(!isWordSame(currentWord, stringToWord("YA")) && !isWordSame(currentWord, stringToWord("TIDAK"))) 
    {
        printf("Input tidak valid!\n");
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", Get(G, idx));
        STARTWORD();
    }
    if (isWordSame(currentWord, stringToWord("YA"))) {
        if (idx != 0) {
            if (!IsMapEmpty(LM->Elmt[idx])) {
                //make SM->Elements[idx].M empty
                CreateEmpty(&LM->Elmt[idx-1]);
                printf("Scoreboard berhasil di-reset\n");
            } else {
                printf("Scoreboard kosong\n");
            }
        } else {
            for (int i = 0; i < G.Neff; i++) {
                if (!IsMapEmpty(LM->Elmt[i])) {
                    //make SM->Elements[idx].M empty
                    CreateEmpty(&LM->Elmt[i]);
                }
            }
            printf("Scoreboard berhasil di-reset\n");
        }
    } else {
        printf("Scoreboard tidak jadi di-reset. Berikut adalah Scoreboard game %s:\n", Get(G, idx));
        if (idx != 0) {
            PrintScoreboard(LM->Elmt[idx-1]);
            printf("\n");
        } else {
            for (int i = 0; i < G.Neff; i++) {
                printf("Scoreboard game %s:\n", Get(G, i));
                PrintScoreboard(LM->Elmt[i]);
                printf("\n");
            }
        }
    }
}

/* *** For Test Purposes *** */
// int main() {
//     Map score;
//     CreateEmptyScore(&score);
//     InsertScore(&score, "Alan", 100.0);
//     InsertScore(&score, "Alzaidan", 200.0);
//     sortmapdesc(&score);
//     PrintScoreboard(score);

//     return 0;
// 