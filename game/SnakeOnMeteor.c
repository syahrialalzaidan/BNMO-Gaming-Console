#include <stdio.h>
#include "SnakeOnMeteor.h"

// gcc SnakeOnMeteor.c ../program/ADT/listdp/listdp.c ../program/ADT/mesinkarkata/mesinkar.c ../program/ADT/mesinkarkata/mesinkata.c -o ular
boolean isValid(Word kata, int *command)
{
    boolean output;
    if (isWordSame(kata, stringToWord("w"))) {
        output = true;
        *command = 0; // 0 = up
    }
    else if (isWordSame(kata, stringToWord("a"))) {
        output = true;
        *command = 1; // 1 = left
        ADVWORD();
    }
    else if (isWordSame(kata, stringToWord("s"))) {
        output = true;
        *command = 2; // 2 = down
        ADVWORD();
    }
    else if (isWordSame(kata, stringToWord("d")))
    {
        output = true;
        *command = 3; // 3 = right
        ADVWORD();
    }
    if(! IsEOP()){
        output = false;
        *command = 11;
    }
    while(! IsEOP()) ADVWORD();
    return output;
}

void addBody(List *L) {
    address tail = Last(*L);
    address P;
    int x = InfoX(tail) - 1;
    int y = InfoY(tail);
    boolean isSpawn = true;
    address P1 = First(*L);
    if (x < 0) {
        isSpawn = false;
    }
    while (P1 != NilListDP && isSpawn) {
        if (InfoX(P1) == x && InfoY(P1) == y) {
            isSpawn = false;
        }
        P1 = Next(P1);
    }
    if (!isSpawn) {
        x = InfoX(tail);
        y = InfoY(tail) - 1;
        isSpawn = true;
        if (y < 0) {
            isSpawn = false;
        }
        P1 = First(*L);
        while (P1 != NilListDP && isSpawn) {
            if (InfoX(P1) == x && InfoY(P1) == y) {
                isSpawn = false;
            }
            P1 = Next(P1);
        }
        if (!isSpawn) {
            x = InfoX(tail);
            y = InfoY(tail) + 1;
            isSpawn = true;
            if (y < 0) {
                isSpawn = false;
            }
            P1 = First(*L);
            while (P1 != NilListDP && isSpawn) {
                if (InfoX(P1) == x && InfoY(P1) == y) {
                    isSpawn = false;
                }
                P1 = Next(P1);
            }
            if (!isSpawn) {
                x = InfoX(tail) + 1;
                y = InfoY(tail);
            }
        }
    }
    P = Alokasi(x, y);
    InsertLast(L, P);
}

void makeSnake(List *L) {
    int HeadX, HeadY, Badan1X, Badan1Y, Badan2X, Badan2Y;
    HeadX = rand() % 5;
    HeadY = rand() % 5;
    // Badan1X = rand() % 5;
    // Badan1Y = rand() % 5;
    // if ((Badan1X != HeadX || Badan1Y != HeadY - 1) && (Badan1X != HeadX - 1 || Badan1Y != HeadY)) {
    //     while ((Badan1X != HeadX || Badan1Y != HeadY - 1) && (Badan1X != HeadX - 1 || Badan1Y != HeadY)) {
    //         HeadX = rand() % 5;
    //         HeadY = rand() % 5;
    //         Badan1X = rand() % 5;
    //         Badan1Y = rand() % 5;
    //     }
    // }

    // Badan2X = rand() % 5;
    // Badan2Y = rand() % 5;
    // if ((Badan2X != Badan1X || Badan2Y != Badan1Y - 1) && (Badan2X != Badan1X - 1 || Badan2Y != Badan1Y)) {
    //     while ((Badan2X != Badan1X || Badan2Y != Badan1Y - 1) && (Badan2X != Badan1X - 1 || Badan2Y != Badan1Y)) {
    //         Badan2X = rand() % 5;
    //         Badan2Y = rand() % 5;
    //     }
    // }

    address P = Alokasi(HeadX, HeadY);
    InsertLast(L, P);
    addBody(L);
    addBody(L);
    // P = Alokasi(Badan1X, Badan1Y);
    // InsertLast(L, P);
    // P = Alokasi(Badan2X, Badan2Y);
    // InsertLast(L, P);
}

