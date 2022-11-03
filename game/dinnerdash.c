#include "dinnerdash.h"

void generatemenu(Queue* q){
    ElType food;
    food.durasi = (rand() % 5) + 1; 
    food.ketahanan = (rand() % 5) + 1; 
    food.harga = ((10000) + rand() % 50000);
    if(isEmpty(*q)){
        food.id = 0;
    }
    else {
        food.id = IDX_TAIL(*q) + 1;
    }
    enqueue(q, food);
}

boolean isCook(char kata[10]){
    boolean output;
    if (kata[0] == 'C'){
        if(kata[1] == 'O'){
            if(kata[2] == 'O'){
                if(kata[3] == 'K'){
                    output = true;
                }
            }
        }
    }
    else {
        output = false;
    }
    return output;
}

int getID(char kata[10]){
    char output;
    if(kata[0] == 'S'){
        output = kata[7];
    }
    else {
        output = kata[6];
    }

    return (output - '0');
}

void serve(Queue *q1, Queue *q2, int i){ //q1 = menu; q2 = cook; i = id
    boolean done = false, found = false;
    ElType food;
    int x = 0;
    while (x < length(*q2) && !found){
        if((*q2).buffer[x].id == i){
            found = true;
            if((*q2).buffer[x].durasi <= 0){
                done = true;
            }
        }
        else{
            x++;
        }
    }
    if(!found){
        printf("Masakan belum dimasak\n");
    }
    else {
        if(done){
            if(i == IDX_HEAD(*q1)){
                printf("Berhasil mengantar M%d\n", i);
                dequeue(q1, &food);
                printf("true");
                boolean found = false;
                int x = IDX_HEAD(*q2);
                while (x < length(*q2) && !found){
                    if((*q2).buffer[x].id == i){
                        found = true;
                        (*q2).buffer[x].ketahanan = 0;
                    }    
                    else{
                        x++;
                    }
                }
            }
            else {
                printf("M%d belum dapat disajikan karena M%d belum selesai\n", i, IDX_HEAD(*q1));
            }
        }
        else {
            printf("M%d belum selesai dimasak\n", i);
        }
    }
}

void playdinnerdash(){
    printf("Selamat Datang di Diner Dash!\n");
    printf("\n");
    srand(time(0));
    //generate menu
    Queue menu;
    CreateQueue(&menu);
    for (int i = 0; i< 3; i++){
        generatemenu(&menu);
    }
    daftarmenu(menu);
    printf("\n");
    Queue cook;
    CreateQueue(&cook);
    daftarcook(cook);
    printf("\n");
    daftarserve(cook);
    printf("MASUKKAN COMMAND: ");
    char input[10];
    scanf("%[^\n]%*c", input);

    
    for(int i = 0; i < 10; i++){
        //ngelayananin input cook/serve
        int foodid = getID(input);
        if(isCook(input)){
            int i=0;
            boolean found=false;
            if(isEmpty(cook)){
                enqueue(&cook, menu.buffer[foodid]);
            }
            else {
                while(i <= IDX_TAIL(cook) && (!found)){
                    if(cook.buffer[i].id == foodid){
                        found = true;
                    }
                    else {
                        i++;
                    }
                }
                if(!found){
                    enqueue(&cook, menu.buffer[foodid]);
                }
            }
        }
        else{
            if(! isEmpty(cook)){
                serve(&menu, &cook, foodid);
            }
            else {
                printf("Anda belum memasak makanan\n");
            }
        }

        //Buat ngurangin durasi/ketahanan
        if(!isEmpty(cook)){
            for(int j = 0; j < length(cook); j++){
                if(cook.buffer[j].durasi >= 0){
                    cook.buffer[j].durasi--;
                }
                else {
                    if(cook.buffer[j].ketahanan > 0){
                        cook.buffer[j].ketahanan--;
                    }
                }
            }
        }
        generatemenu(&menu);
        daftarmenu(menu);
        daftarcook(cook);
        daftarserve(cook);
        printf("MASUKKAN COMMAND: ");
        scanf("%[^\n]%*c", input);
    }
}




int main(){
    srand(time(0));
    playdinnerdash();
    return 0;
}