#include <stdio.h>
#include <stdlib.h>

//writing ABC with loop like this : aAbBcC...zZ

int main()
{
    //the characters will be displayed according to their ascii number (lower case 'a' starts at 97..)
    for (int i = 97 ; i <= 122 ; i++){
        printf("%c",i);
        printf("%c",i-32);
    }

	return 0;
}