void CutBody(List *L, int MetX, int MetY) {
    address P = First(*L);
    while (P != NilListDP) {
        if (InfoX(P) == MetX && InfoY(P) == MetY) {
            DelAfter(L, &P, Prev(P));
            Dealokasi(P);
        }
        P = Next(P);
    }
}

void SpawnFood(List snake, int *FoodX, int *FoodY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y) {
    *FoodX = rand() % 5;
    *FoodY = rand() % 5;
    address P = First(snake);
    while (P != NilListDP) {
        if ((InfoX(P) == *FoodX && InfoY(P) == *FoodY) || (*FoodX == Obs1X && *FoodY == Obs1Y) || (*FoodX == Obs2X && *FoodY == Obs2Y)) {
            *FoodX = rand() % 5;
            *FoodY = rand() % 5;
            P = First(snake);
        } else {
            P = Next(P);
        }
    }
}

void SpawnMeteor(List snake, int *MetX, int *MetY, int FoodX, int FoodY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y) {
    *MetX = rand() % 5;
    *MetY = rand() % 5;
    //if meteor is spawned in food then randomize it again
    while ((*MetX == FoodX && *MetY == FoodY) || (*MetX == Obs1X && *MetY == Obs1Y) || (*MetX == Obs2X && *MetY == Obs2Y)) {
        *MetX = rand() % 5;
        *MetY = rand() % 5;
    }
}

void SpawnObstacles(List Snake, int *Obs1X, int *Obs1Y, int *Obs2X, int *Obs2Y, int FoodX, int FoodY) {
    *Obs1X = rand() % 5;
    *Obs1Y = rand() % 5;
    address P = First(Snake);
    while (P != NilListDP) {
        if ((InfoX(P) == *Obs1X && InfoY(P) == *Obs1Y) || (*Obs1X == FoodX && *Obs1Y == FoodY)) {
            *Obs1X = rand() % 5;
            *Obs1Y = rand() % 5;
            P = First(Snake);
        } else {
            P = Next(P);
        }
    }
    *Obs2X = rand() % 5;
    *Obs2Y = rand() % 5;
    P = First(Snake);
    while (P != NilListDP) {
        if ((InfoX(P) == *Obs2X && InfoY(P) == *Obs2Y) || (*Obs2X == FoodX && *Obs2Y == FoodY) || (*Obs2X == *Obs1X && *Obs2Y == *Obs1Y)) {
            *Obs2X = rand() % 5;
            *Obs2Y = rand() % 5;
            P = First(Snake);
        } else {
            P = Next(P);
        }
    }
}

boolean isHit(List snake, int MetX, int MetY) {
    address P = First(snake);
    while (P != NilListDP) {
        if (InfoX(P) == MetX && InfoY(P) == MetY) {
            return true;
        }
        P = Next(P);
    }
    return false;
}

void MoveSnake(int command, List *snake, int *FoodX, int *FoodY, int MetX, int MetY, boolean *isHitBody, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y, boolean *isHitObs) {
    address first = First(*snake);
    address last = Last(*snake);

    address P = last;
    while (P != first) {
        InfoX(P) = InfoX(Prev(P));
        InfoY(P) = InfoY(Prev(P));
        P = Prev(P);
    }

    if (command == 0) {
        InfoY(first) -= 1;
    } else if (command == 1) {
        InfoX(first) -= 1;
    } else if (command == 2) {
        InfoY(first) += 1;
    } else if (command == 3) {
        InfoX(first) += 1;
    }

    if (InfoX(first) < 0) {
        InfoX(first) = 4;
    } else if (InfoX(first) > 4) {
        InfoX(first) = 0;
    } else if (InfoY(first) < 0) {
        InfoY(first) = 4;
    } else if (InfoY(first) > 4) {
        InfoY(first) = 0;
    }

    if (InfoX(first) == *FoodX && InfoY(first) == *FoodY) {
        SpawnFood(*snake, FoodX, FoodY, Obs1X, Obs1Y, Obs2X, Obs2Y);
        addBody(snake);
    }

    P = Next(first);
    P = Next(P);
    if ((InfoX(first) == Obs1X && InfoY(first) == Obs1Y) || (InfoX(first) == Obs2X && InfoY(first) == Obs2Y)) {
        *isHitObs = true;
    } 
}

