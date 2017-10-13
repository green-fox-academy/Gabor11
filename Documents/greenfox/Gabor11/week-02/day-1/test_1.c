#include <stdio.h>
#include <stdint.h>
#define MYNAME "Gabi"
#define MYAGE 27
#define true 1
#define false 0

void start_screen();
int addition(int num1, int num2);
int multiply(int num3);
int is_bigger_than_10(int num4);
void use_static_var();


int main(){
    /*
    int main_variable = 15;
    start_screen();
    printf("%d\n",multiply(addition(7,3)));

    if(is_bigger_than10(8)){
        printf("your input was bigger than 10.");
    } else {
        printf("your input was smaller than or equal to 10.");
    }


    use_static_var();
    use_static_var();
    use_static_var();
    use_static_var();
    use_static_var();
    */
    if(true)
        printf("This looks like boolean");

    while(true)
    {
        printf("hoolaa hw!\n");

    }

    return 0;
}

void start_screen(){

    printf("Hello user!\n");
    printf("This is a program!\n");
    printf("have fun!\n");

}

int addition(int num1, int num2){

    return num1 + num2;
}

int multiply (int num3){

    return num3 * 5;
}

int is_bigger_than_10(int num4){
    if (num4 <= 10)
        return 0;
    else
        return 1;
}

void use_static_var(){

    int a = 10;
    static sa = 20;

    a += 5;
    sa += 5;

    printf("a is %d\n", a);
    printf("sa is %d\n", sa);
}
