#include <stdio.h>
#include <string.h>
#include "logic.h"
#include "storage.h"



int add_task(task *task_list, int* next_ID, char* taskname, char* errortext)
{
    if (*next_ID >= MAX_NUM_OF_TASKS) {
        strcpy(errortext, "unable to add - max number of tasks are reached\n");
        return 1;
    }

    task new_task;
    new_task.ID = *next_ID;
    new_task.progress = 0;
    new_task.prior = 0;
    if (strlen(taskname) == 0) {
        strcpy(errortext, "unable to add - no title is provided\n");
        return 2;
    } else {
        strcpy(new_task.name, taskname);
    }

    task_list[*next_ID] = new_task;

    (*next_ID)++;

    return 0;
}

int empty_list(task *task_list, int* next_ID, char* errortext)
{
    if (*next_ID > 0) {
        *next_ID = 0;
        return 0;
    }
    strcpy(errortext, "the list is empty\n");
    return 1;
}

int remove_task(task *task_list, int* next_ID, char* operand, char* errortext)
{
    int start_delete = 0;
    int task_to_del = strtol(operand, errortext, 10);
    if (*next_ID > 0) {
        for (int i = 0; i < *next_ID; i++) {
            if (task_list[i].ID == task_to_del) {
                start_delete = 1;
            }
            if (start_delete && i < *next_ID - 1) {
                task_list[i] = task_list[i + 1];
            }
        }

    } else {
        strcpy(errortext, "no tasks to delete\n");
        return 1;
    }
    if (!start_delete) {
        strcpy(errortext, "no such task\n");
        return 2;
    }
    (*next_ID)--;
    return 0;
}
