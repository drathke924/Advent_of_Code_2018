#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct Entry {
    int datetime;
    int minute;
    char data[25];
} Entry;

typedef struct Guard {
    int id;
    int maxminute;
    int sleeptime;
    int minutes[60];
} Guard;

void sort_chron(Entry* book, int n){
    Entry temp;
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i=0;i<n-1;i++) {
            if (book[i].datetime > book[i+1].datetime) {
                temp = book[i];
                book[i] = book[i+1];
                book[i+1] = temp;
                swapped = 1;
            }
        }
    }
}

void get_input(Entry* book, FILE* file) {

}

int main () {
    FILE* input = fopen("Day4.txt", "r");
    Guard regiment[4000];
    long month=0, day=0, hour=0, minute=0;
    int index = 0;
    char buffer[44];
    Entry* logbook = malloc(sizeof(Entry));
    if (!input) {
        printf("BROKEN AUGH!");
        return 1;
    }
    while (fgets(buffer, 44, input)) {
        for (size_t i=6;i<17;i+=3) {
            char* end = &buffer[i+1];
            long n = strtol(&buffer[i], &end, 10);
            if (i==6) {month=n;}
            else if (i==9) {day=n;}
            else if (i==12) {hour=n;}
            else {minute=n;}
        }

        Entry temp;
        strcpy(temp.data, &buffer[19]);
        char* newline;
        if ((newline=strchr(temp.data, '\n')) != NULL) {
            *newline = '\0';
        }
        temp.datetime = month*1000000 + day*10000 + hour*100 + minute;
        temp.minute = minute;
        logbook[index] = temp;
        index++;
        logbook = realloc(logbook, sizeof(Entry)*(index + 1));
    }
    sort_chron(logbook, index);
    Guard currentguard;
    int fallsasleep;
    int wakesup;
    Guard sleepy;
    int max = 0;
    for (int i=0;i<index;i++) {
        if (logbook[i].data[0] == 'G') {
            sscanf(&logbook[i].data[7], "%d", &currentguard.id);
            if (regiment[currentguard.id].id == 0) {
                regiment[currentguard.id].id = currentguard.id;
                for (int j=0; j<60; j++) {
                    currentguard.minutes[j] = 0;
                }
            }
            currentguard = regiment[currentguard.id];
        }
        else if (logbook[i].data[0] == 'f') {
            fallsasleep = logbook[i].minute;
        }
        else if (logbook[i].data[0] == 'w') {
            wakesup = logbook[i].minute;
            for (int j=fallsasleep;j<wakesup;j++) {
                if (!currentguard.minutes[j]) {currentguard.minutes[j] = 0;}
                currentguard.minutes[j]++;
                currentguard.sleeptime++;
            }
            for (int j=0; j<60; j++) {
                if (currentguard.minutes[j] > max) {
                    currentguard.maxminute = j;
                    max = currentguard.minutes[j];
                    sleepy = currentguard;
                }
            }
            regiment[currentguard.id] = currentguard;
        }
    }
    printf("Final Result: %d", sleepy.id*sleepy.maxminute);
    free(logbook);
    fclose(input);
    return 0;
}
