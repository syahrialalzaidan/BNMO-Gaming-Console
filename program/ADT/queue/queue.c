#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q)
{
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    /* Mengirim true jika q kosong: lihat definisi di atas */
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
{
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY;
}

int length(Queue q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1;
    }
}

void enqueue(Queue *q, ElType val)
{
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isFull(*q))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (isEmpty(*q))
        {
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val)
{
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
            q mungkin kosong */
    if (isEmpty(*q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else
        {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    }
}

void displayQueue(Queue q)
{
    /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. q boleh kosong */
    /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika Queue kosong : menulis [] */
    if (isEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        int i;
        printf("[");
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY)
        {
            printf("%s,", q.buffer[i]);
        }
        printf("%s]\n", TAIL(q));
    }
}