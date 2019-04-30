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

node react(node head) {
    node temphead = head;
    node currnode = temphead;
    while (currnode->next != NULL) {
        if (currnode->data == (currnode->next->data - 32) || currnode->data == (currnode->next->data + 32)) {
            if (currnode == temphead) {
                temphead = currnode->next->next;
                currnode = temphead;
            }
            else {
                currnode = currnode->prev;
                currnode->next = currnode->next->next->next;
                currnode->next->prev = currnode;
            }
        }
        else {
            currnode = currnode->next;
        }
    }
    return temphead;
}

int main() {
    FILE* input = fopen("Day5.txt", "r");
    int count, min=11000;
    for (int i=0;i<26;i++) {
        node head = createNode(NULL);
        node currentnode = head;
        char buffer;
        while ((int)(buffer = fgetc(input)) != EOF) {
            if (buffer != 'a'+i && buffer != 'a'+i-32) {
                currentnode = addNode(currentnode, buffer);
            }
        }
        count = 0;
        node test = react(head);
        currentnode = test;
        while (isalpha(currentnode->data)) {
            count++;
            currentnode = currentnode->next;
        }
        if (count<min) {min=count;}
        rewind(input);
    }
    printf("Final Result: %d", min);
    return 0;
}
