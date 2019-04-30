#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int pos;
    int dir;
    int turn;
} Cart;

int findDir (char c) {
    if (c == '^') {return 1;}
    else if (c == '>') {return 2;}
    else if (c == 'v') {return 3;}
    else if (c == '<') {return 4;}
    return 0;
}

Cart * sortCarts(Cart *arr, int carts) {
    int sorted = 0;
    while (sorted != 1) {
        sorted = 1;
        for (int i=0; i<carts-1; i++) {
            if (arr[i].pos > arr[i+1].pos) {
                Cart temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                sorted = 0;
            }
        }
    }
    return arr;
}

int main() {
    Cart * cartarr = malloc(sizeof(Cart) + 1);
    FILE *input = fopen("Day13.txt", "r");
    int **arr, carts = 0;
    arr = malloc(sizeof(int)*150 + 1);
    char buffer[151];
    for (int i=0; i<150; i++) {
        arr[i] = malloc(sizeof(int)*150 + 1);
        for (int j=0; j<150; j++) {
            arr[i][j] = 0;
        }
    }
    for (int y=0; y<150; y++) {
        fgets(buffer, 151, input);
        for (int x=0; x<150; x++) {
            if (buffer[x] == ' ') {arr[y][x] = 0;}
            else if (buffer[x] == '-') {arr[y][x] = 1;}
            else if (buffer[x] == '|') {arr[y][x] = 2;}
            else if (buffer[x] == '+') {arr[y][x] = 3;}
            else if (buffer[x] == '\\') {arr[y][x] = 4;}
            else if (buffer[x] == '/') {arr[y][x] = 5;}
            else if (buffer[x] == '^' || buffer[x] == '<' || buffer[x] == '>' || buffer[x] == 'v'){
                /* if (arr[y-1][x] == '/' || ) */
                carts++;
                cartarr = realloc(cartarr, sizeof(Cart)*carts + 1);
                cartarr[carts - 1].x = x;
                cartarr[carts - 1].y = y;
                cartarr[carts - 1].pos = x + y*1000;
                cartarr[carts - 1].dir = findDir(buffer[x]);
                cartarr[carts - 1].turn = 0;
            }
        }
        fseek(input, 1, SEEK_CUR);
    }
    for (int i=0; i<carts; i++) {
        printf("%06d\n", cartarr[i].pos);
    }
    return 0;
}
