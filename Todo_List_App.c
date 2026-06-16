#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 100

typedef struct {
    char name[MAX_TASK_LENGTH];
    int day;
    int month;
    int year;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task();
void display_tasks();
bool validate_date(int day, int month, int year);
void delete_task(int task_number);

void userChoice(char *choice) {
    if (strcmp(choice, "1") == 0) {
        add_task();
    } 
    else if (strcmp(choice, "2") == 0) {
        // Check if there are any tasks before proceeding
        if (task_count == 0) {
            printf("No tasks available to delete.\n\n");
            return;
        }
        // Display existing tasks before asking for deletion
        display_tasks();

        int task_number;
        printf("Enter task number to delete: ");
        scanf("%d", &task_number);
        // Clear the newline from previous input
        getchar();
        delete_task(task_number);
    } 
    else if (strcmp(choice, "3") == 0) {
        display_tasks();
    } 
    else if (strcmp(choice, "4") == 0) {
        printf("Exiting application. Goodbye!\n");
    } 
    else {
        printf("Invalid choice!\n\n");
    }
}

void delete_task(int task_number) {
    int index = task_number - 1;
    if (index >= 0 && index < task_count) {
        printf("Task '%s' deleted successfully!\n\n", tasks[index].name);
         
        // After deletion, shift all subsequent elements one position to the left
        for (int i = index; i < task_count - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        task_count--;
    } else {
        printf("Invalid task number!\n\n");
    }
}

void display_tasks() {
    if (task_count == 0) {
        printf("No tasks available.\n\n");
        return;
    }
    printf("\nYour Tasks:\n");
    for (int i = 0; i < task_count; ++i) {
        printf("%d. %s - Deadline: %02d-%02d-%d\n", 
               i + 1, 
               tasks[i].name, 
               tasks[i].day, 
               tasks[i].month, 
               tasks[i].year);
    }
    printf("\n");
}

bool validate_date(int day, int month, int year) {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    
    int days_in_month;
    if (month == 2) {
        if((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
            days_in_month = 29;
        else 
            days_in_month = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    }
    else {
        days_in_month = 31;
    }
    return day >= 1 && day <= days_in_month;
}

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n\n");
        return;
    }

    Task new_task;
    
    printf("Enter task name: ");
    
    // Read the task name
    fgets(new_task.name, MAX_TASK_LENGTH, stdin);

    // Remove trailing newline if present
    new_task.name[strcspn(new_task.name, "\n")] = '\0';
    
    printf("Enter deadline (DD MM YYYY): \n");
    printf("Day: ");
    scanf("%d", &new_task.day);
    printf("Month: ");
    scanf("%d", &new_task.month);
    printf("Year: ");
    scanf("%d", &new_task.year);

    // Clear the newline from previous input
    getchar();

    if (!validate_date(new_task.day, new_task.month, new_task.year)) {
        printf("Invalid date! Task not added.\n\n");
        return;
    }

    tasks[task_count] = new_task;
    task_count++;
    printf("Task added successfully!\n\n");
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
