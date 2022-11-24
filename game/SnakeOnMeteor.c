#include <stdio.h>
#include "SnakeOnMeteor.h"

boolean isInputValid(Word kata, int *command)
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
    // if there is no body in x - 1 of tail then the body will be spawned
    // in x - 1 of tail
    int x = InfoX(tail) - 1;
    int y = InfoY(tail);
    boolean isSpawn = true;
    address P1 = First(*L);
    if (x < 0) {
        isSpawn = false;
    }
    while (P1 != Nil && isSpawn) {
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
        while (P1 != Nil && isSpawn) {
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
            while (P1 != Nil && isSpawn) {
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
    while (P != Nil) {
        if (InfoX(P) == MetX && InfoY(P) == MetY) {
            DelAfter(L, &P, Prev(P));
            Dealokasi(P);
        }
        P = Next(P);
    }
}

void SpawnFood(List snake, int *FoodX, int *FoodY) {
    *FoodX = rand() % 5;
    *FoodY = rand() % 5;
    address P = First(snake);
    while (P != Nil) {
        if (InfoX(P) == *FoodX && InfoY(P) == *FoodY) {
            *FoodX = rand() % 5;
            *FoodY = rand() % 5;
            P = First(snake);
        } else {
            P = Next(P);
        }
    }
}

void SpawnMeteor(List snake, int *MetX, int *MetY, int FoodX, int FoodY) {
    *MetX = rand() % 5;
    *MetY = rand() % 5;
    //if meteor is spawned in food then randomize it again
    while (*MetX == FoodX && *MetY == FoodY) {
        *MetX = rand() % 5;
        *MetY = rand() % 5;
    }
}


boolean isHit(List snake, int MetX, int MetY) {
    address P = First(snake);
    while (P != Nil) {
        if (InfoX(P) == MetX && InfoY(P) == MetY) {
            return true;
        }
        P = Next(P);
    }
    return false;
}

void MoveSnake(int command, List *snake, int *FoodX, int *FoodY, int MetX, int MetY, boolean *isHitBody) {
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
        SpawnFood(*snake, FoodX, FoodY);
        addBody(snake);
    }

    P = Next(first);
    P = Next(P);
    
    while (P != Nil) {
        if (InfoX(P) == InfoX(first) && InfoY(P) == InfoY(first)) {
            *isHitBody = true;
        }
        P = Next(P);
    }
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

boolean isMoveBackwards(int command, List L) {
    address first = First(L);
    address second = Next(first);
    if (command == 0) {
        // return true if meteor is above the head of snake
        return InfoX(second) == InfoX(first) && InfoY(second) + 1 == InfoY(first);
    } else if (command == 1) {
        // return true if meteor is left of the head of snake
        return InfoX(second) + 1 == InfoX(first) && InfoY(second) == InfoY(first);
    } else if (command == 2) {
        // return true if meteor is below the head of snake
        return InfoX(second) == InfoX(first) && InfoY(second) - 1 == InfoY(first);
    } else if (command == 3) {
        // return true if meteor is right of the head of snake
        return InfoX(second) - 1 == InfoX(first) && InfoY(second) == InfoY(first);
    }
    return false;
}

void PrintMapSnake (List L, int FoodX, int FoodY, int MetX, int MetY) {
    int MapSnake[5][5] = {{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
    MapSnake[InfoY(First(L))][InfoX(First(L))] = 1;
    address P = Next(First(L));
    int count  = 1;
    while (P != Nil) {
        MapSnake[InfoY(P)][InfoX(P)] = count;
        P = Next(P);
        count++;
    }
    MapSnake[FoodY][FoodX] = 25;
    if (MetX != -1 && MetY != -1) {
        MapSnake[MetY][MetX] = 26;
    }
    printf("Berikut merupakan peta permainan\n");
    printf("+-----------+ \n");
    for (int i = 0; i < 5; ++i){
        printf("| ");
        for (int j = 0; j < 5; ++j) {
            if (MapSnake[i][j] == 0) {
                printf("_ ");
            } else if (MapSnake[i][j] == 26) {
                printf("M "); 
            } else if (i == InfoY(First(L)) && j == InfoX(First(L))) {
                printf("H ");
            } else if (MapSnake[i][j] == 25) {
                printf("O ");
            } else {
                printf("%d ", MapSnake[i][j]);
            }
            if (j == 4) {
                printf("|\n");
            }
        }
    }
    printf("+-----------+ \n");
}

boolean isGameOver(List snake, int MetX, int MetY, boolean isHitBody) {
    return ((InfoX(First(snake)) == MetX && InfoY(First(snake)) == MetY) || isHitBody);
}

void PlaySnakeOnMeteor(int *skor) {
    List snake;
    int FoodX, FoodY, MetX = -1, MetY = -1, turn = 1, command;
    boolean isHitBody = false;
    boolean isMovingBackwards = false;
    CreateEmptyList(&snake);
    srand(time(NULL));
    printf("Selamat datang di Snake on Meteor!\n");
    printf("Mengenerate peta, snake, dan makanan...\n");
    makeSnake(&snake);
    SpawnFood(snake, &FoodX, &FoodY);
    printf("Berhasil digenerate!\n");
    printf("====================\n");
    while (!isGameOver(snake, MetX, MetY, isHitBody)) {
        if (turn > 1) {
            SpawnMeteor(snake, &MetX, &MetY, FoodX, FoodY);
        }
        if (isHit(snake, MetX, MetY)) {
            PrintMapSnake(snake, FoodX, FoodY, MetX, MetY);
            if (MetX == InfoX(First(snake)) && MetY == InfoY(First(snake))) {
                printf("Kepala snake terkena meteor!\n");
            } else {
                printf("\nAnda terkena meteor!\n");
                CutBody(&snake, MetX, MetY);
            }
        }
        if (!isHitBody && !isHit(snake, MetX, MetY)) {
            PrintMapSnake(snake, FoodX, FoodY, MetX, MetY);
            if (turn > 1) {
                printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
            }
            printf("TURN %d\n", turn);
            printf("Silakan masukkan command Anda: ");
            STARTWORD();
            while (!isInputValid(currentWord, &command)) {
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                printf("Silakan masukkan command Anda: ");
                STARTWORD();
            }
            while(isMoveToMeteor(command, snake, MetX, MetY) || isMoveBackwards(command, snake)) {
                if (isMoveToMeteor(command, snake, MetX, MetY)) {
                    printf("Anda tidak bisa bergerak ke meteor!\n");
                } else if (isMoveBackwards(command, snake)) {
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                }
                printf("Silakan input command yang lain\n");
                printf("Silakan masukkan command Anda: ");
                STARTWORD();
                while (!isInputValid(currentWord, &command)) {
                    printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
                    printf("Silakan masukkan command Anda: ");
                    STARTWORD();
                }
            }
            MoveSnake(command, &snake, &FoodX, &FoodY, MetX, MetY, &isHitBody);
            while(isMovingBackwards) {
                printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain");
                printf("Silakan masukkan command Anda: ");
                STARTWORD();
            }
            turn++;
        }
        if (isHitBody) {
            printf("Kepala snake menabrak badan snake!\n");
        }
    }
    if (InfoX(First(snake)) == MetX && InfoY(First(snake)) == MetY) {
        infotype HeadX, HeadY;
        DelVFirst(&snake, &HeadX, &HeadY);
    }
    *skor = LengthList(snake)*2;
    printf("Game berakhir. Skor: %d\n", *skor);
}