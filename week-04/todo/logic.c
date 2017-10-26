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

int process(task task_list[], char *input,int *next_ID, char *errortext)
{
    int switcher = -1;

    char command[MAX_COMMAND_LENGTH];
    char operand[strlen(input) - MAX_COMMAND_LENGTH];

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
        add_task(task_list, next_ID, operand, errortext);
        break;
    case 1:
        printf("%c", 'a' + switcher);
        break;
    case 2:
        printf("%c", 'a' + switcher);
        break;
    case 3:
        printf("%c", 'a' + switcher);
        break;
    case 4:
        printf("%c", 'a' + switcher);
        break;
    case 5:
        printf("%c", 'a' + switcher);
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
        printf("%s\n", errortext);

        break;
    }

}

void substring(char s[], char *sub, int p, int l) {
   int c = 0;

   while (c < l) {
      sub[c] = s[p+c];
      c++;
   }
   sub[c] = '\0';
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
