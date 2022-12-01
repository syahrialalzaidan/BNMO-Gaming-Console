#include <stdio.h>
#include <stdlib.h>
#include "listdp.c"

int main(){
    List l;
    printf("Membuat list baru \n");
    CreateEmptyList(&l);
    if (IsEmpty(l)){
        printf("List kosong\n");
    }
    int panjang = LengthList(l);
    printf("Panjang list: %d\n\n", panjang);
    int a = 1;
    int b = 2;
    printf("Memasukkan isi list\n");
    InsVFirst(&l, a, b);
    if (!IsEmpty(l)){
        printf("List tidak kosong\n\n");
    }
    printf("Menampilkan isi list forward\n");
    PrintForward(l);
    printf("\n\nMenghapus isi list\n");
    DelVLast(&l, &a, &b);
    if (IsEmpty(l)){
        printf("List kosong\n");
    }

    return 0;
}