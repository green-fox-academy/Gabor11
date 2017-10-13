#include <string.h>
#include <stdio.h>

char* to_be_printed = "It prints. Really.";

void printer(char* str){

for (int i = 0 ; i < strlen(str) ; i++){
    printf("%c", str[i]);

}
}
