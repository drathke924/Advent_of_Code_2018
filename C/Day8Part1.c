#include <stdio.h>
#include <stdlib.h>

int GetMeta(FILE* in) {
    int meta;
    fscanf(in, "%d ", &meta);
    return meta;
}

int GetChild(FILE* in) {
    int children, metas, out = 0;
    fscanf(in, "%d %d ", &children, &metas);
    for (int i=0; i<children; i++) {
        out += GetChild(in);
    }
    for (int i=0; i<metas; i++) {
        out += GetMeta(in);
    }
    return out;
}

int main() {
    FILE* input = fopen("Day8.txt", "r");
    printf("Final Result: %d", GetChild(input));

    return 0;
}
