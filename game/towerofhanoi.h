#ifndef towerofhanoi_h
#define towerofhanoi_h

#include "../program/ADT/StackHanoi/stackhanoi.h"
#include "../program/ADT/boolean/boolean.h"
#include "../program/ADT/mesinkarkata/mesinkata.h"
#include <unistd.h>
#include <stdio.h>

void printblank(int n);


void printbintang(int n);

float optimummove(int n);

boolean isAngka(Word W);

void displaytower(int n, Stack tower1, Stack tower2, Stack tower3);

void printart();

void gameover();

float playtowerofhanoi();





#endif