#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of tasks
#define MAX_TASKS 100
// Maximum length of each task
#define MAX_TASK_LENGTH 100

// Character array to store tasks
char tasks[MAX_TASKS][MAX_TASK_LENGTH];
// Arrays to store the deadline of each task
int days[MAX_TASKS], months[MAX_TASKS], years[MAX_TASKS];
// Counter for the number of tasks
int task_count = 0;

void delete_task(int task_number);
void display_tasks();
void add_task();
bool validate_date(int day, int month, int year);


void userChoice(char *choice) {
    if (strcmp(choice, "1") == 0) {
        add_task();
    } else if (strcmp(choice, "2") == 0) {
        int task_number;
        printf("Enter task number to delete: ");
        scanf("%d", &task_number);
        
        // Clear the newline from previous input
        getchar();
        
        delete_task(task_number);
    } else if (strcmp(choice, "3") == 0) {
        display_tasks();
    } else if (strcmp(choice, "4") == 0) {
        printf("Exiting application. Goodbye!\n");
    } else {
        printf("Invalid choice!\n\n");
    }


void delete_task(int task_number) {
    printf("Function to delete a task with task number %d\n", task_number);
}

void display_tasks() {
    printf("Function to display all tasks\n");
}

void add_task() {
    printf("Function to add a task\n");
}

bool validate_date(int day, int month, int year) {
    if(year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    int days_in_month;
    if(month ==2){
        if((year % 400 == 0) || (year % 100 != 0 && year % 4 ==0))
            days_in_month = 29;
        else
            days_int_months = 28;
}
else if (month == 4 || month == 6 || month == 9 || month == 11){
days_in_month = 30;
}
else {
days_in_month = 31;
}
return day >= 1 && day <= days_in_month;
} 
int main() {
    char choice[10];
    printf("\nWelcome to the To-Do List Application!\n");

    while (1) {
        printf("Choose one operation:\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        fgets(choice, sizeof(choice), stdin);
        int len = strlen(choice);
        if (len > 0 && choice[len - 1] == '\n') {
            choice[len - 1] = '\0';
        }

        if (strcmp(choice, "4") == 0) {
            printf("Exiting application. Goodbye!\n");
            break;
        }
        
        userChoice(choice);
    }
    return 0;
}
