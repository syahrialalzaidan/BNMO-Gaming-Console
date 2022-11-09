#include "queuedinnerdash.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueueDD(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}


/* ********* Prototype ********* */
boolean isEmptyDD(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFullDD(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (lengthDD(q) == CAPACITY);
}

int lengthDD(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmptyDD(q)) {
        return 0;
    } else {
        if (IDX_TAIL(q) < IDX_HEAD(q)) {
            return (CAPACITY - (IDX_HEAD(q) - IDX_TAIL(q) - 1));
        } else {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
}

/* *** Primitif Add/Delete *** */
void enqueueDD(Queue *q, ElType val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmptyDD(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q)++;
    }   
    TAIL(*q) = val;
}

void dequeueDD(Queue *q, ElType *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

/* *** Display Queue *** */
/*void displayQueue(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/*
    printf("[");
    if (!(isEmpty(q))) {
        if (IDX_HEAD(q) <= IDX_TAIL(q)) {
            for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
                printf("%d", q.buffer[i]);
                if (i < IDX_TAIL(q)) {
                    printf(",");
                }
            }
        } else {
            for (int i = IDX_HEAD(q); i < CAPACITY; i++) {
                printf("%d,", q.buffer[i]);
            }
            for (int i = 0; i <= IDX_TAIL(q); i++){
                printf("%d", q.buffer[i]);
                if (i < IDX_TAIL(q)) {
                    printf(",");
                }
            }            
        }
    }
    printf("]\n");
}
*/
void daftarmenu(Queue q){
    //menampilkan daftar pesanan
    printf("Daftar Pesanan\n");
    printf("Makanan \t| Durasi memasak \t| Ketahanan \t| Harga\n");
    printf("--------------------------------------------------------------\n");
    if(!isEmptyDD(q)){
        for(int x = IDX_HEAD(q); x <= IDX_TAIL(q); x++){
            printf("M%d \t\t| %d \t\t\t| %d \t\t| %d\n", q.buffer[x].id,q.buffer[x].durasi,q.buffer[x].ketahanan,q.buffer[x].harga);
        }
    }
    else {
        printf("Menu Kosong\n");
    }
}

void daftarcook(Queue q){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan \t| Sisa durasi memasak\n");
    printf("--------------------------------------\n");
    if(!isEmptyDD(q)){
        for(int x = IDX_HEAD(q); x < lengthDD(q); x++){
            if(q.buffer[x].durasi+1 > 0){
                printf("M%d \t\t| %d \t\t\n", q.buffer[x].id, q.buffer[x].durasi+1);
            }
        }
    }
    else {
        printf("\t\t|\n");
    }
}

void daftarserve(Queue q, Queue q1){
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan \t| Sisa ketahanan makanan\n");
    printf("--------------------------------------\n");
    int count = 0;
    if(!isEmptyDD(q)){
        for(int x = IDX_HEAD(q); x <= IDX_TAIL(q); x++){
            if(q.buffer[x].durasi+1 <= 0 && q.buffer[x].ketahanan >0 && q.buffer[x].id >= IDX_HEAD(q1) && q.buffer[x].id <= IDX_TAIL(q1)){
                printf("M%d \t\t| %d \t\t\n", q.buffer[x].id,q.buffer[x].ketahanan);
                count ++;
            }
        }
        if(count == 0){
        printf("\t\t|\n\n\n");
        }
    }
    else {
        printf("\t\t|\n\n\n");
    }
}
/*
int main() {
    Queue menu,masak;
    CreateQueue(&menu);
    ElType menu1, menu2,menu3;
    menu1.durasi  = 2;
    menu1.id = 1;
    menu1.harga = 15000;
    menu1.ketahanan = 3;
    menu2.durasi  = 3;
    menu2.id = 2;
    menu2.harga = 20000;
    menu2.ketahanan = 5;

    enqueue(&menu, menu1);
    enqueue(&menu, menu2);
    CreateQueue(&masak);
    daftarserve(masak);
}
*/
