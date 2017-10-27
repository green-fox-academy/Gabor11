#ifndef LOGIC_H__
#define LOGIC_H__
#include "storage.h"

#define MAX_COMMAND_LENGTH 4
#define NUM_OF_COMMANDS 9

char commands[NUM_OF_COMMANDS][MAX_COMMAND_LENGTH];

void defining_commands();

int process(task *task_list, char *input, int *next_ID, char *errortext, char *filename);

int list(task *task_list, int *next_ID, char *errortext);

int progress_task(task *task_list, int *next_ID, char *operand, char *errortext);

int prior_task(task *task_list, int *next_ID, char *operand, char *errortext);

char* get_command(char *input, char *errortext);

#endif /* LOGIC_H__*/
