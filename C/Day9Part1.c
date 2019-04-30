#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int data;
    struct LinkedList *prev;
    struct LinkedList *next;
};

typedef struct LinkedList *Node;

Node addMarble(Node curr, int mar) {
    curr = curr->next;
    Node temp = malloc(sizeof(struct LinkedList));
    temp->data = mar;
    curr->next->prev = temp;
    temp->next = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return temp;
}

int removeMarble(Node curr, int mar) {
    int out;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    out = curr->data;
    return out;
}

void readout(Node curr) {
    Node temp = malloc(sizeof(curr));
    temp = curr;
    printf("%d", temp->data);
    temp = temp->next;
    while(temp != curr) {
        printf(",%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main () {
    FILE* input = fopen("Day9.txt", "r");
    int players, lastscore, currentscore = 0, marble = 0, currentelf = 0, max = 0, totalmarbs = 0;
    fscanf(input, "%d players; last marble is worth %d points", &players, &lastscore);
    int elves[players];
    for (int i=0; i<players; i++) {
        elves[i] = 0;
    }
    Node current = malloc(sizeof(struct LinkedList));
    current->prev = current;
    current->next = current;
    current->data = marble;
    totalmarbs++;
    while(marble < lastscore) {
        marble++;
        /*readout(current);*/
        if (marble % 23 != 0 || marble == 0) {
            current = addMarble(current, marble);
            totalmarbs++;
        } else {
            for (int i=0; i<7; i++) {
                current = current->prev;
            }
            currentscore = 0;
            currentscore += marble;
            currentscore += removeMarble(current, marble);
            current = current->next;
            elves[currentelf] += currentscore;
        }
        currentelf = (currentelf + 1) % players;
    }
    for (int i=0; i<players; i++) {
        if (elves[i] > max) {
            max = elves[i];
        }
    }
    printf("Final Result: %d\n", max);
    return 0;
}
