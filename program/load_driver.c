#include "load.h"
#include "history.h"
#include "scoreboard.h"
#include "save.h"
// gcc program/save.c program/scoreboard.c program/history.c program/load_driver.c program/load.c program/ADT/mesinkarkata/mesinkar.c program/ADT/mesinkarkata/mesinkata.c program/ADT/arraydin/arraydin.c program/ADT/Stack/stack.c program/ADT/Map/map.c -o load_driver

int main() {
    ArrayDin Games = MakeArrayDin();
    Stack History;
    ListMap scoreboard;
    CreateEmptyStack(&History);
    CreateEmptyLM(&scoreboard);
    
    load("savefile1.txt", &Games, &History, &scoreboard);
    // games
    PrintArrayDin(Games);

    // history
    PrintHistory(History, 5);
    printf("\n");
    
    // scoreboard
    printf("**** SCOREBOARD GAME RNG ****\n");
    PrintScoreboard(scoreboard.Elmt[0]);
    printf("\n");
    printf("**** SCOREBOARD GAME Diner Dash ****\n");
    PrintScoreboard(scoreboard.Elmt[1]);
    printf("\n");
    printf("**** SCOREBOARD GAME Diner Dash ****\n");
    PrintScoreboard(scoreboard.Elmt[2]);
    printf("\n");
    printf("**** SCOREBOARD GAME Hangman ****\n");
    PrintScoreboard(scoreboard.Elmt[3]);
    printf("\n");
    printf("**** SCOREBOARD GAME Tower of Hanoi ****\n");
    PrintScoreboard(scoreboard.Elmt[4]);
    printf("\n");
    printf("**** SCOREBOARD GAME Snake on Meteor ****\n");
    PrintScoreboard(scoreboard.Elmt[5]);
    printf("\n");
    printf("**** SCOREBOARD GAME Akinator ****\n");
    PrintScoreboard(scoreboard.Elmt[6]);
    printf("\n");
    printf("scoreboard.neff = %d\n", scoreboard.Neff);
    //print set manually
    // printf("**** SET GAME ****\n");
    // int i = 0;
    // while (i < scoreboard.Count) {
    //     int j = 0;
    //     printf("%d.\n", i+1);
    //     while (j < scoreboard.Elements[i].S.Count) {
    //         printf("%s\n", scoreboard.Elements[i].S.Elements[j]);
    //         j++;
    //     }
    //     i++;
    // }
    save(&Games, &History, &scoreboard, "savefile2.txt");
    return 0;
}