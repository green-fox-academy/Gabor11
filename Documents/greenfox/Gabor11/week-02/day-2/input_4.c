#include <stdio.h>
#include <string.h>

void func();

int main()
{
    //write a void function which asks for a number with scanf and print it out with printf, then asks for a name with gets, and print it out with puts
    //you will notice something is wrong
    //try to solve the problem

    func();

    return 0;
}

void func(){
    int num = 0;
    char name[50];
    printf("Pls insert a number:\n");
    scanf("%d", &num);
    printf("%d\n", num);
    printf("Enter your name: \n");
    getchar();
    gets(name); //reads string from user
    printf("Your name is: \n");
    puts(name);  //displays string
    getch();
}
