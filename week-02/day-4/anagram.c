#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define false 0
#define true 1

int anagram();

int main()
{
    char* input1 = "valami";
    char* input2 = "imaval";

    printf("%s\n",input1);
    printf("%s\n",input2);


    if (anagram(input1, input2))
        printf("This is an anagram.");
    else
        printf("This is NOT an anagram.");

    return 0;
}

int anagram(char* input1, char* input2)
{
    int size = 0;
    int i = 0;
    int check = 0;

    // checking the sizes of the two inputs and setting the 'size' variable if they are equal
    if (strlen(input1) != strlen(input2)){
        printf("different size\n");
        return false;
    } else {
        size = sizeof(input1)/sizeof(char);
    }

    //filling up the 'checker' array with zeros
    int8_t checker[100] = {0};

    for (int i = 0; i < size; i++){
        printf("%d\n", checker[i]);
    }
    printf("-----------------\n");
    printf("size is: %d\n", size);

    while (i < size){
        for (int j = 0; j < size; j++){
            if (checker[j] == true){
                j++;
                if (j == size){
                    i = size;
                    break;
                }
            } else if (input1[i] == input2[j]){
                checker[j] = true;
            }
            printf("j: %d\n", j);
        }
        printf("i: %d\n", i);
        i++;
    }

    //checking whether all the elements of 'checker' are set to true..
    for (int k = 0; k < size; k++){
        check += checker[k];
    }

    if (check == size)
        return true;
    else
        printf("i is: %d",i);
        return false;
}
