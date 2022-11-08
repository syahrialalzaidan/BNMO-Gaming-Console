#include "dinnerdash.h"

void generatemenu(Queue *q) {
    ElType food;
    food.durasi = (rand() % 5) + 1;
    food.ketahanan = (rand() % 5) + 1;
    food.harga = ((10000) + rand() % 50000);
    if (isEmpty(*q)) food.id = 0;
    else food.id = IDX_TAIL(*q) + 1;
    enqueue(q, food);
}

boolean isCook(Word kata) {
    boolean output = false;
    if (kata.Length == 4) {
        if (kata.TabWord[0] == 'C') {
            if (kata.TabWord[1] == 'O') {
                if (kata.TabWord[2] == 'O') {
                    if (kata.TabWord[3] == 'K') output = true; 
                }
            }
        }
    }
    return output;
}

boolean isSkip(Word kata){
    boolean output = false;
    if (kata.TabWord[0] == 'S') {
        if (kata.TabWord[1] == 'K') {
            if (kata.TabWord[2] == 'I') {
                if (kata.TabWord[3] == 'P') output = true;
            }
        }
    }
    return output;
}

boolean isCommandValid(Word kata) {
    boolean output = false;
    if (kata.Length == 5) {
        if (kata.TabWord[0] == 'S') {
            if (kata.TabWord[1] == 'E') {
                if (kata.TabWord[2] == 'R'){
                    if (kata.TabWord[3] == 'V') {
                        if (kata.TabWord[4] == 'E') output = true;
                    }
                }
            }
        }
    }
    else {
        if (kata.Length == 4) {
            if (isCook(kata)) output = true;
            if (kata.TabWord[0] == 'S') {
                if (kata.TabWord[1] == 'K') {
                    if (kata.TabWord[2] == 'I') {
                        if (kata.TabWord[3] == 'P') output = true;
                    }
                }
            }
        }
    }
    return output;
}

boolean isdigitvalid(Word kata) {
    boolean output = true;
    for (int i = 1; i < kata.Length; i++)
    {
        if (kata.TabWord[i] < '0' || kata.TabWord[i] > '9') output = false;
    }
    return output;
}

int getID(Word kata) {
    int output = 0;
    if (kata.Length == 2) return kata.TabWord[1] - '0';
    else if (kata.Length == 3) return (kata.TabWord[1] - '0') * 10 + (kata.TabWord[2] - '0');
}

void serve(Queue *q1, Queue *q2, int i, int *saldo, int *count, boolean *sukses) { // q1 = menu; q2 = cook; i = id
    boolean done = false, found = false;
    ElType food;
    int x = 0;
    while (x < length(*q2) && !found) {
        if ((*q2).buffer[x].id == i) {
            found = true;
            if ((*q2).buffer[x].durasi <= 0) done = true;
        }
        else x++;
    }
    if (!found) {
        printf("Masakan belum dimasak\n");
        *sukses = false;
    }
    else {
        if (done) {
            if (i == IDX_HEAD(*q1)) {
                dequeue(q1, &food);
                printf("Berhasil mengantar M%d\n", i);
                *count++;
                *saldo += (HEAD(*q1).harga);
                boolean found = false;
                int x = IDX_HEAD(*q2);
                while (x < length(*q2) && !found) {
                    if ((*q2).buffer[x].id == i) {
                        found = true;
                        (*q2).buffer[x].ketahanan = 0;
                    }
                    else x++;  
                }
                *sukses = true;
            }
            else {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", i, IDX_HEAD(*q1));
                *sukses = false;
            }
        }
        else {
            printf("M%d belum selesai dimasak\n", i);
            *sukses = false;
        }
    }
}

void playdinnerdash() {
    printf("Selamat Datang di Diner Dash!\n");
    printf("\n");
    int saldo = 0, countserve = 0;
    srand(time(0));
    // generate menu
    Queue menu;
    CreateQueue(&menu);
    for (int i = 0; i < 3; i++) generatemenu(&menu);
    Queue cook;
    CreateQueue(&cook);
    boolean conds = false;
    while (length(menu) <= 7 && countserve <= 15) {
        // ngelayananin input cook/serve
        printf("============================\n\n");
        printf("Saldo: %d\n\n", saldo);
        daftarmenu(menu);
        daftarcook(cook);
        daftarserve(cook, menu);
        printf("MASUKKAN COMMAND: ");
        STARTWORD();
        if (conds) generatemenu(&menu);
        if (isCommandValid(currentWord) && length(menu) <= 8) {
            boolean masak = isCook(currentWord);
            conds = true;
            if (isSkip(currentWord)) conds = true;
            else {
                if(! IsEOP()) ADVWORD();
                Word kedua = currentWord;
                if (isdigitvalid(kedua) && kedua.TabWord[0] == 'M' && kedua.Length > 1 && kedua.Length <=3) {
                    int foodid = getID(kedua);
                    if (masak && length(menu) < 8) {
                        int i = 0;
                        boolean found = false;
                        if (foodid >= IDX_HEAD(menu) && foodid <= (IDX_TAIL(menu)-1)){
                            printf("Berhasil memasak M%d\n", foodid);
                            enqueue(&cook, menu.buffer[foodid]);
                        }
                        else {
                            printf("Makanan tidak ada di daftar pesanan!\n");
                            conds = false;
                        }
                    }
                    else {
                        if (! masak){
                            if (!isEmpty(cook) && length(menu) <= 8) serve(&menu, &cook, foodid, &saldo, &countserve, &conds);
                            else {
                                printf("Anda belum memasak makanan\n");
                                conds = false;
                            }
                        }
                    }
                    // Buat ngurangin durasi/ketahanan
                    
                }
                else conds = false;
            }   
            if (!isEmpty(cook) && conds && length(menu) < 8) {
            for (int j = 0; j < length(cook); j++) {
                if (cook.buffer[j].durasi >= 0) {
                    cook.buffer[j].durasi--;
                    if (cook.buffer[j].durasi == -1) printf("M%d telah selesai dimasak\n", cook.buffer[j].id);
                }
                else {
                    if (cook.buffer[j].ketahanan > 0) cook.buffer[j].ketahanan--;
                }
            }
        }
        }
        while (! IsEOP()) ADVWORD();
        printf("\n");
    }
    printf("Permainan telah selesai. Anda mendapatkan %d poin.\n", saldo);
}

int main() {
    srand(time(0));
    playdinnerdash();
    return 0;
}