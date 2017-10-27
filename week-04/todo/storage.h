#ifndef STORAGE_H__
#define STORAGE_H__

#define MAX_NUM_OF_TASKS 10

typedef struct{
    int ID;
    int progress;
    char name[256];
    int prior;
} task;

int add_task(task *task_list, int* next_ID, char* taskname, char* errortext);

int empty_list(task *task_list, int* next_ID, char* errortext);

int remove_task(task *task_list, int* next_ID, char* operand, char* errortext);

int write_to_file(task *task_list, int *next_ID, char *errortext, char* filename);

int read_from_file(task *task_list, int *next_ID, char *errortext, char *filename);

#endif /* STORAGE_H__*/

