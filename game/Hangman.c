#include "Hangman.h"
//gcc -o hangman Hangman.c ../program/ADT/Map/mapchar.c ../program/ADT/Set/sethangman.c ../program/ADT/mesinkarkata/mesinkata.c ../program/ADT/mesinkarkata/mesinkar.c ../program/ADT/Set/set.c ../program/load.c ../program/ADT/Stack/stack.c ../program/ADT/Map/map.c ../program/ADT/arraydin/arraydin.c


/*Me-load kamus*/
void loadkamus(char* filename, Set* kamus) {
/*  Membaca save file yang berisi list game yang dapat dimainkan.
    I.S. : filename terdefinisi dan array games kosong.
    F.S. : Array games terisi dengan list game yang ada pada save file. */
    char* filepath = AddPath(filename);
    char* name;
    float score;
    // LoadPita("./data/config.txt");
    LoadPita(filepath, true);
    // load games
    STARTWORD();
    int jmlGame = WordToInt(currentWord);
    int j = 0;
    while (j < jmlGame) {
        ADVWORD();
        char* name = WordToString(currentWord);
        InsertSet(kamus, name);
        j++;
    }
    StopLoadPita();
}

/*Mengubah semua huruf kecil ke huruf besar*/
char UpperHuruf(char input){
    int upperfactor = 'A' - 'a';
    if (input >= 'a' && input <= 'z'){
        input += upperfactor;
    }
    return input;
}

/*Membuat input kata menjadi huruf besar semua*/
char* UpperKata(char* input){
    int i = 0;
    while (input[i] != '\0')
    {
        input[i] = UpperHuruf(input[i]);
        i++;
    }
    return input;
}

/*Animasi kekalahan HAHAHA*/
void hangmanart(){
    printf("\nur dead bruh\n\n");
    printf("  _________\n");
    printf("  |/      |\n");
    printf("  |      (_)\n");
    printf("  |      \\|/\n");
    printf("  |       |\n");
    printf("  |      / \\\n");
    printf("  |\n");
    printf("__|________\n");
    printf("|         |\n");
    printf("|_________|\n");
}

/*Menghitung panjang kata*/
int countkataHM(char *kata){
    int i=0;
    while (kata[i] != '\0'){
        i++;
    }
    return i;
}

