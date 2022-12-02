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
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void CreateTree (Tree* tree, addresst node);
/* Membuat tree baru*/
/* I.S. Sembarang
   F.S. Menghasilkan tree */

boolean isTreeEmpty(BinTree tree);
/* Mengirimkan true tree kosong*/

void BuildTree(Tree *t, Tree *root, int x);
/* Membuat tree dari file txt*/
/* I.S. Sebuah tree untuk dijadikan tree, sebuah tree untuk dijadikan sebagai root, dan integer x untuk mengecek
   F.S. Sebuah tree dan root*/

void addLeft (BinTree p, ElType x);
/* Menambahkan child kiri tree*/
/* I.S. Sebuah tree dan value
   F.S. Menambahkan child kiri pada tree dengan value*/

void addRight (BinTree p, ElType x);
/* Menambahkan child kanan tree*/
/* I.S. Sebuah tree dan value
   F.S. Menambahkan child kanan pada tree dengan value*/


#endif