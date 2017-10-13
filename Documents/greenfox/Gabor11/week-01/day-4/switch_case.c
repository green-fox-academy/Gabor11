#include <stdio.h>
#include <stdlib.h>

int main()
{
    char grade = 'A';

    switch (grade) {
        case 'A' :
            printf("This is good.");
            break;
        case 'B' :
            printf("This is still good.");
            break;
        case 'C' :
            printf("The grass is green and the grasshopper jumps.");
            break;
        case 'D' :
            printf("Something happens.");
            break;
        default  :
            printf("\a");


    }

}
