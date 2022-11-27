#include "help.h"
#include <stdio.h>

void help() {
/*  Bantuan yang berisikan command-command lain, serta kegunaannya. */
    printf("                                        'Kamu Nanya Menunya Apa Aja?' \n");
    printf("+---+------------------+-------------------------------------------------------------------------------------------------+\n");
    printf("| 1 | START            | Untuk menjalankan BNMO                                                                          |\n");
    printf("| 2 | LOAD             | Untuk membaca save file yang berisi list game yang dapat dimainkan, histori dan scoreboard game |\n");
    printf("| 3 | SAVE             | Untuk menyimpan state game pemain saat ini                                                      |\n");
    printf("| 4 | CREATE GAME      | Untuk menambahkan game baru pada daftar game                                                    |\n");
    printf("| 5 | LIST GAME        | Untuk menampilkan daftar game yang disediakan oleh sistem                                       |\n");
    printf("| 6 | DELETE GAME      | Untuk menghapus sebuah game dari daftar game                                                    |\n");
    printf("| 7 | QUEUE GAME       | Untuk mendaftarkan permainan kedalam list                                                       |\n");
    printf("| 8 | PLAY GAME        | Untuk memainkan sebuah permainan                                                                |\n");
    printf("| 9 | SKIP GAME <n>    | Untuk melewatkan permainan sebanyak yang kamu mau                                               |\n");
    printf("| 10| SCOREBOARD       | Untuk melihat nama dan skor musuh kamu di game tersebut                                         |\n");
    printf("| 11| RESET SCOREBOARD | Untuk mereset scoreboard permainan kamu                                                         |\n");
    printf("| 12| HISTORY <n>      | Untuk melihat kenangan permainan yang telah kamu mainkan, sebanyak yang kamu mau                |\n");
    printf("| 13| RESET HISTORY    | Untuk menghapus semua kenangan permainan yang kamu mainkan                                      |\n");
    printf("| 11| QUIT             | Untuk keluar dari program                                                                       |\n");
    printf("| 12| HELP             | Untuk bantuin kamu                                                                              |\n");
    printf("+---+------------------+-------------------------------------------------------------------------------------------------+\n");
}   