boolean isMoveToBody(int command, List L) {
    address first = First(L);
    address P = Next(first);
    boolean found = false;
    int newX, newY;
    if (command == 0) {
        newY = InfoY(first) - 1;
        newX = InfoX(first);
    } else if (command == 1) {
        newX = InfoX(first) - 1;
        newY = InfoY(first);
    } else if (command == 2) {
        newY = InfoY(first) + 1;
        newX = InfoX(first);
    } else if (command == 3) {
        newX = InfoX(first) + 1;
        newY = InfoY(first);
    }

    if (newX < 0) {
        newX = 4;
    } else if (newX > 4) {
        newX = 0;
    } else if (newY < 0) {
        newY = 4;
    } else if (newY > 4) {
        newY = 0;
    }

    while (P != NilListDP && !found) {
        if (InfoX(P) == newX && InfoY(P) == newY) {
            found = true;
        } 
        P = Next(P);
    }
    return found;
}

boolean isMoveToMeteor(int command, List L, int MetX, int MetY) {
    address first = First(L);
    if (command == 0) {
        // return true if meteor is above the head of snake
        return (InfoX(first) == MetX && InfoY(first) - 1 == MetY) || (InfoY(first) == 0 && MetY == 4 && InfoX(first) == MetX);
    } else if (command == 1) {
        // return true if meteor is left of the head of snake
        return (InfoX(first) - 1 == MetX && InfoY(first) == MetY) || (InfoX(first) == 0 && MetX == 4 && InfoY(first) == MetY);
    } else if (command == 2) {
        // return true if meteor is below the head of snake
        return (InfoX(first) == MetX && InfoY(first) + 1 == MetY) || (InfoY(first) == 4 && MetY == 0 && InfoX(first) == MetX);
    } else if (command == 3) {
        // return true if meteor is right of the head of snake
        return (InfoX(first) + 1 == MetX && InfoY(first) == MetY) || (InfoX(first) == 4 && MetX == 0 && InfoY(first) == MetY);
    }
    return false;
}

boolean isSurrounded(List L) {
    return (isMoveToBody(0, L) && isMoveToBody(1, L) && isMoveToBody(2, L) && isMoveToBody(3, L));
}

