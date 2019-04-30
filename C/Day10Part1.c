#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct Point {
    int x;
    int y;
    int h;
    int v;
} Point;

int main () {
    FILE* input = fopen("Day10.txt", "r");
    int lines=0;
    while(fscanf(input, "%*[^\n]") != EOF) {
        fscanf(input, "\n");
        lines++;
    }
    rewind(input);
    Point points[lines];
    int tempx, tempy, temph, tempv, index = 0;
    while(fscanf(input, "position=<%d,  %d> velocity=<%d, %d>\n", &tempx, &tempy, &temph, &tempv) != EOF) {
        points[index].x = tempx;
        points[index].y = tempy;
        points[index].h = temph;
        points[index].v = tempv;
        index++;
    }
    int64_t minx = 100000, miny = 100000, maxx = -100000, maxy = -100000, lastarea = 100000000000, area;
    while (1) {
        minx = 100000;
        miny = 100000;
        maxx = -100000;
        maxy = -100000;
        for (int i=0;i<lines;i++) {
            points[i].x += points[i].h;
            points[i].y += points[i].v;
            if(points[i].x < minx){minx = points[i].x;}
            if(points[i].x > maxx){maxx = points[i].x;}
            if(points[i].y < miny){miny = points[i].y;}
            if(points[i].y > maxy){maxy = points[i].y;}
        }
        area = (maxx-minx)*(maxy-miny);
        if (maxy-miny == 9) {
            for (int i=miny; i<=maxy; i++) {
                for (int j=minx; j<=maxx; j++) {
                    int printed=0;
                    for (int check=0; check<=lines; check++) {
                        if (points[check].x==j && points[check].y == i && printed==0) {
                            printf("X");
                            printed = 1;
                        }
                    }
                    if(printed==0) {printf(" ");}
                }
                printf("\n");
            }
            break;
        }
        else {
            lastarea = area;
        }
    }
    return 0;
}
