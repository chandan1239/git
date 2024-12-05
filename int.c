#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void initializeSlots(char** timeSlots, int numTimeSlots);
void enterTasks(char** timeSlots, char** tasks, int numTimeSlots);
void displaySchedule(char** timeSlots, char** tasks, int numTimeSlots);

int main() {
    int numTimeSlots = 5;
    char** timeSlots = (char*)malloc(numTimeSlots * sizeof(char));
    char** tasks = (char*)malloc(numTimeSlots * sizeof(char));
    initializeSlots(timeSlots, numTimeSlots);
    enterTasks(timeSlots, tasks, numTimeSlots);
    displaySchedule(timeSlots, tasks, numTimeSlots);
    for (int i = 0; i < numTimeSlots; i++) {
        free(tasks[i]);
    }
    free(timeSlots);
    free(tasks);

    return 0;
}
void initializeSlots(char** timeSlots, int numTimeSlots) {
    timeSlots[0] = "";
    timeSlots[1] = "";
    timeSlots[2] = "";
    timeSlots[3] = "";
    timeSlots[4] = "";
}
void enterTasks(char** timeSlots, char** tasks, int numTimeSlots) {
    char buffer[100];
    for (int i = 0; i < numTimeSlots; i++) {
        printf("Enter task for %s: ", timeSlots[i]);
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        tasks[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(tasks[i], buffer);
    }
}
void displaySchedule(char** timeSlots, char** tasks, int numTimeSlots) {
    printf("\nSchedule for the day:\n");
    for (int i = 0; i < numTimeSlots; i++) {
        printf("%s: %s\n", timeSlots[i], tasks[i]);
    }
}