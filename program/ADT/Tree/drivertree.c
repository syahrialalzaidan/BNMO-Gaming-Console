#include "tree.c"
#include <stdio.h>
#include <stdlib.h>
#include "../MesinkarkataAkinator/mesinkarakinator.c"
#include "../MesinkarkataAkinator/mesinkataakinator.c"
#include "../boolean/boolean.h"

int main(){
    printf("Membaca file txt\n");
    LoadPitaAkin("./program/ADT/Tree/tree.txt", true);
    STARTWORDakin();

    printf("Membuat tree dan address\n");
    Tree pohon1, pohon2, pohon3;
    addresst p, pp, ppp;
    int stop = 0;

    printf("Membuat tree\n");
    CreateTree(&pohon1, p);
    CreateTree(&pohon2, pp);
    CreateTree(&pohon3, ppp);
    if (isTreeEmpty(pohon1)){
        printf("Tree sudah terbuat\n\n");
    }
    BuildTree(&pohon1, &pohon2, stop);
    pohon3 = pohon2;
    printf("Isi pertama dari tree: %s\n", INFO(*pohon3));
    printf("Isi dari tree kanan pertama: %s\n", INFO(*RIGHT(pohon3)));
    printf("Isi dari tree kiri pertama: %s\n", INFO(*LEFT(pohon3)));
    return 0;
}