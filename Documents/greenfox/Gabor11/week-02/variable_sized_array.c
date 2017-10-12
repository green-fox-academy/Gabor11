#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, sum = 0;
    char *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    ptr = (char*) malloc(num * sizeof(char));  //memory allocated using malloc
    if(ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements of array: ");
    for(i = 0; i < num; ++i)
    {
        getch(*(ptr + i));
    }


    printf("%s", *ptr);
    free(ptr);
    return 0;
}
