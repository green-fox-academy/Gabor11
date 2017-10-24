#include <stdio.h>
#include <string.h>

void reverse_name(char *name, char *reversed_name);

int main(void)
{
	char name[] = "Gipsz Jakab";

    char reversed[50];

    //write a function which reverse a name's last name and first name. Use a void function. Put your 'return' value in the second parameter.

    reverse_name(name, reversed);

    printf("%s", reversed);
}

void reverse_name(char *name, char *reversed_name)
{
    int len = strlen(name);
    char temp[50] = {'\0'};

    for (int i = 0; i < len; i++) {
        if (name[i] == ' ') {
            for (int j = i; j < len; j++) {
                reversed_name[j - i] = name[j];
            }
            strcat(reversed_name, " ");
        } else {
        temp[i] = name [i];
        }


    }
    strcat(reversed_name, temp);

}
