#include "start.h"
#include "load.h"

void start(ArrayDin *Games) {
    //load config.txt 
    loadfile("config.txt", Games);
}