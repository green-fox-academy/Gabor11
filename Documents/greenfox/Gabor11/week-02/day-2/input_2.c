#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input
    int i = 0;
    char c = 0;
    //TODO:
    // Get the user's name with gets

    printf("Insert your name: \n");
    gets(buffer);

    //TODO:
    // Print it out with puts

    puts(buffer);

    //TODO:
    // Get the user's pet name with getch

    //clear the buffer
    for(int i = 0; i < 256; i++){
        buffer[i] = '\0';
    }

    printf("Insert your pet's name: ");


    c = getch();
    while(c != 13){

        buffer[i] = c;
        i++;
        c = getch();
    }

    //TODO:
    // Print it out

    printf("\n%s ", buffer);
    return 0;
}
