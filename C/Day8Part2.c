#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *children;
    int numChildren;
    int value;
} Node;

int GetMeta(FILE* in) {
    int meta;
    fscanf(in, "%d ", &meta);
    return meta;
}

Node GetChild(FILE* in, Node parent) {
    int children, metas;
    Node child;
    fscanf(in, "%d %d ", &children, &metas);
    child.children = malloc(sizeof(Node) * children + 1);
    child.numChildren = children;
    child.value = 0;
    for (int i=0; i<children; i++) {
        Node grandchild = GetChild(in, child);
        *(child.children + i) = grandchild;
    }
    if (children == 0) {
        for (int i=0; i<metas; i++) {
            child.value += GetMeta(in);
        }
    }
    else {
        for (int i=0; i<metas; i++) {
            int index = GetMeta(in);
            if (index <= children) {
                child.value += (*(child.children + index - 1)).value;
            }
        }
    }
    return child;
}

int main() {
    Node root;
    root.children = malloc(sizeof(Node) + 1);
    root.value = 0;
    FILE* input = fopen("Day8.txt", "r");
    printf("Final Result: %d", GetChild(input, root).value);

    return 0;
}
