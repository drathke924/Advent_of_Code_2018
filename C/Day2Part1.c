#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Label {
    int Count;
};

int main () {
    FILE* input = fopen("Day2.txt", "r");
    char tmp[1000];
    fscanf(input, "%s", tmp);
    int BOXSIZE = strlen(tmp);
    char* string = malloc(sizeof(char)*BOXSIZE + 1);
    rewind(input);
    int dubs = 0, trips = 0;
    struct Label l;
    struct Label* box = malloc(sizeof(l)*26 + 1);
    for (int i=0;i<26;i++) {
        box[i].Count = 0;
    }
    while (fscanf(input, "%[^\n]", string) != EOF){
        int boxdub = 0, boxtrip = 0;
        fscanf(input, "\n");
        for (int i=0;i<BOXSIZE;i++) {
            box[string[i] - 'a'].Count++;
        }
        for (int i=0;i<26;i++) {
            if (box[i].Count == 2 && boxdub == 0) {
                dubs++;
                boxdub = 1;
            }
            else if (box[i].Count == 3 && boxtrip == 0) {
                trips++;
                boxtrip = 1;
            }
            box[i].Count = 0;
        }
    }
    printf("Final Result: %d\n", dubs * trips);
    free(box);
    free(string);
    fclose(input);

    return 0;
}
