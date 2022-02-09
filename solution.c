#include <stdio.h>
#include <stdbool.h>
void printAbacus(bool *ARR, int ARRSIZE);
int latestAbacus(bool *ARR, int ARRSIZE);
bool moveAbacus(bool *ARR, int ARRSIZE);

int main(){
    int SQUARESIZE = 0;
    printf("Width & length of the square? ");
    scanf("%i",&SQUARESIZE);
    int ARRSIZE = SQUARESIZE * 2;

    bool ARR[ARRSIZE];
    for(int i = 0; i < ARRSIZE; i++){
        ARR[i] = i<SQUARESIZE ? true : false;
    }
    
    int count = 1;
    printAbacus(ARR, ARRSIZE);
    while(!moveAbacus(ARR, ARRSIZE)){
        printAbacus(ARR, ARRSIZE);
        count++;
    }
    //printAbacus(ARR, ARRSIZE);
    
    printf("%i possibilities found\n",count);
    return 0;
}

void printAbacus(bool *ARR, int ARRSIZE){
    for(int i = 0; i < ARRSIZE; i++){
        printf(ARR[i] ? "O" : "-");
    }
    printf("\n");
}

int latestAbacus(bool *ARR, int ARRSIZE){
    for(int i = ARRSIZE - 1; i >= 0; i--){
        if(ARR[i]){return i;}
    }
    return -1;
}

bool moveAbacus(bool *ARR, int ARRSIZE){
    int i = latestAbacus(ARR, ARRSIZE);
    int j = 0;

    if(i == ARRSIZE - 1){
        while(ARR[i]){
            j++;
            ARR[i] = false;
            i--;
        }

        i = latestAbacus(ARR, ARRSIZE);
        if(i == -1){
            return true;
        }
        if(i < 0){
            printf("Left Outside of array error!\n");
            i = 0;
        }
        ARR[i] = false;
        
        for(; j >= 0; j--){
            i++;
            if(i >= ARRSIZE){
                printf("Right Outside of array error!\n");
                i = ARRSIZE - 1;
            }
            ARR[i] = true;
        }

    }else{
        ARR[i] = false;
        ARR[i + 1] = true;
    }

    return false; // UNLESS abacus cannot be moved any longer!
}