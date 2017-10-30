#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Create a function that takes two arrays of characters and a number.
 * It should replace the contents of the first array from the given index
 * with the contents of the second array.
 * The function should return a number which tells whether it was successful:
 *    * If all is right it should return 0.
 *    * If the index is out of bounds it should return -1.
 *    * If the inserted content would be longer than the receiving array it should return 1 and leave the array as it is.
 * IMPORTANT: Think about what kind of arguments You need to make this happen and craft the function accordingly.
 *
 * Write code in the main function to test all scenarios and write out the result You need to check whether this works.
 */

 int main()
 {
    char string1[256];
    char string2[50];

    strcpy(string1, "if you put hard work and commitment and a little piece of talent together..");
    strcpy(string2, "you can achieve things..");
    puts(string1);
    puts(string2);
    write_in(string1, string2, 15);
    puts(string1);

    return 0;
 }

 int write_in(char *string1, char *string2, int pos){
    if (pos > 255) {
         return -1;
    } else if(pos + strlen(string2) < 255) {
        int i, j = 0;
        for (i = pos, j = 0; i < pos + strlen(string2); i++, j++) {

            string1[i] = string2[j];
        }
        return 0;
    } else {
        return 1;
    }
 }
