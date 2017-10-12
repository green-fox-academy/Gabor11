#include <stdio.h>
#include <string.h>
#include <stdint.h>

int palindrom_search(char* string);

int main()
{
    char string[256]; // string variable for user input
    int head = 0;



    //inserting data
    printf("Pls insert a line of text: \n");
    gets(string);


    printf("%s\n", string);
    puts(string);



    return 0;
}

int palindrom_search(char* string)
{
    char target[256];
    char compare[256];
    int len = strlen(string);
    int count = 0;

    // loop for the size of the words
    for (int h = 3; h < len / 2; h++) {
        // loop for iterating till the end of the initial string.
        // 'i' is the start of the actually investigated "word"
        for (int i = 0; i < len - h + 1; i++) {
            // loop for filling up the target array
            // in order to compare it with other parts of the string in the next loop
            for (int j = 0; j < h; j++) {
                compare[j] = string[i + j];
            }
            // loop for iterating backwards while comparing the parts of the string with the target
            for (int k = len; k > i + h; k--) {
                // counting the identical characters
                for (int l = 0; l < h; l++) {
                    if (compare[l] == string [k - l])
                        count++;
                    else
                        break;
                }
                if (count == h) {

                }

            }

        }
    }

}
