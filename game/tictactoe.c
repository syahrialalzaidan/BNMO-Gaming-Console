#include<stdio.h>
#include "../program/ADT/array/array.h"
#include "../program/ADT/boolean/boolean.h"
#include "mesinkata.h"
// 


boolean isgameover(TabInt baris1, TabInt baris2, TabInt baris3, int *winner){
    int i=1;
    boolean output = false;
    if (baris1.TI[i] == baris1.TI[i+1] && baris1.TI[i] == baris1.TI[i+2] && baris1.TI[i] != 0){
        output = true;
    }
    else if (baris2.TI[i] == baris2.TI[i+1] && baris2.TI[i] == baris2.TI[i+2] && baris2.TI[i] != 0){
        output = true;
    }
    else if (baris3.TI[i] == baris3.TI[i+1] && baris3.TI[i] == baris3.TI[i+2] && baris3.TI[i] != 0){
        output = true;
    }
    else if (baris1.TI[i] == baris2.TI[i] && baris1.TI[i] == baris3.TI[i] && baris1.TI[i] != 0){
        output = true;
    }
    else if (baris1.TI[i+1] == baris2.TI[i+1] && baris1.TI[i+1] == baris3.TI[i+1] && baris1.TI[i+1] != 0){
        output = true;
    }
    else if (baris1.TI[i+2] == baris2.TI[i+2] && baris1.TI[i+2] == baris3.TI[i+2] && baris1.TI[i+2] != 0){
        output = true;
    }
    else if (baris1.TI[i] == baris2.TI[i+1] && baris1.TI[i] == baris3.TI[i+2] && baris1.TI[i] != 0){
        output = true;
    }
    else if (baris1.TI[i+2] == baris2.TI[i+1] && baris1.TI[i+2] == baris3.TI[i] && baris1.TI[i+2] != 0){
        output = true;
    }
    if (output){
        *winner = baris1.TI[i];
    }
    return output;
}

void turn (TabInt* baris1, TabInt *baris2, TabInt* baris3, int player){
    boolean valid = false;
    int baris, kolom;
    while (!valid){
        printf("Masukkan baris yang ingin diisi: ");
        STARTWORD();
        baris = WordtoInteger(currentWord);
        printf("Masukkan kolom yang ingin diisi: ");
        STARTWORD();
        kolom = WordtoInteger(currentWord);
        if (baris == 1){
            if ((*baris1).TI[kolom] == 0){
                (*baris1).TI[kolom] = player;
                valid = true;
            }
            else printf("Kolom sudah terisi, silahkan masukkan kolom yang lain\n"); 
        }
        else if (baris == 2){
            if ((*baris2).TI[kolom] == 0){
                (*baris2).TI[kolom] = player;
                valid = true;
            }
            else printf("Kolom sudah terisi, silahkan masukkan kolom yang lain\n");
        }
        else if (baris == 3){
            if ((*baris3).TI[kolom] == 0){
                (*baris3).TI[kolom] = player;
                valid = true;
            }
            else printf("Kolom sudah terisi, silahkan masukkan kolom yang lain\n");
        }
        else printf("Baris tidak valid, silahkan masukkan baris yang valid\n");     
    }
}

void playtictactoe(){
    TabInt baris1, baris2, baris3;
    int winner;
    MakeEmpty(&baris1);
    MakeEmpty(&baris2);
    MakeEmpty(&baris3);
    for(int i = 1; i <= 3; i++){
        SetEl (&baris1,i,0);
        SetEl (&baris2,i,0);
        SetEl (&baris3,i,0);
    }
    while (! isgameover(baris1, baris2, baris3, &winner)){
        TulisTicTacToe(baris1, baris2, baris3);
        printf("Giliran pemain 1\n");
        turn(&baris1, &baris2, &baris3, 1);
        TulisTicTacToe(baris1, baris2, baris3);
        printf("Giliran pemain 2\n");
        turn(&baris1, &baris2, &baris3, 2);
        TulisTicTacToe(baris1, baris2, baris3);
    }
    printf("Pemenangnya adalah pemain %d\n", winner);
}

int main(){
    playtictactoe();
    return 0;
}