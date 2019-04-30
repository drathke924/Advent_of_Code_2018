#include <stdio.h>
#include <stdlib.h>

typedef struct Reqs {
    int available;
    int waiting;
    int complete;
    int required[26];
} Reqs;

int main () {
    FILE* input = fopen("Day7.txt", "r");
    Reqs steps[26];
    char a, b;
    int finished = 0, second = 0, result, workers = 0;
    for (int i=0;i<26;i++) {
        steps[i].available = 1;
        steps[i].complete = 1;
        steps[i].waiting = -1;
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
                if (steps[i].available == 1 && steps[i].waiting == -1 && workers < 5) {
                    steps[i].waiting = second + i + 61;
                    workers++;
                }
                if (steps[i].available == 1 && second == steps[i].waiting) {
                    steps[i].available = 0;
                    steps[i].complete = 1;
                    workers--;
                    second--;
                    break;
                }
                if (steps[i].available == 1 && steps[i].waiting != -1) {
                }
            }
        }
        second++;
    }
    printf("Final Result: %d\n", second - 1);


    return 0;
}
