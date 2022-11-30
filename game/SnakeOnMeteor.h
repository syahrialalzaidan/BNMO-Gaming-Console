#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../program/ADT/boolean/boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include "../program/ADT/mesinkarkata/mesinkar.h"
#include "../program/ADT/listdp/listdp.h"

boolean isInputValid(Word kata, int *command);

void addBody(List *L);

void makeSnake(List *L);

void CutBody(List *L, int MetX, int MetY);

void SpawnFood(List snake, int *FoodX, int *FoodY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y);

void SpawnMeteor(List snake, int *MetX, int *MetY, int FoodX, int FoodY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y);

void SpawnObstacles(List Snake, int *Obs1X, int *Obs1Y, int *Obs2X, int *Obs2Y, int FoodX, int FoodY);

boolean isHit(List snake, int MetX, int MetY);

void MoveSnake(int command, List *snake, int *FoodX, int *FoodY, int MetX, int MetY, boolean *isHitBody, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y, boolean *isHitObs);

boolean isMoveToBody(int command, List L);

boolean isMoveToMeteor(int command, List L, int MetX, int MetY);

// boolean isMoveBackwards(int command, List L);

boolean isSurrounded(List L);

void PrintMapSnake(List L, int FoodX, int FoodY, int MetX, int MetY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y);

boolean isGameOver(List snake, int MetX, int MetY, boolean isHitBody, boolean isHitObs);

void print_logo_snake();

void PlaySnakeOnMeteor(float *skor);
