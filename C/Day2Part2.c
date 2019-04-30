#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE* input = fopen("Day2.txt", "r");
    char tmp[1000];
    fscanf(input, "%s", tmp);
    int BOXSIZE = strlen(tmp), LINES = 0;
    char box[BOXSIZE];
    rewind(input);
    int index = 0;
    while(fscanf(input, "%s", box) != EOF) {
        fscanf(input, "\n");
        LINES++;
    }
    rewind(input);
    char boxes[LINES][BOXSIZE];
    while (fscanf(input, "%s", box) != EOF){
        int numdiff = 0, toomany = 0;
        char diff = 'a';
        fscanf(input, "\n");
        for (int i=0;i<index;i++) {
            toomany = 0;
            numdiff = 0;
            for (int j=0;j<BOXSIZE;j++) {
                if ((box[j] - 'a') != (boxes[i][j] - 'a')) {
                    if (numdiff < 1) {
                        numdiff++;
                        diff = box[j];
                    }
                    else {
                        toomany = 1;
                        break;
                    }
                }
                if (toomany == 1) {
                    break;
                }
            }
            if (toomany == 0 && numdiff == 1) {
                printf("Final Result: ");
                for (int j=0;j<BOXSIZE;j++){
                    if(box[j]==boxes[i][j]) {
                        printf("%c", box[j]);
                    }
                }
                printf("\n");
            }
        }
        for (int i=0;i<BOXSIZE;i++) {
            boxes[index][i] = box[i];
        }
        index++;
    }
    fclose(input);
    return 0;
}
