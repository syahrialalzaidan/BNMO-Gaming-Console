#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

addresst newTreeNode (ElType value)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
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
/* Mengirimkan true tree kosong*/
    return (tree == NILakin);
}

void CreateTree(Tree* tree, addresst node)
/* Membuat tree baru*/
/* I.S. Sembarang
   F.S. Menghasilkan tree */
{
  *tree = node;
}


void BuildTree(Tree *t, Tree *root, int x)
/* Membuat tree dari file txt*/
/* I.S. Sebuah tree untuk dijadikan tree, sebuah tree untuk dijadikan sebagai root, dan integer x untuk mengecek
   F.S. Sebuah tree dan root*/
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
/* I.S. Sebuah tree dan value
   F.S. Menambahkan child kiri pada tree dengan value*/
    if (!isTreeEmpty(p)){
        p = newTreeNode(x);
    } else{
        addLeft(LEFT(p), x);
    }
}

void addRight (BinTree p, ElType x){
/* Menambahkan child kanan tree*/
/* I.S. Sebuah tree dan value
   F.S. Menambahkan child kanan pada tree dengan value*/
    if (!isTreeEmpty(p)){
        p = newTreeNode(x);
    } else{
        addRight(LEFT(p), x);
    }
}