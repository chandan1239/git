#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximum_classes 5  
typedef struct {
    char *dayName;         
    char **classNames;     
} Timetable;


void initializeTimetable(Timetable *timetable);
void enterClasses(Timetable *timetable);
void displayTimetable(Timetable *timetable);
void freeTimetable(Timetable *timetable);

int main() {
    Timetable timetable[5]; 

    initializeTimetable(timetable);
    enterClasses(timetable);
    displayTimetable(timetable);
    freeTimetable(timetable);

    return 0;
}

void initializeTimetable(Timetable *timetable) {
    const char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    for (int i = 0; i < 5; i++) {
       
        timetable[i].dayName = (char *)malloc(strlen(days[i]) + 1);
        strcpy(timetable[i].dayName, days[i]);

        timetable[i].classNames = (char **)malloc(maximum_classes * sizeof(char *));
        for (int j = 0; j < maximum_classes; j++) {
            timetable[i].classNames[j] = NULL;  
        }
    }
}

void enterClasses(Timetable *timetable) {
    for (int i = 0; i < 5; i++) {
        printf("\nEnter classes for %s:\n", timetable[i].dayName);
        for (int j = 0; j < maximum_classes; j++) {
            char className[100]; 
            printf("Enter class %d : ", j + 1);
            fgets(className, sizeof(className), stdin);
            className[strcspn(className, "\n")] = '\0'; 

            timetable[i].classNames[j] = (char *)malloc(strlen(className) + 1);
            strcpy(timetable[i].classNames[j], className);
        }
    }
}

void displayTimetable(Timetable *timetable) {
    printf("\nWeekly Timetable:\n");
    for (int i = 0; i < 5; i++) {
        printf("\n%s:\n", timetable[i].dayName);
        int j = 0;
        while (timetable[i].classNames[j] != NULL) {
            printf("  %s\n", timetable[i].classNames[j]);
            j++;
        }
    }
}

void freeTimetable(Timetable *timetable) {
    for (int i = 0; i < 5; i++) {

        free(timetable[i].dayName);

        for (int j = 0; j < maximum_classes; j++) {
            if (timetable[i].classNames[j] != NULL) {
                free(timetable[i].classNames[j]);
            }
        }
        free(timetable[i].classNames);
    }
}
