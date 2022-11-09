#include "queue.c"
#include <stdio.h>
#include "../boolean/boolean.h"

int main(){
    printf("Membuat queue\n");
    Queue q;
    CreateQueue(&q);
    displayQueue(q);
    printf("Queue terbuat\n");
    if (isEmpty(q)){
        printf("Queue saat ini kosong\n\n");
    }

    printf("Mengisi queue\n");
    ElType isi;
    isi = "ISI";
    enqueue(&q, isi);
    displayQueue(q);

    if (!isEmpty(q)){
        printf("Queue saat ini tidak kosong\n");
    }
    if (!isFull(q)){
        printf("Queue saat ini tidak full\n");
    }

    int panjang = length(q);
    printf("Panjang queue sekarang: %d\n\n", panjang);

    printf("Menghapus val pada q\n");
    ElType isi2;
    dequeue(&q, &isi2);
    displayQueue(q);
    printf("Val queue yang terambil: %s\n\n", isi2);

    printf("Mengisi queue sampai full\n");
    int i;
    for (i = 0; i < CAPACITY; i++){
        enqueue(&q, isi);
    }
    displayQueue(q);

    if (isFull(q)){
        printf("Queue saat ini full\n");
    }
}