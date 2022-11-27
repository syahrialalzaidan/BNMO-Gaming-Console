#ifndef AKINATOR_H
#define AKINATOR_H

#include "tree.h"
#include "../program/ADT/MesinkarkataAkinator/mesinkataakinator.h"
#include "../program/ADT/tree/tree.h"

boolean isStringSameakin(char *c1, char*c2);

void namahewan(char* file,char* hewan[41]);

void jawab(char* file, char* jawaban[41], int nomer[41]);

int akinator(); 

#endif