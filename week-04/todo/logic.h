#include "storage.h"

#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED

#define MAX_COMMAND_LENGTH 4
#define NUM_OF_COMMANDS 9

char commands[NUM_OF_COMMANDS][MAX_COMMAND_LENGTH];

void defining_commands();

int process(task task_list[], char *input, int *next_ID, char *errortext);

char* get_command(char *input, char *errortext);

#endif // LOGIC_H_INCLUDED
