#include "load.h"
#include "history.h"
#include "scoreboard.h"
#include "ADT/listSetMap/listSetMap.h"
#include "save.h"
// gcc save.c ADT/listSetMap/listSetMap.c scoreboard.c history.c load_driver.c load.c ADT/mesinkarkata/mesinkar.c ADT/mesinkarkata/mesinkata.c ADT/arraydin/arraydin.c ADT/Stack/stack.c ADT/Map/map.c -o load_driver

int main() {
    ArrayDin Games = MakeArrayDin();
    Stack History;
    ListSetMap scoreboard;
    CreateEmptyStack(&History);
    CreateEmptyLSM(&scoreboard);
    
    load("savefile1.txt", &Games, &History, &scoreboard);
    // games
    PrintArrayDin(Games);

    // history
    PrintHistory(History, 5);
    printf("\n");
    
    // scoreboard
    printf("**** SCOREBOARD GAME RNG ****\n");
    PrintScoreboard(scoreboard.Elements[0].M);
    printf("\n");
    printf("**** SCOREBOARD GAME Diner Dash ****\n");
    PrintScoreboard(scoreboard.Elements[1].M);
    printf("\n");
    printf("**** SCOREBOARD GAME Hangman ****\n");
    PrintScoreboard(scoreboard.Elements[2].M);
    printf("\n");
    printf("**** SCOREBOARD GAME Tower of Hanoi ****\n");
    PrintScoreboard(scoreboard.Elements[3].M);
    printf("\n");
    printf("**** SCOREBOARD GAME Snake on Meteor ****\n");
    PrintScoreboard(scoreboard.Elements[4].M);
    printf("\n");
    printf("**** SCOREBOARD GAME Game Asal ****\n");
    PrintScoreboard(scoreboard.Elements[5].M);
    printf("\n");
    //print set manually
    printf("**** SET GAME ****\n");
    int i = 0;
    while (i < scoreboard.Count) {
        int j = 0;
        printf("%d.\n", i+1);
        while (j < scoreboard.Elements[i].S.Count) {
            printf("%s\n", scoreboard.Elements[i].S.Elements[j]);
            j++;
        }
        i++;
    }
    save(&Games, &History, &scoreboard, "savefile2.txt");
    return 0;
}