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
    int buffer = 100;
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
    for (int i=0; i<20; i++) {
        int *temp;
        temp = malloc(sizeof(int)*pots + 1);
        for (int j=0; j<pots; j++) {
            temp[j] = 0;
        }
        for (int j=0; j<pots-5; j++) {
            int state = 0;
            for (int k=0; k<5; k++) {
                /*printf("%d", current[j+k]);*/
                if (current[j+k] == 1) {state += pow(2, k);}
            }
            /*printf("%d, %d\n", states[state], state);*/
            if (states[state] == 1) {temp[j+2] = 1;}
            else {temp[j+2] = 0;}
        }
        for (int j=0; j<pots; j++) {
            current[j] = temp[j];
            /*printf("%d", current[j]);*/
        }
        /*printf("\n");*/
    }
    printf("Final Result: %d\n", getsum(current, pots, buffer));

    return 0;
}
