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

int process(task *task_list, char *input,int *next_ID, char *errortext)
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
        printf("%c", 'a' + switcher);
        break;
    case 2:
        printf("%c", 'a' + switcher);
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
        printf("%c", 'a' + switcher);
        break;
    case 7:
        printf("%c", 'a' + switcher);
        break;
    case 8:
        printf("%c", 'a' + switcher);
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
            printf("%d.\t[%d\%]\t%s\t-%d\n", task_list[i].ID, task_list[i].progress, task_list[i].name, 1);
        }
        return 0;
    }
    strcpy(errortext, "no tasks to list\n");
    return 1;
}
