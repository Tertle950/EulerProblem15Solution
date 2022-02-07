#include <stdio.h>
#include <stdbool.h>
void printAcabus(bool *ARR, int ARRSIZE);

int main(){
    int SQUARESIZE = 0;
    printf("Width & length of the square? ");
    scanf("%i",&SQUARESIZE);
    int ARRSIZE = SQUARESIZE * 2;

    bool ARR[ARRSIZE];
    for(int i = 0; i < ARRSIZE; i++){
        ARR[i] = i<SQUARESIZE ? true : false;
    }
    printAcabus(ARR, ARRSIZE);

    return 0;
}

void printAcabus(bool *ARR, int ARRSIZE){
    for(int i = 0; i < ARRSIZE; i++){
        printf(ARR[i] ? "O" : "-");
    }
}

int latestAbacus(bool *ARR, int ARRSIZE){
    for(int i = ARRSIZE - 1; i >= 0; i--){
        if(ARR[i]){return i}
    }
}

bool moveAbacus(bool *ARR, int ARRSIZE){
    int i = latestAbacus(*ARR, ARRSIZE);
    
    if(i == ARRSIZE - 1){
        ;
    }else{
        ARR[i] = false;
        ARR[i + 1] = true;
    }

    return false; // UNLESS abacus cannot be moved any longer!
}