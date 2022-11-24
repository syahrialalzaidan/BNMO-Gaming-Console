#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../program/ADT/boolean/boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include "../program/ADT/mesinkarkata/mesinkar.h"
#include "../program/ADT/listdp/listdp.h""

boolean isInputValid(Word kata, int *command);

void addBody(List *L);

void makeSnake(List *L);

void CutBody(List *L, int MetX, int MetY);

void SpawnFood(List snake, int *FoodX, int *FoodY);

void SpawnMeteor(List snake, int *MetX, int *MetY, int FoodX, int FoodY);

boolean isHit(List snake, int MetX, int MetY);

void MoveSnake(int command, List *snake, int *FoodX, int *FoodY, int MetX, int MetY, boolean *isHitBody);

boolean isMoveToMeteor(int command, List L, int MetX, int MetY);

boolean isMoveBackwards(int command, List L);

void PrintMapSnake (List L, int FoodX, int FoodY, int MetX, int MetY);

boolean isGameOver(List snake, int MetX, int MetY, boolean isHitBody);

void PlaySnakeOnMeteor(int *skor);
