#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int getsum(int *arr, int arrsize, int buff) {
    int total = 0;
    for (int i=0; i<arrsize; i++) {
        if(arr[i] == 1) {total += (i-buff);}
    }
    return total;
}

int main () {
    FILE* input = fopen("Day12.txt", "r");
    char initial[99];
    int buffer = 200;
    int *current;
    int states[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    fscanf(input, "initial state: %s\n", &initial);
    int pots = strlen(initial) + buffer*2;
    current = malloc(sizeof(int)*pots + 1);
    for(int i=0; i<pots; i++){
        current[i] = 0;
    }
    for (int i=0; i<strlen(initial); i++){
        current[i+buffer] = ((initial[i] == '#') ? 1 : 0);
    }
    fscanf(input, "\n");
    char state[5];
    char result = 'a';
    while(fscanf(input, "%s => %c\n", &state, &result) != EOF) {
        int index = 0;
        for (int i = 0; i<5; i++) {
            if (state[i] == '#'){index += pow(2, i);}
        }
        if (result == '#'){states[index] = 1;}
    }
    int last = getsum(current, pots, buffer), diff=0, curr, lastdiff, breakpoint, stepsize=10;
    for (int i=1; i<=1000; i++) {
        int *temp;
        temp = malloc(sizeof(int)*pots + 1);
        for (int j=0; j<pots; j++) {
            temp[j] = 0;
        }
        for (int j=0; j<pots-5; j++) {
            int state = 0;
            for (int k=0; k<5; k++) {
                if (current[j+k] == 1) {state += pow(2, k);}
            }
            if (states[state] == 1) {temp[j+2] = 1;}
            else {temp[j+2] = 0;}
        }
        for (int j=0; j<pots; j++) {
            current[j] = temp[j];
        }
        if (i%stepsize==0) {
            curr = getsum(current, pots, buffer);
            diff = curr - last;
            last = curr;
            if (diff==lastdiff) {
                breakpoint = i;
                break;
            }
            else {
                lastdiff = diff;
            }
        }
    }
    printf("Final Result: %lld\n", (last + (((50000000000-breakpoint))*(lastdiff/stepsize))));

    return 0;
}
