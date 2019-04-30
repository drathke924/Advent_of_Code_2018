#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE* input = fopen("Day3.txt", "r");
    int x, y, width, height, count = 0, maxx = 0, maxy = 0;
    int** arr = malloc(1000*sizeof(int*) + 1);
    for (int i=0;i<1000;i++) {
        arr[i] = malloc(1000*sizeof(int) + 1);
        for (int j=0;j<1000;j++) {
            arr[i][j] = 0;
        }
    }
    while (fscanf(input, "#%*d @ %d,%d: %dx%d\n", &x, &y, &width, &height) != EOF) {
        int intact = 1;
        for (int i=x;i<x+width;i++) {
            for (int j=y;j<y+height;j++) {
                if (arr[i][j] == 1) {
                    count++;
                }
                if (arr[i][j] > 0) {
                    intact = 0;
                }
                arr[i][j]++;
            }
        }
    }
    for (int i=0;i<1000;i++) {
        free(arr[i]);
    }
    free(arr);
    printf("Final Result: %d", count);
    fclose(input);

    return 0;
}
