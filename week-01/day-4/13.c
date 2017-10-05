#include <stdio.h>

/*
create a program which converts the fahrenheit to celsius
the output should look like this:
Fahrenheit       Celsius
  0               -17.8
 20                -6.7
 40                 4.4
 60                15.6
...
print out at least 10 lines
*/

int main() {

    float m = 0.5557;
    float a = -17.8;
    printf("Fahrenheit\t\tCelsius\n");

    for(int i = 0; i <210; i += 20)
    {
        printf("%d\t\t\t%.1f\n",i,i*m+a);
    }

	return 0;
}
