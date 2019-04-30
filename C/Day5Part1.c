#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct LinkedList {
    char data;
    struct LinkedList *prev;
    struct LinkedList *next;
};

typedef struct LinkedList *node;

node createNode(node head){
    node temp;
    temp = malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->prev = head;
    return temp;
}

node addNode(node head, char value) {
    node temp = createNode(head);
    head->data = value;
    head->next = temp;
    return head->next;
}

int main() {
    FILE* input = fopen("Day5.txt", "r");
    node head = createNode(NULL);
    node currentnode = head;
    char buffer;
    while ((int)(buffer = fgetc(input)) != EOF) {
        currentnode = addNode(currentnode, buffer);
    }
    currentnode = head;
    while (currentnode->next != NULL) {
        if (currentnode->data == (currentnode->next->data - 32) || currentnode->data == (currentnode->next->data + 32)) {
            if (currentnode == head) {
                head = currentnode->next->next;
                currentnode = head;
            }
            else {
                currentnode = currentnode->prev;
                currentnode->next = currentnode->next->next->next;
                currentnode->next->prev = currentnode;
            }
        }
        else {
            currentnode = currentnode->next;
        }
    }
    currentnode = head;
    int count = 0;
    while (currentnode != NULL) {
        if (isalpha(currentnode->data)) {
            count++;
        }
        currentnode = currentnode->next;
    }
    printf("Final Result: %d", count);
    return 0;
}
