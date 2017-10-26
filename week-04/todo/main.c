#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include "storage.h"

int main()
{
    char input[256];
    char errortext[256];
    task task_list[10] = {'\0'};
    static int next_ID = 0;
    defining_commands();

    printf("TODO APP\n");

    if (add_task(task_list, &next_ID, "something to do", errortext) != 0)
        puts(errortext);


/*  gets(input);

    process(input);
*/


    return 0;
}
