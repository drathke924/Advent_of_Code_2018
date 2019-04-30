#include <stdio.h>
#include <stdlib.h>

typedef struct Reqs {
    int available;
    int complete;
    int required[26];
} Reqs;

int main () {
    FILE* input = fopen("Day7.txt", "r");
    Reqs steps[26];
    char a, b;
    char result[27];
    int finished = 0, index = 0;
    for (int i=0;i<26;i++) {
        steps[i].available = 1;
        steps[i].complete = 1;
        for (int j=0;j<26;j++) {
            steps[i].required[j] = 0;
        }
    }
    while (fscanf(input, "Step %c must be finished before step %c can begin.\n", &a, &b) != EOF) {
        steps[b-'A'].available = 0;
        steps[a-'A'].complete = 0;
        steps[b-'A'].complete = 0;
        steps[b-'A'].required[a-'A'] = 1;
    }
    while (finished == 0) {
        finished = 1;
        for (int i=0;i<26;i++) {
            if (steps[i].complete == 0) {
                finished = 0;
                if (steps[i].available == 0) {
                    steps[i].available = 1;
                    for (int j=0; j<26; j++) {
                        if (steps[i].required[j] == 1 && steps[j].complete == 1) {
                            steps[i].required[j] = 0;
                        }
                        else if (steps[i].required[j] == 1 && steps[j].complete == 0) {
                            steps[i].available = 0;
                        }
                    }

                }
                if (steps[i].available == 1) {
                    steps[i].complete = 1;
                    result[index] = (char)(i+'A');
                    printf("%c\n", (char)(i+'A'));
                    index++;
                    break;
                }
            }
        }
    }
    result[26] = '\0';
    printf("Final Result: %s\n", result);


    return 0;
}
