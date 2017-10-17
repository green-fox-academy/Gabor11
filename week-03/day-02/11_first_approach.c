#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int convert(char* com);

int main()
{
	char command[256];
	int switcher = 0;
    char logged_in = 0;
    char registered = 0;
    char exit = 0;



    //TODO: write a register-login-logout program
    //if you type in register print out "Registration..." or "You are already registered." if you are registered.
	//you are able to log in, if you are already registered, otherwise not. In that case print out "You are not registered.".
    //if you type in login print out "Logging in..." or "Already logged in." if are logged in.
    //if you type in logout print out "Logging out..." or "Already logged out." if are logged out.

    printf("Welcome to fast&curious. What would you like to do?\n");

    while (exit != 1) {
        printf("(type in: register, login, logout, exit)\n");
        scanf("%s", &command);
        switcher = convert(command);

        switch (switcher) {
        case 869 :
            if (registered == 0) {
                printf("Registration..\n");
                registered = 1;
            } else {
                printf("You are already registered..\n");}
            break;
        case 537 :
            if (registered == 0) {
                printf("You are not registered..\n");
            } else if (logged_in == 0) {
                printf("Logging in..\n");
                logged_in = 1;
            } else {
                printf("You are already logged in..\n");}
            break;
        case 666 :
            if (registered == 0) {
                printf("You are not registered..\n");
            } else if (logged_in == 1) {
                printf("Logging out..\n");
                logged_in = 0;
            } else {
                printf("You are already logged out..\n");}
            break;
        case 442 :
            printf("Exit the program..\n");
            exit = 1;
            break;
        default :
            printf("Wrong input..\n");
            break;

        }
    }

}

int convert(char* com)
{
    int add;
    for (int i = 0; i < strlen(com); i++) {
        add += com[i];
    }
    return add;
}
