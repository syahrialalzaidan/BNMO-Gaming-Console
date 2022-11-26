#include "dinnerdash.h"
#include "queuedinnerdash.h"
void generatemenu(Queue *q) {
/* I.S sembarang 
 * F.S terdapat menu baru pada Queue q */

    //Kamus Lokal
    ElType food;
    //Algoritma
    food.durasi = (rand() % 5) + 1;
    food.ketahanan = (rand() % 2) + 1;
    food.harga = ((10000 + rand() % 50000)) % 50000;
    if (isEmptyDD(*q)) food.id = 0;
    else food.id = IDX_TAIL(*q) + 1;
    enqueueDD(q, food);
}

boolean isCook(Word kata) {
/* Mengecek apakah kata merupakan perintah cook */
    //Kamus Lokal
    boolean output = false;
    //Algoritma
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
/* Mengecek apakah kata merupakan perintah skip */
    //Kamus Lokal
    boolean output = false;
    //Algoritma
    if (kata.Length == 4){
        if (kata.TabWord[0] == 'S') {
            if (kata.TabWord[1] == 'K') {
                if (kata.TabWord[2] == 'I') {
                    if (kata.TabWord[3] == 'P') output = true;
                }
            }
        }
    }
    return output;
}

boolean isCommandValid(Word kata) {
/* Mengecek apakah kata merupakan perintah yang valid */
    //Kamus Lokal
    boolean output = false;
    //Algoritma
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
/*Mengecek apakah merupakan digit yang valid*/
    //Kamus Lokal
    boolean output = true;
    //Algoritma
    for (int i = 1; i < kata.Length; i++)
    {
        if (kata.TabWord[i] < '0' || kata.TabWord[i] > '9') output = false;
    }
    return output;
}

int getID(Word kata) {
//Mengembalikan ID dari kata
    //Kamus Lokal
    int output = 0;
    //Algoritma
    if (kata.Length == 2) return kata.TabWord[1] - '0';
    else if (kata.Length == 3) return (kata.TabWord[1] - '0') * 10 + (kata.TabWord[2] - '0');
}

void serve(Queue *q1, Queue *q2, int i, int *saldo, int *count, boolean *sukses) {
/* I.S. q1 terdefinisi, q2 terdefinisi, i terdefinisi, saldo terdefinisi, count terdefinisi, sukses terdefinisi
 * F.S. q1 terdefinisi, q2 terdefinisi, i terdefinisi, saldo terdefinisi, count terdefinisi, sukses terdefinisi */
    //Kamus Lokal
    boolean done = false, found = false;
    ElType food;
    int x = 0;
    //Algoritma
    while (x < lengthDD(*q2) && !found) {
        if ((*q2).buffer[x].id == i) {
            found = true;
            if ((*q2).buffer[x].durasi < 0) done = true;
        }
        else x++;
    }
    if (!found) {
        printf("Makanan belum dimasak\n");
        *sukses = false;
    }
    else {
        if (done) {
            if (i == IDX_HEAD(*q1)) {
                *saldo += (HEAD(*q1).harga);
                dequeueDD(q1, &food);
                printf("Berhasil mengantar M%d\n", i);
                *count++;
                boolean found = false;
                int x = IDX_HEAD(*q2);
                while (x < lengthDD(*q2) && !found) {
                    if ((*q2).buffer[x].id == i) {
                        found = true;
                        (*q2).buffer[x].ketahanan = -1;
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

void printdinnerdash(){
    //Print UI dinnerdash
    printf("  ____  _                   ____            _     \n");
    printf(" |  _ \\(_)_ __   ___ _ __  |  _ \\  __ _ ___| |__  \n");
    printf(" | | | | | '_ \\ / _ \\ '__| | | | |/ _` / __| '_ \\ \n");
    printf(" | |_| | | | | |  __/ |    | |_| | (_| \\__ \\ | | |\n");
    printf(" |____/|_|_| |_|\\___|_|    |____/ \\__,_|___/_| |_|\n\n");
}

void playdinnerdash() {
    //Program utama untuk menjalankan game

    //Kamus Lokal
    int saldo = 0, countserve = 0;
    Queue menu, cook;
    boolean conds = false;
    //Algoritma
    printdinnerdash();
    printf("Selamat Datang di Diner Dash!\n");
    printf("\n");
    srand(time(0));
    // generate menu
    CreateQueueDD(&menu);
    for (int i = 0; i < 3; i++) generatemenu(&menu);
    CreateQueueDD(&cook);
    while (lengthDD(menu) <= 7 && countserve <= 15) {
        // ngelayananin input cook/serve
        if (conds) generatemenu(&menu);
        if (lengthDD(menu) <= 7){
            printf("============================\n\n");
            printf("Saldo: %d\n\n", saldo);
            daftarmenu(menu);
            daftarcook(cook);
            daftarserve(cook, menu);
            printf("MASUKKAN COMMAND: ");
            STARTWORD();
        }
        // system("cls");
        if (isCommandValid(currentWord) && lengthDD(menu) <= 7) {
            boolean masak = isCook(currentWord);
            if (isSkip(currentWord)) conds = true;
            else {
                if(! IsEOP()) ADVWORD();
                Word kedua = currentWord;
                while (! IsEOP()) ADVWORD();
                if (isdigitvalid(kedua) && kedua.TabWord[0] == 'M' && kedua.Length > 1 && kedua.Length <=3) {
                    int foodid = getID(kedua);
                    if (masak && lengthDD(menu) <= 7) {
                        int i = 0;
                        boolean found = false;
                        if (foodid >= IDX_HEAD(menu) && foodid <= (IDX_TAIL(menu))){
                            if (lengthDD(menu) < 7) printf("Berhasil memasak M%d\n", foodid);
                            enqueueDD(&cook, menu.buffer[foodid]);
                            conds = true;
                        }
                        else {
                            printf("Makanan tidak ada di daftar pesanan!\n");
                            conds = false;
                        }
                    }
                    else {
                        if (! masak){
                            if (!isEmptyDD(cook) && lengthDD(menu) <= 7) serve(&menu, &cook, foodid, &saldo, &countserve, &conds);
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
            if (!isEmptyDD(cook) && conds && lengthDD(menu) < 7) {
            for (int j = 0; j < lengthDD(cook); j++) {
                if (cook.buffer[j].durasi >= 0) {
                    cook.buffer[j].durasi--;
                    if (cook.buffer[j].durasi == -1) printf("M%d telah selesai dimasak\n", cook.buffer[j].id);
                }
                else {
                    if (cook.buffer[j].ketahanan > 0){
                        cook.buffer[j].ketahanan--;
                        if (cook.buffer[j].ketahanan == 0){
                            printf("Makanan M%d telah hangus\n", cook.buffer[j].id);
                            cook.buffer[j].id = 999;
                            }
                        }
                    }
                }
            }
        }
        else conds = false;
        while (! IsEOP()) ADVWORD();   
        printf("\n");
    }
    printf("Permainan telah selesai. Anda mendapatkan %d poin.\n", saldo);
}

/*
int main() {
    srand(time(0));
    playdinnerdash();
    return 0;
}
*/