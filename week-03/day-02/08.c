#include <stdio.h>
#include <stdlib.h>

void transform (char str[], int original_base, int new_base);

//TODO: write a program, which transforms a number from a number system to another.
//use the stdlib.h functions, and take care of error handling (see the reference)
//the transform() function should print out the result.

void transform(char* str, int original_base, int new_base);

int main()
{
    char str[20];
    int original_base;
    int new_base;
    while (1) {
        printf("Give me a number to transform it in an other system: ");
        scanf("%s", str);
        printf("Give me the original base: ");
        scanf("%d", &original_base);
        if(original_base > 36 || original_base < 1) {
            printf("Unfortunately number system transitions\nare only provided till base of 36 by this program.\n");
            continue;
        }
        printf("Give me the number of the new base: ");
        scanf("%d", &new_base);
        if(new_base > 36 || new_base < 1) {
            printf("Unfortunately number system transitions\nare only provided till base of 36 by this program.\n");
            continue;
        }
        break;
    }
    transform(str, original_base, new_base);
    return(0);
}

void transform(char* str, int original_base, int new_base)
{
    char *ptr;
    int ret = 0;
    char buffer[20] = {0};

    ret = strtol(str, &ptr, original_base);

    itoa(ret, buffer, new_base);
    printf("The number %s (%d) is:\n", str, original_base);
    printf("%s (%d)\n", buffer, new_base);
}

