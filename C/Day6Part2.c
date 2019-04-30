#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Center {
    int x;
    int y;
} Center;

int main () {
    FILE* input = fopen("Day6.txt", "r");
    int a, b, lines=0, region=0;
    while(fscanf(input, "%d,%d", &a, &b) != EOF) {
        lines++;
    }
    Center centers[lines];
    rewind(input);
    int index = 0;
    while(fscanf(input, "%d,%d", &a, &b) != EOF) {
        centers[index].x = a;
        centers[index].y = b;
        index++;
    }
    for(int i=0;i<500;i++) {
        for (int j=0;j<500;j++) {
            int totaldist = 0;
            for (int k=0; k<lines; k++) {
                totaldist += abs(centers[k].x-i)+abs(centers[k].y-j);
            }
            if (totaldist < 10000) {
                region++;
            }
        }
    }
    printf("Final Result: %d\n", region);
    return 0;
}
