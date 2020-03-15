#include "stdio.h"

EightQueen();

int main(){
    int Q[8][8], i ,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            Q[i][j] = 0;
        }
    }
    EightQueen();
}