#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE* input = fopen("Day3.txt", "r");
    int id, x, y, width, height;
    int** arr = malloc(1000*sizeof(int*) + 1);
    for (int i=0;i<1000;i++) {
        arr[i] = malloc(1000*sizeof(int) + 1);
        for (int j=0;j<1000;j++) {
            arr[i][j] = 0;
        }
    }
    while (fscanf(input, "#%d @ %d,%d: %dx%d\n", &id, &x, &y, &width, &height) != EOF) {
        int intact = 1;
        for (int i=x;i<x+width;i++) {
            for (int j=y;j<y+height;j++) {
                arr[i][j]++;
            }
        }
    }
    rewind(input);
    while (fscanf(input, "#%d @ %d,%d: %dx%d\n", &id, &x, &y, &width, &height) != EOF) {
        int intact = 1;
        for (int i=x;i<x+width;i++) {
            for (int j=y;j<y+height;j++) {
                if (arr[i][j] > 1) {
                    intact = 0;
                }
            }
        }
        if (intact == 1) {
            printf("Final Result: %d", id);
        }
    }
    for (int i=0;i<1000;i++) {
        free(arr[i]);
    }
    free(arr);
    fclose(input);

    return 0;
}
