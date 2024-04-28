#include <stdio.h>
#include <stdlib.h>

/**
 * this program generates and prints all possible combinations of numbers from 1 to N.
 * it uses a backtracking algorithm to generate the combinations.
 */

int main() {
    int N;

    printf("Enter N: ");
    scanf("%d", &N);
    int move = N;

    int option[N+2][N+2];
    int nopts[N+2];

    // fill up the option array with initial values
    for (int i=N; i>0; i--) { 
        for (int j=i; j>0; j--) { 
            option[N-i+1][j] = N-j+1;
        }
        nopts[N-i+1] = i;
    }

    while (move != 0) {
        
        // print the current combination
        for (int i=1; i<move+1; i++) printf("%d ", option[i][nopts[i]]);
        printf("\n");

        // modify nopts array to generate the next combination
        if (--nopts[move] < 1) move--;
        else {
            for (int i=move+1; i<move+1+nopts[move]-1; i++) {
                nopts[i] = nopts[move]-i+move;
            }
            move += nopts[move]-1;
        } 
    }
}