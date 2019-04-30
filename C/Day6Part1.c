#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
    int x_near;
    int y_near;
    int dist_near;
    int index_center;
    int equidistant;
} Point;

typedef struct Area {
    int x;
    int y;
    int infinite;
    int size;
} Area;

int main () {
    FILE* input = fopen("Day6.txt", "r");
    int a, b, minx = 1000, maxx = 0, miny = 1000, maxy = 0, lines=0;
    while(fscanf(input, "%d,%d", &a, &b) != EOF) {
        lines++;
    }
    Area centers[lines];
    Point **grid = (Point**)malloc(500 * sizeof(Point*));
    for (int i=0;i<500;i++) {
        grid[i] = (Point*)malloc(500 * sizeof(Point));
    }
    Area biggest;
    biggest.x = 0;
    biggest.y = 0;
    biggest.size = 0;

    rewind(input);
    int index = 0;
    while(fscanf(input, "%d,%d", &a, &b) != EOF) {
        if (a<minx) {minx=a;}
        if (a>maxx) {maxx=a;}
        if (b<miny) {miny=b;}
        if (b>maxy) {maxy=b;}
        centers[index].x = a;
        centers[index].y = b;
        centers[index].infinite = 0;
        centers[index].size = 0;
        index++;
    }
    for(int i=0;i<500;i++) {
        for (int j=0;j<500;j++) {
            grid[i][j].dist_near = 500;
            for (int k=0; k<lines; k++) {
                if (abs(centers[k].x-i)+abs(centers[k].y-j) < grid[i][j].dist_near) {
                    grid[i][j].x_near=centers[k].x;
                    grid[i][j].y_near=centers[k].y;
                    grid[i][j].dist_near=abs(centers[k].x-i)+abs(centers[k].y-j);
                    grid[i][j].index_center = k;
                    grid[i][j].equidistant = 0;
                }
                else if (abs(centers[k].x-i)+abs(centers[k].y-j) == grid[i][j].dist_near) {
                    grid[i][j].equidistant = 1;
                }
            }
            int index = grid[i][j].index_center;
            if (grid[i][j].equidistant ==0){centers[index].size++;}
            if (i<minx || i>maxx || j<miny || j>maxy) {
                centers[index].infinite = 1;
            }
        }
    }
    for (int i=0;i<lines;i++) {
        if (centers[i].infinite == 0 && centers[i].size > biggest.size) {
            biggest.x = centers[i].x;
            biggest.y = centers[i].y;
            biggest.size = centers[i].size;
        }
    }

    printf("Final Result: %d", biggest.size);
    return 0;
}
