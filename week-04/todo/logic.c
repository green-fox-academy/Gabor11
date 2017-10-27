#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic.h"
#include "storage.h"

void defining_commands()
{
	strcpy(commands[0], "-a");
	strcpy(commands[1], "-wr");
	strcpy(commands[2], "-rd");
	strcpy(commands[3], "-l");
	strcpy(commands[4], "-e");
	strcpy(commands[5], "-rm");
	strcpy(commands[6], "-c");
	strcpy(commands[7], "-p");
	strcpy(commands[8], "-lp");
}

int process(task *task_list, char *input,int *next_ID, char *errortext, char *filename)
{
    int switcher = -1;

    char command[MAX_COMMAND_LENGTH];
    char operand[256];

    strcpy(command, get_command(input, errortext));

    strcpy(operand, input + strlen(command) + 1);

    for (int i = 0; i < NUM_OF_COMMANDS; i++) {
        if (strcmp(commands[i],command) == 0) {
            switcher = i;
            break;
        }
    }

    switch (switcher) {
    case 0:
        if (add_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        else
            puts("new task added\n");
        break;
    case 1:
        if (write_to_file(task_list, next_ID, errortext, filename) != 0)
            puts(errortext);
        else
            puts("tasks have been written to \"tasks.csv\"");
        break;
    case 2:
        if (read_from_file(task_list, next_ID, errortext, filename) != 0)
            puts(errortext);
        else
            puts("tasks have been written to \"tasks.csv\"");
        break;
    case 3:
        if(list(task_list, next_ID, errortext) != 0)
            puts(errortext);
        break;
    case 4:
        if(empty_list(task_list, next_ID, errortext) != 0)
            puts(errortext);
        break;
    case 5:
        if(remove_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        break;
    case 6:
        if(progress_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        break;
    case 7:
        if(prior_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        break;
    case 8:
        //
        break;
    default:
        printf("default\n");

        break;
    }

}

char* get_command(char *input, char *errortext)
{
    char* tempstr = calloc(strlen(input) + 1, sizeof(char));
    strcpy(tempstr, input);
    tempstr = strtok(tempstr, " ");
    if (strlen(tempstr) >= MAX_COMMAND_LENGTH) {
        strcpy(errortext, "invalid length of operator");
        strcpy(tempstr, "err");
    }
    return tempstr;
}

int list(task *task_list, int *next_ID, char *errortext)
{
    if (*next_ID > 0) {
        printf("List by number\n");
        printf("====================\n");
        printf("Num | Progress | Text  | Prio\n");
        for (int i = 0; i < *next_ID; i++) {
            printf("%d.\t[%d%c]\t%s\t   %d\n", task_list[i].ID, task_list[i].progress, 37, task_list[i].name, task_list[i].prior);
        }
        return 0;
    }
    strcpy(errortext, "no tasks to list\n");
    return 1;
}

int progress_task(task *task_list, int *next_ID, char *operand, char *errortext)
{
    int task_to_modify = strtol(operand, errortext, 10);

    int task_exist = 0;
    int i = 0;

    for (i ; i < *next_ID; i++) {
        if (task_list[i].ID == task_to_modify) {
            task_exist = 1;
            task_list[i].progress = 100;
            break;
        }
    }

    if (!task_exist) {
        strcpy(errortext, "no such task\n");
        return 1;
    }

    return 0;

}

prior_task(task *task_list, int *next_ID, char *operand, char *errortext)
{
    char *buffer1;
    char buffer2[10] = {'\0'};
    int priority = 0;
    int task_exist = 0;
    int i = 0;
    int task_to_modify = -1;

    buffer1 = strtok(operand, " ");

    strcpy(buffer2, operand + strlen(buffer1) + 1);

    task_to_modify = strtol(buffer1, errortext, 10);

    priority = strtol(buffer2, errortext, 10);



    for (i ; i < *next_ID; i++) {
        if (task_list[i].ID == task_to_modify) {
            task_exist = 1;
            task_list[i].prior = priority;// ***
            break;
        }
    }

    if (!task_exist) {
        strcpy(errortext, "no such task\n");
        return 1;
    }

    return 0;
}



