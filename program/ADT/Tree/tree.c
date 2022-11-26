#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

address newTreeNode (ElType value)
{
    /* KAMUS LOKAL */
    address node;
    Tree p;
    CreateTree(&p, node);
    Node n;

    /* ALGORITMA */
    node = (address) malloc(sizeof(Node));
    if (node != NULL) {
        INFO(n) = value;
        n.right = NULL;
        n.left = NULL;
        *node = n;
        return node;
    }
}
// { Mengirimkan address hasil alokasi sebuah elemen bernilai x }
// { Jika alokasi berhasil, maka address tidak NIL, dan misalnya
// menghasilkan p, maka p↑.info=x, p↑.left=NIL, p↑.right=NIL }
// { Jika alokasi gagal, mengirimkan NIL }

boolean isTreeEmpty(BinTree tree){
    return (tree == NIL);
}

void CreateTree(Tree* tree, address node)
// I.S. Tree sembarang
// F.S. Tree terdefinisi
{
  *tree = node;
}


void BuildTree(Tree *t, Tree *root, int x)
/* Dipakai jika input dari pita karakter */
/* I.S. cc berisi '(' */
/* F.S. t terdefinisi */
/* Proses: Membaca isi pita karakter dan membangun pohon secara rekursif, hanya
membutuhkan mesin karakter */

{   /* Kamus Lokal */
    /* Algoritma */
    ADVWORDakin(); /* advance */
    if (currentWord.TabWord[0] == ')'){ /* Basis: pohon kosong */
        *t = NIL;
        if (x == 0){
            *root = *t;
            x++;
        }
    } else { /* Rekurens */
        char* isi = WordToStringakin(currentWord);
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
// { I.S. p boleh kosong }
// { F.S. p bertambah simpulnya, dengan x sebagai simpul daun terkiri }
// KAMUS LOKAL

// ALGORITMA
    if (!isTreeEmpty(p)){
        p = newTreeNode(x);
    } else{
        addLeft(LEFT(p), x);
    }
}

void addRight (BinTree p, ElType x){
// { I.S. p boleh kosong }
// { F.S. p bertambah simpulnya, dengan x sebagai simpul daun terkiri }
// KAMUS LOKAL

// ALGORITMA
    if (!isTreeEmpty(p)){
        p = newTreeNode(x);
    } else{
        addRight(LEFT(p), x);
    }
}