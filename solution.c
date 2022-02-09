#include <stdio.h>
#include <stdbool.h>
void printAbacus(bool *ARR, int ARRSIZE);
int latestAbacus(bool *ARR, int ARRSIZE);
int moveAbacus(bool *ARR, int ARRSIZE);

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
    int try = 1;
    printAbacus(ARR, ARRSIZE);
    while(true){
        //printf("count = %i | ",count);
        try = moveAbacus(ARR, ARRSIZE);
        //printAbacus(ARR, ARRSIZE);
        if(try == -1){
            break;
        }else{
            count += try;
        }
        
    }
    
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

int moveAbacus(bool *ARR, int ARRSIZE){
    int i = latestAbacus(ARR, ARRSIZE);
    int j = 0;

    //printf("i = %i | ",i);

    if(i == ARRSIZE - 1){
        while(ARR[i]){
            j++;
            ARR[i] = false;
            i--;
        }

        i = latestAbacus(ARR, ARRSIZE);
        if(i == -1){
            //printAbacus(ARR, ARRSIZE);
            return -1;
            // End of the line
        }
        /*
        if(i < 0){
            printf("Left Outside of array error!\n");
            i = 0;
        }
        */
        ARR[i] = false;
        
        for(; j >= 0; j--){
            i++;
            /*
            if(i >= ARRSIZE){
                printf("Right Outside of array error!\n");
                i = ARRSIZE - 1;
            }
            */
            ARR[i] = true;
        }
        return 1;
    }else{
        ARR[i] = false;
        ARR[ARRSIZE - 1] = true;
        return ARRSIZE - i - 1;
    }
}