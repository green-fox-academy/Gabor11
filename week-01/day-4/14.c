#include <stdio.h>

/*
modify the previous program to print the table reverse order
for example:
Fahrenheit       Celsius
300               148.9
280               137.8
260               126.7
240               115.6
...
print out at least 10 lines
*/

int main() {

    float m = 0.5557;
    float a = -17.8;
    printf("Fahrenheit\t\tCelsius\n");

    for(int i = 200; i >= 0; i -= 20)
    {
        printf("%d\t\t\t%.1f\n",i,i*m+a);
    }

	return 0;
}
