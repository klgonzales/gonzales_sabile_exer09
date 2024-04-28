#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    printf("Enter N: ");
    scanf("%d", &N);
    int move = N;

    int option[N+2][N+2];
    int nopts[N+2];

    // fill up
    for (int i=N; i>0; i--) { 
        for (int j=i; j>0; j--) { 
            option[N-i+1][j] = N-j+1;
        }
        nopts[N-i+1] = i;
    }

    while (move != 0) {
        
        // print solution
        for (int i=1; i<move+1; i++) printf("%d ", option[i][nopts[i]]);
        printf("\n");

        // modify nopts
        if (--nopts[move] < 1) move--;
        else {
            for (int i=move+1; i<move+1+nopts[move]-1; i++) {
                nopts[i] = nopts[move]-i+move;
            }
            move += nopts[move]-1;
        } 
    }
}