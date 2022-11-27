#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "../MesinkarkataAkinator/mesinkarakinator.h"
#include "../MesinkarkataAkinator/mesinkataakinator.h"

#define NILakin NULL
/* Selektor */

typedef char* ElType;
typedef struct tNode* address;
typedef address BinTree;
typedef address Tree;

typedef struct tNode {
    ElType info;
    address left;
    address right;
} Node;

#define INFO(p) (p).info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

/* Definisi PohonBiner */
/* pohon Biner kosong p = NIL */

address newTreeNode (ElType value);

void CreateTree (Tree* tree, address node);
// { I.S. Sembarang }
// { F.S. Menghasilkan sebuah pohon p }
// { Menghasilkan pohon p yang kosong (NIL) jika alokasi gagal }

boolean isTreeEmpty(BinTree tree);

void BuildTree(Tree *t, Tree *root, int x);
/* Dipakai jika input dari pita karakter */
/* I.S. cc berisi '(' */
/* F.S. t terdefinisi */
/* Proses: Membaca isi pita karakter dan membangun pohon secara rekursif, hanya
membutuhkan mesin karakter */

void addLeft (BinTree p, ElType x);

void addRight (BinTree p, ElType x);


#endif