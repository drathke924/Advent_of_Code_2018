#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int gridserial;
    FILE* input = fopen("Day11.txt", "r");
    fscanf(input, "%d", &gridserial);
    int maxx, maxy, bestsize, maxfuel=-100;
    int fuelgrid[301][301];
    for (int y=1; y<=300; y++) {
        for (int x=1; x<=300; x++) {
            fuelgrid[x][y] = 0;
        }
    }
    for (int y=1; y<=300; y++) {
        for (int x=1; x<=300; x++) {
            int rackid = x+10;
            int power = rackid*((rackid*(y)) + gridserial);
            char num[99];
            snprintf(num, 98, "%d", power);
            int fuel = (num[strlen(num)-3]-'0')-5;
            fuelgrid[x][y] = fuel + fuelgrid[x-1][y] + fuelgrid[x][y-1] - fuelgrid[x-1][y-1];
        }
    }
    for (int size=1;size<300;size++) {
        for (int y=size; y<=300; y++) {
            for (int x=size; x<=300; x++) {
                int cell = fuelgrid[x][y] - fuelgrid[x-size][y] - fuelgrid[x][y-size] + fuelgrid[x-size][y-size];
                if (cell > maxfuel) {
                    maxfuel = cell;
                    bestsize = size;
                    maxx = x-size;
                    maxy = y-size;
                }
            }
        }
    }
    printf("Final Result: %d,%d,%d\n", maxx+1, maxy+1, bestsize);
    return 0;
}
