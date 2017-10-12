#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define false 0
#define true 1

int anagram();

int main()
{
    char* input1 = "valami";
    char* input2 = "lvamai";

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
    int j = 0;
    int check = 0;
    //filling up the 'checker' array with zeros, the program will only able to deal with words under 100
    int8_t checker[100] = {0};

    // checking the sizes of the two inputs and setting the 'size' variable if they are equal
    if (strlen(input1) != strlen(input2)) {
        printf("different size.\n");
        return false;
    } else {
        size = strlen(input1);
    }
    // these nested loops search for identical characters
    while (i < size) {
        j = 0;
        while (j < size) {
            // this check is to jump over the elements that have been already found
            while (checker[j] == true) {
                j++;
                // if we reach the size that means we have too many of the character stored actually in 'input1[i]'
                if (j == size){
                    i = size;
                    break;
                }
            }
            if (j < size && input1[i] == input2[j]) {
                checker[j] = true;
                break;
            }
            j++;
        }
        i++;
    }
    //checking whether all the elements of 'checker' are set to true..
    for (int k = 0; k < size; k++) {
        check += checker[k];
    }
    if (check == size)
        return true;
    else
        printf("not all characters are identical.\n");
        return false;
}
