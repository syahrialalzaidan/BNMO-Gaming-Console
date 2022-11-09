#include <stdio.h>
#include <stdlib.h>
#include "arraydin.c"

int main(){
    printf("Membuat arraydin\n");
    ArrayDin array = MakeArrayDin();
    printf("Arraydin telah terbuat\n");
    PrintArrayDin(array);
    if (IsEmpty(array)){
        printf("Arraydin saat ini kosong\n");
    }
    int kapasitas = GetCapacity(array);
    printf("Kapasitas arraydin: %d\n\n", kapasitas);

    ElType isi1 = "ISI";
    ElType isi2 = "ISI 2";
    ElType isi3 = "ISI 3";
    printf("Insert first arraydin\n");
    InsertFirst(&array, isi1);
    PrintArrayDin(array);

    printf("Insert last arraydin\n");
    InsertLast(&array, isi2);
    PrintArrayDin(array);

    printf("Insert di idx 1\n");
    InsertAt(&array, isi3, 1);
    PrintArrayDin(array);

    printf("\n");
    printf("Copy arraydin\n");
    ArrayDin Copy = CopyArrayDin(array);
    PrintArrayDin(Copy);

    /*
    printf("\n");
    printf("Reverse arraydin\n");
    ReverseArrayDin(&array);
    PrintArrayDin(array);
    printf("\n");
    */

    printf("Mencari Index arraydin ISI 3\n");
    IdxType x = SearchArrayDin(array, isi3);
    printf("index isi 3: %d\n\n", x);

    printf("Mengambil arraydin index 1\n");
    ElType index1 = Get(array, 1);
    printf("index 1: %s\n", index1);

    printf("\n");
    printf("Isi arraydin sekarang: ");
    PrintArrayDin(array);

    printf("\n");
    printf("Delete index 1 arraydin\n");
    DeleteAt(&array, 1);
    PrintArrayDin(array);

    printf("\n");
    printf("Delete last arraydin\n");
    DeleteLast(&array);
    PrintArrayDin(array);

    printf("\n");
    printf("Delete first arraydin\n");
    DeleteFirst(&array);
    PrintArrayDin(array);
}
