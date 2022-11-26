#include "Hangman.h"

/*Meng-generate kamus kata yang digunakan untuk permainan*/
void generatemap(Map *kamus){
    Insert(kamus, "mayornaufal", "K01tertampan");
    Insert(kamus, "gibeh", "dinosaurus");
    Insert(kamus, "argentina", "messi");
    Insert(kamus, "swedia", "negara dengan pulau terbanyak");
    Insert(kamus, "alstrukdat", "matkul favorit ariq");
    Insert(kamus, "kalimantan", "pulau terbesar di indonesia");
}

/*Mengubah semua huruf kecil ke huruf besar*/
char UpperHuruf(char input){
    int upperfactor = 'A' - 'a';
    if (input >= 'a' && input <= 'z'){
        input += upperfactor;
    }
    return input;
}

/*Menghitung panjang kata*/
int countkata(char *kata){
    int i=0;
    while (kata[i] != '\0'){
        i++;
    }
    return i;
}

/*Fungsi untuk cek apakah dua string yang dimasukkan sama.
Ini dimanfaatkan untuk memvalidasi masukkan pengguna apakah sesuai KJ*/
boolean isstringequal(char *kata1, char *kata2){
    int i=0;
    if (countkata(kata1) != countkata(kata2)){
        return false;
    }
    while (kata1[i] != '\0'){
        if (kata1[i] != kata2[i]){
            return false;
        }
        i++;
    }
    return true;
}

/*Permainan utama*/
void playtebakkata(int* scoretotal){
    int skor = 0; //Skor game
    time_t t;
    srand(time(&t)); //Seed for random number
    Map kamus;
    CreateEmpty(&kamus); 
    generatemap(&kamus); //Meng-generate kamus kata ke kamus lokal
    boolean win = false;
    int angka = rand() % 6; //Randomize kata yang dipilih
    
    //ADT Set
    Set SKunjaw, SAnswer;
    CreateEmptySet(&SAnswer);
    CreateEmptySet(&SKunjaw);

    //Displaying soal awal
    printf("Tebak Kata dengan benar! (DALAM HURUF BESAR)\n");
    printf("Clue : %s\n", Value(kamus, kamus.Elements[angka].Key));
    int n = 0;
    for(int i=0; i < countkata(kamus.Elements[angka].Key); i++){
        printf("_ ");
        InsertSet(&SKunjaw, kamus.Elements[angka].Key[i]);
        n++;
    }
    printf("(%d huruf)", n);
    printf("\n");
    printf("Masukkan huruf jawaban : ");
    int count = 9;
    
    //Terima input kata
    STARTWORD();

    /*Jika jawaban salah, maka tampil "Jawaban anda salah!" akan diminta memasukkan jawaban ulang*/
    while (! win && count > 0){
        char *guess;
        guess = WordToString(currentWord);
        while(! IsEOP()) ADVWORD();
        boolean found = false;
        found = isstringequal(guess, kamus.Elements[angka].Key);
        if (found){
            printf("Selamat jawaban anda benar! Kamu berhasil menebak kata %s!\n", kamus.Elements[angka].Key);
            printf("Anda mendapatkan %d poin!\n", n);
            skor += n;
            win = true;
        }
        else {
            printf("Jawaban anda salah!\n");
            printf("Tries remaining : %d\n", count);
            for(int i=0; i < countkata(kamus.Elements[angka].Key); i++){
                printf("_ ");
            }
            printf("(%d huruf)", n);
            printf("\n");
            printf("Masukkan jawaban : ");
            STARTWORD();
        }
        count--;
    }

    if (! win) printf("Mohon maaf, kesempatan habis.\nJawaban benar: %s\n",kamus.Elements[angka].Key);
    (*scoretotal) = skor;
}

//Fungsi utama yang dipanggil
void Hangman(){
    int skortemp, skortotal = 0;
    playtebakkata(&skortemp);
    skortotal += skortemp;

    //Asking for mengulangi permainan
    char valid = 'x';
    //printf("%c\n", valid);
    while (valid != 'y' && valid != 'n' && valid != 'Y' && valid != 'N'){
        printf("Apakah anda ingin bermain lagi? (y/n) : ");
        START();
        valid = currentChar;
        //printf("%c\n", valid);
        if (valid == 'y' || valid == 'Y') //Jika ingin main lagi
        {
        playtebakkata(&skortemp);
        skortotal += skortemp;
        }
        else if (valid == 'n' || valid == 'N'){ //Jika tidak ingin main lagi, game berakhir
        printf("Selamat kamu berhasil mendapatkan %d poin pada game ini!\n", skortotal);
        printf("Selamat mengerjakan tubes lainnya, Bye-bye! :D\n");
        break;
        }
        else {
        printf("Masukkan tidak valid!\n");
        }
    }
    //ALGORITMA MASUKIN SCOREBOARD
}

//Driver test
int main(){
    Hangman();
    srand(0);
    return 0;
}
