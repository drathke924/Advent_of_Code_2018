#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int gridserial;
    FILE* input = fopen("Day11.txt", "r");
    fscanf(input, "%d", &gridserial);
    int maxx, maxy, maxsize=-100;
    int fuelgrid[299][299];
    for (int y=0; y<299; y++) {
        for (int x=0; x<299; x++) {
            int rackid = x+10+1;
            int power = rackid*((rackid*(y+1)) + gridserial);
            char num[99];
            snprintf(num, 98, "%d", power);
            int fuel = (num[strlen(num)-3]-'0')-5;
            fuelgrid[x][y] = fuel;
        }
    }
    for (int i=0; i<297; i++) {
        for (int j=0; j<297; j++) {
            int cell = fuelgrid[j][i] + fuelgrid[j+1][i] + fuelgrid[j+2][i] + fuelgrid[j][i+1] + fuelgrid[j+1][i+1] + fuelgrid[j+2][i+1] + fuelgrid[j][i+2] + fuelgrid[j+1][i+2] + fuelgrid[j+2][i+2];
            if (cell > maxsize) {
                maxsize = cell;
                maxx = j;
                maxy = i;
            }
        }
    }
    printf("Final Result: %d,%d\n", maxx+1, maxy+1);
    return 0;
}
