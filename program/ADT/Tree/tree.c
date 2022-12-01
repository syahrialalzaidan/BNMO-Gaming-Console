#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

addresst newTreeNode (ElType value)
/* Membuat tree node baru*/
{
    /* KAMUS LOKAL */
    addresst node;
    Tree p;
    CreateTree(&p, node);
    Node n;

    /* ALGORITMA */
    node = (addresst) malloc(sizeof(Node));
    if (node != NULL) {
        INFO(n) = value;
        n.right = NULL;
        n.left = NULL;
        *node = n;
        return node;
    }
}

boolean isTreeEmpty(BinTree tree){
/* Mengecek apakah tree kosong*/
    return (tree == NILakin);
}

void CreateTree(Tree* tree, addresst node)
/* Membuat tree baru*/
{
  *tree = node;
}


void BuildTree(Tree *t, Tree *root, int x)
/* Membuat tree dari file txt*/
{   /* Kamus Lokal */
    /* Algoritma */
    ADVWORDakin(); /* advance */
    if (currentWordakin.TabWord[0] == ')'){ /* Basis: pohon kosong */
        *t = NILakin;
        if (x == 0){
            *root = *t;
            x++;
        }
    } else { /* Rekurens */
        char* isi = WordToStringakin(currentWordakin);
        *t = newTreeNode(isi);
        if (x == 0){
            *root = *t;
            x++;
        }
        ADVWORDakin(); /* advance */
        BuildTree(&(RIGHT(*t)), root, x);
        BuildTree(&(LEFT(*t)), root, x);
    }
    ADVWORDakin(); /* advance */
}




void addLeft (BinTree p, ElType x){
/* Menambahkan child kiri tree*/
    if (!isTreeEmpty(p)){
        p = newTreeNode(x);
    } else{
        addLeft(LEFT(p), x);
    }
}

void addRight (BinTree p, ElType x){
/* Menambahkan child kanan tree*/
    if (!isTreeEmpty(p)){
        p = newTreeNode(x);
    } else{
        addRight(LEFT(p), x);
    }
}