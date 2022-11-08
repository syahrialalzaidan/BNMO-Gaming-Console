#include "queuegame.h"
/*
#include <stdio.h>
#include "queue.c"
#include "boolean.h"
#include "mesinkata.c"
#include "mesinkar.c"
#include "arraydin.c"
#include <stdlib.h>
#include "queuegame.h"
*/

void queuegame(Queue *queuegame, ArrayDin array){
    int x;
    printf("Berikut adalah daftar antrian game-mu\n");
    if (!isEmpty(*queuegame)){
        listqueue(*queuegame);
    }
    printf("\n");

    listgame(array);
    printf("\n");

    int j;
    printf("Game: \n");
    for (j = 0; j < array.Neff; j++){
        printf("%d. %s\n", j+1, array.A[j]);
    }

    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTWORD();
    x = currentWord.TabWord[0] - '0';
    printf("\n");

    if ((x > array.Neff) || (x < 1)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    } else{
        enqueue(queuegame, array.A[x - 1]);
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}

void listqueue(Queue *queuegame){
    int i;
    for (i = (*queuegame).idxHead; i < (*queuegame).idxTail + 1; i++){
        printf("%s\n", (*queuegame).buffer[i]);
    }
}




/*
int main(){
    Queue q;
    CreateQueue(&q);
    ArrayDin a = MakeArrayDin();
    ElType as, b, c;
    as = "a";
    b = "b";
    c = "c";
    InsertFirst(&a, as);
    InsertLast(&a, b);
    InsertLast(&a, c);

    queuegame(&q, a);
    listqueue(&q);
    queuegame(&q, a);
    listqueue(&q);
    return 0;  
}*/