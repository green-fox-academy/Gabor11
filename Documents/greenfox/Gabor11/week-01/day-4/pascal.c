#include <stdio.h>
int main()

/*
create a program which draws a diamond, like this:
      *
    * * *
  * * * * *
* * * * * * *
* * * * * * *
  * * * * *
    * * *
      *
*/

{
    //lazy diamond :)
    printf("      *\n    * * *\n  * * * * *\n* * * * * * *\n* * * * * * *\n  * * * * *\n    * * *\n      *\n");


    printf("\n\n");


    //let us do it in the hard way
    int count = 6;

    for (int i = 0; i < 8; i++)
    {

            for (int k = 0; k < count; k++) //printing the spaces
            {
                printf(" ");
            }

            for (int l = 0; l <8%(count+1); l++)
            {
                printf("* ");
            }


            switch (i)
            {
            case 0:
            case 1:
            case 2:
                count -= 2;
                break;
            case 5:
            case 6:
            case 7:
                count += 2;
                break;
            default:
                break;
            }

        printf("\n");

    }


    return 0;
}