/*Fungsi untuk cek apakah dua string yang dimasukkan sama.
Ini dimanfaatkan untuk memvalidasi masukkan pengguna apakah sesuai KJ*/
boolean isstringequalHM(char *kata1, char *kata2){
    int i=0;
    if (countkataHM(kata1) != countkataHM(kata2)){
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

void hangmanascii(){
    printf("HHHHHHHHH     HHHHHHHHH               AAA               NNNNNNNN        NNNNNNNN        GGGGGGGGGGGGGMMMMMMMM               MMMMMMMM               AAA               NNNNNNNN        NNNNNNNN\n");
    printf("H:::::::H     H:::::::H              A:::A              N:::::::N       N::::::N     GGG::::::::::::GM:::::::M             M:::::::M              A:::A              N:::::::N       N::::::N\n");    
    printf("H:::::::H     H:::::::H             A:::::A             N::::::::N      N::::::N   GG:::::::::::::::GM::::::::M           M::::::::M             A:::::A             N::::::::N      N::::::N\n");     
    printf("HH::::::H     H::::::HH            A:::::::A            N:::::::::N     N::::::N  G:::::GGGGGGGG::::GM:::::::::M         M:::::::::M            A:::::::A            N:::::::::N     N::::::N\n");    
    printf("  H:::::H     H:::::H             A:::::::::A           N::::::::::N    N::::::N G:::::G       GGGGGGM::::::::::M       M::::::::::M           A:::::::::A           N::::::::::N    N::::::N\n");    
    printf("  H:::::H     H:::::H            A:::::A:::::A          N:::::::::::N   N::::::NG:::::G              M:::::::::::M     M:::::::::::M          A:::::A:::::A          N:::::::::::N   N::::::N\n");   
    printf("  H::::::HHHHH::::::H           A:::::A A:::::A         N:::::::N::::N  N::::::NG:::::G              M:::::::M::::M   M::::M:::::::M         A:::::A A:::::A         N:::::::N::::N  N::::::N\n");     
    printf("  H:::::::::::::::::H          A:::::A   A:::::A        N::::::N N::::N N::::::NG:::::G    GGGGGGGGGGM::::::M M::::M M::::M M::::::M        A:::::A   A:::::A        N::::::N N::::N N::::::N\n");     
    printf("  H:::::::::::::::::H         A:::::A     A:::::A       N::::::N  N::::N:::::::NG:::::G    G::::::::GM::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A       N::::::N  N::::N:::::::N\n");     
    printf("  H::::::HHHHH::::::H        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::NG:::::G    GGGGG::::GM::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N\n");     
    printf("  H:::::H     H:::::H       A:::::::::::::::::::::A     N::::::N    N::::::::::NG:::::G        G::::GM::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A     N::::::N    N::::::::::N\n");     
    printf("  H:::::H     H:::::H      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N G:::::G       G::::GM::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N\n");     
    printf("HH::::::H     H::::::HH   A:::::A             A:::::A   N::::::N      N::::::::N  G:::::GGGGGGGG::::GM::::::M               M::::::M   A:::::A             A:::::A   N::::::N      N::::::::N\n");     
    printf("H:::::::H     H:::::::H  A:::::A               A:::::A  N::::::N       N:::::::N   GG:::::::::::::::GM::::::M               M::::::M  A:::::A               A:::::A  N::::::N       N:::::::N\n");     
    printf("H:::::::H     H:::::::H A:::::A                 A:::::A N::::::N        N::::::N     GGG::::::GGG:::GM::::::M               M::::::M A:::::A                 A:::::A N::::::N        N::::::N\n");     
    printf("HHHHHHHHH     HHHHHHHHHAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN        GGGGGG   GGGGMMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN\n\n");
}


/*Permainan utama*/
void playtebakkataHM(float* scoretotal, float* nyawa){
    int skor = 0; //Skor game
    time_t t;
    srand(time(&t)); //Seed for random number
    Set kamus;
    CreateEmptySet(&kamus);
    loadkamus("kamus.txt", &kamus);
    //generatemap(&kamus); //Meng-generate kamus kata ke kamus lokal
    boolean win = false;
    int angka = rand() % kamus.Count; //Randomize kata yang dipilih
    
    //ADT Set
    SetChar SKunjaw, SAnswer;
    CreateEmptySetChar(&SAnswer);
    CreateEmptySetChar(&SKunjaw);

    //Displaying soal awal
    //printf("Selamat Datang di Hangman!\nTebak kata berikut dengan benar! (DALAM HURUF BESAR)\nEdisi Nama-nama Negara di Asia\n");
    float poin = 0;
    char* soal = kamus.Elements[angka]; //Soal hasil randomizer

    //Buat set kunjaw
    for(int i=0; i < countkataHM(soal); i++){
        InsertSetChar(&SKunjaw, soal[i]);
        poin++;
    }
    //float nyawa = 10;

    printf("---Mari mulai bermain!---\n\n");
    //Rilis soal
    while (!IsSubsetSetChar(SAnswer, SKunjaw) && (*nyawa) > 0){
        //Cetak soal setelah ditebak
        //printf("\nClue : %s\n", ValueChar(kamus, kamus.Elements));
        printf("Huruf yang udah kamu tebak : ");
        PrintSetChar(SAnswer);
        //printf("\n");

        for(int i=0; i < countkataHM(soal); i++){
            if (IsMemberSetChar(SAnswer, soal[i])){
                printf("%c ", soal[i]);
            }
            else{
                printf("_ ");
            }
        }
        printf("(%.0f huruf)\n", poin);
        printf("Sisa nyawa kamu : %.0f\n", (*nyawa));
        printf("Masukkan huruf jawaban : ");
        START();  //Diasumsikan input selalu character, bukan string
        currentChar = UpperHuruf(currentChar); //Memastikan semua input dalam Uppercase
        clear();
        //Saat jawaban salah jika kondisinya Huruf belum pernah ditebak tapi memang tidak ada di kunjaw
        //Tidak salaah jika kondisinya huruf pernah ditebak
        if (!IsMemberSetChar(SKunjaw, currentChar) && !IsMemberSetChar(SAnswer, currentChar))
        {
            (*nyawa)--;
            printf("-------------------\n");
            printf("Jawaban kamu salah!\n");
            printf("-------------------\n");
        }
        else if (IsMemberSetChar(SAnswer, currentChar)){
            printf("-----------------------\n");
            printf("Huruf %c sudah kamu tebak\n", currentChar);
            printf("-------------------------\n");
        }
        InsertSetChar(&SAnswer, currentChar);
        while (! IsEOP()) ADV();
}
    
    //Saat jawaban benar
    if (IsSubsetSetChar(SAnswer, SKunjaw)){
        printf("Selamat jawaban kamu benar! Kamu berhasil menebak kata %s !\n", soal);
        printf("Kamu mendapatkan %.0f poin!\n\n", poin);
        (*scoretotal) = poin;
    }

    //Saat kesempatan habis
    else{
        printf("\nMohon maaf, nyawamu habis.\nJawaban yang benar: %s\n", soal);
        hangmanart();
    }
}

void savekamus(Set kamus){
    char* filepath = AddPath("kamus.txt");
    FILE* fp = fopen(filepath, "w");
    fprintf(fp, "%d\n", kamus.Count);
    for (int i = 0; i < kamus.Count; i++){
        if (i != kamus.Count - 1){
            fprintf(fp, "%s\n", kamus.Elements[i]);
        }
        else{
            fprintf(fp, "%s", kamus.Elements[i]);
        }
    }
    fclose(fp);
}

//Fungsi utama yang dipanggil
void Hangman(float *skor, boolean *play){
    float skortemp, skortotal = 0, nyawa = 10;
    *play = true;
    int pilihan;
    boolean valid = false;
    hangmanascii();
    printf("Selamat Datang di Hangman!\nTebak kata berikut dengan benar! (DALAM HURUF BESAR)\nEdisi Nama-nama Negara di Asia\n");
    printf("Ketik 1 untuk main\nKetik 2 untuk menambahkan kata ke daftar kata\n");
    while(! valid){
        printf("Masukkan command: ");
        STARTWORD();
        pilihan = WordToInt(currentWord);
        if(pilihan == 1){
            valid = true;
            playtebakkataHM(&skortemp, &nyawa);
            skortotal += skortemp;
            //Asking for mengulangi permainan
            //char valid;
            //boolean main_lagi = true;
            // printf("\nApakah kamu ingin bermain lagi? (y/n) : ");
            //printf("%c\n", valid);
            while (nyawa > 0){
                //printf("%c\n", valid);
                //printf("\nApakah kamu ingin bermain lagi? (y/n) : ");
                // START();
                // valid = currentChar;
                // //printf("%c", valid);
                // while (! IsEOP()) ADV();
                //clear();
                // if (valid == 'y' || valid == 'Y') //Jika ingin main lagi
                // {
                playtebakkataHM(&skortemp, &nyawa);
                skortotal += skortemp;
                //}
                // else if (valid == 'n' || valid == 'N'){ //Jika tidak ingin main lagi, game berakhir
                (*skor) = skortotal;
                // printf("Selamat mengerjakan tubes lainnya, Bye-bye! :D\n");
                //main_lagi = false;
                // }
                // else {
                // printf("Coba pilih antara y atau n, bukan antara kamu atau dia ya :(\n");
                // }
            }
            printf("Yah nyawa kamu habis, tapi ... Selamat kamu berhasil mendapatkan %.0f poin pada game ini!\n", skortotal);
            printf("Selamat mengerjakan tubes lainnya, Bye-bye! :D\n");
        //ALGORITMA MASUKIN SCOREBOARD
        }
        else if (pilihan == 2){
            valid = true;
            *play = false;
            Set kamus;
            printf("Masukkan kata yang ingin ditambahkan ke daftar kata : ");
            STARTWORD();
            char* kata = WordToString(currentWord);
            while (! IsEOP()) ADV();
            clear();
            CreateEmptySet(&kamus);
            loadkamus("kamus.txt", &kamus);
            kata = UpperKata(kata);
            InsertSet(&kamus, kata);
            savekamus(kamus);
            printf("Kata %s berhasil ditambahkan ke daftar kata!\n", kata);
        }
        else{
            printf("Pilihan tidak valid, coba lagi ya!\n");
        }
    }
}

// //Driver test
// int main(){
//     float skor;
//     Hangman(&skor);
//     srand(0);
//     return 0;
// }
