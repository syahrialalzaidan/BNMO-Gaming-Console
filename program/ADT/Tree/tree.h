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
typedef struct tNode* addresst;
typedef addresst BinTree;
typedef addresst Tree;

typedef struct tNode {
    ElType info;
    addresst left;
    addresst right;
} Node;

#define INFO(p) (p).info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

/* Definisi PohonBiner */
/* pohon Biner kosong p = NIL */

addresst newTreeNode (ElType value);
/* Membuat tree node baru*/

void CreateTree (Tree* tree, addresst node);
/* Mengecek apakah tree kosong*/

boolean isTreeEmpty(BinTree tree);
/* Membuat tree baru*/

void BuildTree(Tree *t, Tree *root, int x);
/* Membuat tree dari file txt*/

void addLeft (BinTree p, ElType x);
/* Menambahkan child kiri tree*/

void addRight (BinTree p, ElType x);
/* Menambahkan child kanan tree*/


#endif