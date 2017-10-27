#ifndef STORAGE_H__
#define STORAGE_H__

#define MAX_NUM_OF_TASKS 10

typedef struct{
    int ID;
    int progress;
    char name[256];
} task;

int add_task(task *task_list, int* next_ID, char* taskname, char* errortext);

int empty_list(task *task_list, int* next_ID, char* errortext);

int remove_task(task *task_list, int* next_ID, char* operand, char* errortext);

#endif /* STORAGE_H__*/

