#include "Hangman.h"
//gcc -o hangman Hangman.c ../program/ADT/Map/map.c ../program/ADT/Set/set.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c

/*Meng-generate kamus kata yang digunakan untuk permainan*/
void generatemap(Map *kamus){
    Insert(kamus, "MAYORNAUFAL", "K01tertampan");
    Insert(kamus, "GIBEH", "dinosaurus");
    Insert(kamus, "ARGENTINA", "messi");
    Insert(kamus, "SWEDIA", "negara dengan pulau terbanyak");
    Insert(kamus, "ALSTRUKDAT", "matkul favorit ariq");
    Insert(kamus, "KALIMANTAN", "pulau terbesar di indonesia");
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
    printf("Selamat Datang di Hangman!\nTebak kata berikut dengan benar! (DALAM HURUF BESAR)\n");
    int n = 0;

    //Buat set kunjaw
    for(int i=0; i < countkata(kamus.Elements[angka].Key); i++){
        InsertSet(&SKunjaw, kamus.Elements[angka].Key[i]);
        n++;
    }
    int nyawa = 10;

    //Rilis soal
    while (!IsSubsetSet(SAnswer, SKunjaw) && nyawa > 0){
        //Cetak soal setelah ditebak
        printf("\nClue : %s\n", Value(kamus, kamus.Elements[angka].Key));
        printf("Huruf yang udah kamu tebak : ");
        PrintSet(SAnswer);
        //printf("\n");

        for(int i=0; i < countkata(kamus.Elements[angka].Key); i++){
            if (IsMember(SAnswer, kamus.Elements[angka].Key[i])){
                printf("%c ", kamus.Elements[angka].Key[i]);
            }
            else{
                printf("_ ");
            }
        }
        printf("(%d huruf)\n", n);
        printf("Sisa nyawa kamu : %d\n", nyawa);
        printf("Masukkan huruf jawaban : ");
        START();  //Diasumsikan input selalu character, bukan string
        currentChar = UpperHuruf(currentChar); //Memastikan semua input dalam Uppercase

        //Saat jawaban salah jika kondisinya Huruf belum pernah ditebak tapi memang tidak ada di kunjaw
        //Tidak salaah jika kondisinya huruf pernah ditebak
        if (!IsMember(SKunjaw, currentChar) && !IsMember(SAnswer, currentChar))
        {
            nyawa--;
            printf("\n-------------------\n");
            printf("Jawaban kamu salah!\n");
            printf("-------------------\n");
        }
        else if (IsMember(SAnswer, currentChar)){
            printf("\n-----------------------\n");
            printf("Huruf %c sudah kamu tebak\n", currentChar);
            printf("-------------------------\n");
        }
        InsertSet(&SAnswer, currentChar);
        while (! IsEOP()) ADV();
}
    
    //Saat jawaban benar
    if (IsSubsetSet(SAnswer, SKunjaw)){
        printf("Selamat jawaban kamu benar! Kamu berhasil menebak kata %s!\n", kamus.Elements[angka].Key);
        printf("Kamu mendapatkan %d poin!\n\n", n);
        (*scoretotal) = n;
    }

    //Saat kesempatan habis
    else{
        printf("\nMohon maaf, nyawamu habis.\nJawaban yang benar: %s\n",kamus.Elements[angka].Key);
    }
}

//Fungsi utama yang dipanggil
void Hangman(){
    int skortemp, skortotal = 0;
    playtebakkata(&skortemp);
    skortotal += skortemp;

    //Asking for mengulangi permainan
    char valid;
    boolean main_lagi = true;
    printf("\nApakah kamu ingin bermain lagi? (y/n) : ");
    //printf("%c\n", valid);
    while (main_lagi){
        //printf("%c\n", valid);
        START();
        valid = currentChar;
        //printf("%c", valid);
        while (! IsEOP()) ADV();
        if (valid == 'y' || valid == 'Y') //Jika ingin main lagi
        {
        playtebakkata(&skortemp);
        skortotal += skortemp;
        }
        else if (valid == 'n' || valid == 'N'){ //Jika tidak ingin main lagi, game berakhir
        printf("Selamat kamu berhasil mendapatkan %d poin pada game ini!\n", skortotal);
        printf("Selamat mengerjakan tubes lainnya, Bye-bye! :D\n");
        main_lagi = false;
        }
        else {
        printf("Coba pilih antara y atau n, bukan antara kamu atau dia ya :(\n");
        }
        printf("\nApakah kamu ingin bermain lagi? (y/n) : ");
    }
    //ALGORITMA MASUKIN SCOREBOARD
}

//Driver test
int main(){
    Hangman();
    srand(0);
    return 0;
}