void PrintMapSnake (List L, int FoodX, int FoodY, int MetX, int MetY, int Obs1X, int Obs1Y, int Obs2X, int Obs2Y) {
    int MapSnake[5][5] = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
    MapSnake[InfoY(First(L))][InfoX(First(L))] = 1;
    address P = Next(First(L));
    int count  = 1;
    while (P != NilListDP) {
        MapSnake[InfoY(P)][InfoX(P)] = count;
        P = Next(P);
        count++;
    }
    MapSnake[FoodY][FoodX] = 25;
    if (MetX != -1 && MetY != -1) {
        MapSnake[MetY][MetX] = 26;
    }
    MapSnake[Obs1Y][Obs1X] = 27;
    MapSnake[Obs2Y][Obs2X] = 27;
    printf("Berikut merupakan peta permainan\n\n");
    printf("      +---+---+---+---+---+ \n");
    for (int i = 0; i < 5; ++i){
        printf("      |");
        for (int j = 0; j < 5; ++j) {
            if (MapSnake[i][j] == 0) {
                if (j != 4) {
                    printf("   |");
                } else {
                    printf("   ");
                }
                
            } else if (MapSnake[i][j] == 26) {
                if (j != 4) {
                    printf(" M |"); 
                } else {
                    printf(" M ");  
                }
            } else if (i == InfoY(First(L)) && j == InfoX(First(L))) {
                if (j != 4) {
                    printf(" H |"); 
                } else {
                    printf(" H ");
                }
            } else if (MapSnake[i][j] == 25) {
                if (j != 4) {
                    printf(" O |"); 
                } else {
                    printf(" O ");
                }
            } else if (MapSnake[i][j] == 27) {
                if (j != 4) {
                    printf(" X |"); 
                } else {
                    printf(" X ");
                }
                
            } else {
                if (j != 4) {
                    if (MapSnake[i][j] < 10) {
                        printf(" %d |", MapSnake[i][j]);
                    } else {
                        printf("%d |", MapSnake[i][j]);
                    }
                } else {
                    if (MapSnake[i][j] < 10) {
                        printf(" %d ", MapSnake[i][j]);
                    } else {
                        printf("%d ", MapSnake[i][j]);
                    }
                }
            }
            if (j == 4) {
                if (i != 4) {
                    printf("|\n      +---+---+---+---+---+\n");   
                } else {
                    printf("|\n");
                }
            }
        }
    }
    printf("      +---+---+---+---+---+ \n\n");
    printf("      Legends:\n");
    printf("      H, 1, 2, and other digits : Snake\n");     
    printf("      O : Food\n");
    printf("      M : Meteor\n");
    printf("      X : Obstacle\n\n");
}

boolean isGameOver(List snake, int MetX, int MetY, boolean isHitBody, boolean isHitObs) {
    return ((InfoX(First(snake)) == MetX && InfoY(First(snake)) == MetY) || isHitBody || isHitObs || isSurrounded(snake));
}

