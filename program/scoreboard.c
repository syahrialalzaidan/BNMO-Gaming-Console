#include <stdio.h>

#include "scoreboard.h"

int StringLength(char* string) {
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

int CountDigits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
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
        if (maxNameLength < 4) maxScoreLength = 4;
        
        
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
            for (int j = 0; j < maxNameLength - StringLength(M.Elements[i].Key); j++) {
                printf(" ");
            }
            printf("  | %d", M.Elements[i].Value);
            for (int j = 0; j < maxScoreLength - CountDigits(M.Elements[i].Value); j++) {
                printf(" ");
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

int main() {

    return 0;
}