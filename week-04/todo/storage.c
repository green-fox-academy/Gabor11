#include <stdio.h>
#include "logic.h"
#include "storage.h"

int add_task(task task_list[], int* next_ID, char* taskname, char* errortext)
{
    if (*next_ID >= MAX_NUM_OF_TASKS) {
        strcpy(errortext, "unable to add - max number of tasks are reached\n");
        return 1;
    }

    task new_task;
    new_task.ID = *next_ID;
    new_task.progress = 0;
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

int lists_tasks(task task_list[], int* next_ID, char* errortext)
{

}