void print_logo_snake() {                                               
    printf("\n");
    printf("                      ::::::::  ::::    :::     :::     :::    ::: :::::::::: \n");
    printf("                    :+:    :+: :+:+:   :+:   :+: :+:   :+:   :+:  :+:         \n");
    printf("                   +:+        :+:+:+  +:+  +:+   +:+  +:+  +:+   +:+          \n");
    printf("                  +#++:++#++ +#+ +:+ +#+ +#++:++#++: +#++:++    +#++:++#      \n");
    printf("                        +#+ +#+  +#+#+# +#+     +#+ +#+  +#+   +#+            \n");
    printf("                #+#    #+# #+#   #+#+# #+#     #+# #+#   #+#  #+#             \n");
    printf("                ########  ###    #### ###     ### ###    ### ##########       \n");
    printf("                                  ::::::::  ::::    :::                       \n");
    printf("                                :+:    :+: :+:+:   :+:                        \n");
    printf("                               +:+    +:+ :+:+:+  +:+                         \n");
    printf("                              +#+    +:+ +#+ +:+ +#+                          \n");
    printf("                             +#+    +#+ +#+  +#+#+#                           \n");
    printf("                            #+#    #+# #+#   #+#+#                            \n");
    printf("                            ########  ###    ####                             \n");
    printf("        :::   :::   :::::::::: ::::::::::: :::::::::: ::::::::  :::::::::     \n");
    printf("      :+:+: :+:+:  :+:            :+:     :+:       :+:    :+: :+:    :+:     \n");
    printf("    +:+ +:+:+ +:+ +:+            +:+     +:+       +:+    +:+ +:+    +:+      \n");
    printf("   +#+  +:+  +#+ +#++:++#       +#+     +#++:++#  +#+    +:+ +#++:++#:        \n");
    printf("  +#+       +#+ +#+            +#+     +#+       +#+    +#+ +#+    +#+        \n");
    printf(" #+#       #+# #+#            #+#     #+#       #+#    #+# #+#    #+#         \n");
    printf("###       ### ##########     ###     ########## ########  ###    ###          \n\n");

}
void PlaySnakeOnMeteor(float *skor) {
    List snake;
    int FoodX, FoodY, MetX = -1, MetY = -1, turn = 1, command, Obs1X = -1, Obs1Y = -1, Obs2X = -1, Obs2Y = -1;
    boolean isHitBody = false;
    boolean isHitObs = false;
    boolean isBodyCut = false;
    boolean isMovingBackwards = false;
    CreateEmptyList(&snake);
    srand(time(NULL));
    print_logo_snake();
    printf("Selamat datang di Snake on Meteor!\n");
    printf("Mengenerate peta, snake, dan makanan...\n");
    makeSnake(&snake);
    SpawnFood(snake, &FoodX, &FoodY, Obs1X, Obs1Y, Obs2X, Obs2Y);
    SpawnObstacles(snake, &Obs1X, &Obs1Y, &Obs2X, &Obs2Y, FoodX, FoodY);
    printf("Berhasil digenerate!\n");
    printf("================================\n");
    while (!isGameOver(snake, MetX, MetY, isHitBody, isHitObs)) {
        if (turn > 1) {
            SpawnMeteor(snake, &MetX, &MetY, FoodX, FoodY, Obs1X, Obs1Y, Obs2X, Obs2Y);
        }
        if (isHit(snake, MetX, MetY)) {
            PrintMapSnake(snake, FoodX, FoodY, MetX, MetY, Obs1X, Obs1Y, Obs2X, Obs2Y);
            if (MetX == InfoX(First(snake)) && MetY == InfoY(First(snake))) {
                printf("Kepala snake terkena meteor!\n");
            } else {
                printf("\nAnda terkena meteor!\n");
                isBodyCut = true;
                CutBody(&snake, MetX, MetY);
            }
        }
        if (!isHitBody && !isHit(snake, MetX, MetY)) {
            PrintMapSnake(snake, FoodX, FoodY, MetX, MetY, Obs1X, Obs1Y, Obs2X, Obs2Y);
            if (turn > 1) {
                if (!isBodyCut) {
                    printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
                } else {
                    isBodyCut = false;
                }
            }
            printf("TURN %d\n", turn);
            printf("Silakan masukkan command Anda: ");
            STARTWORD();
            while (!isValid(currentWord, &command)) {
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                printf("Silakan masukkan command Anda: ");
                STARTWORD();
            }
            while(isMoveToMeteor(command, snake, MetX, MetY) || isMoveToBody(command, snake)) {
                if (isMoveToMeteor(command, snake, MetX, MetY)) {
                    printf("Anda tidak bisa bergerak ke meteor!\n");
                } else if (isMoveToBody(command, snake)) {
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                }
                printf("Silakan input command yang lain\n");
                printf("Silakan masukkan command Anda: ");
                STARTWORD();
                while (!isValid(currentWord, &command)) {
                    printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                    printf("Silakan masukkan command Anda: ");
                    STARTWORD();
                }
            }
            MoveSnake(command, &snake, &FoodX, &FoodY, MetX, MetY, &isHitBody, Obs1X, Obs1Y, Obs2X, Obs2Y, &isHitObs);
            while(isMovingBackwards) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain");
                printf("Silakan masukkan command Anda: ");
                STARTWORD();
            }
            turn++;
        }
        if (isSurrounded(snake)) {
            PrintMapSnake(snake, FoodX, FoodY, MetX, MetY, Obs1X, Obs1Y, Obs2X, Obs2Y);
            printf("Kepala snake sudah tidak bisa bergerak ke mana-mana\n");
        } else if (isHitObs) {
            printf("Kepala snake menabrak obstacles!\n");
        }
    }
    if (InfoX(First(snake)) == MetX && InfoY(First(snake)) == MetY) {
        infotypeList HeadX, HeadY;
        DelVFirst(&snake, &HeadX, &HeadY);
    }
    *skor = LengthList(snake)*2;
    printf("\n): G A M E    O V E R :( \n\nSkor: %.0f\n\n", *skor);
}