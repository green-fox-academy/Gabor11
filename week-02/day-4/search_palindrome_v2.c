#include <stdio.h>
#include <string.h>
#include <stdint.h>

int palindrom_search(char* string);

int main()
{
    char string[256]; // string variable for user input

    //inserting data
    printf("Pls insert a line of text: \n");
    gets(string);

    if(palindrom_search(string))
        printf("Palindrom search ended.");

    return 0;
}

int palindrom_search(char* string)
{
    char target[256] = {'['};
    char compare[256] = {'\0'};
    int len = strlen(string);
    int count = 0;

    // loop for the size of the words
    for (int h = 3; h <= len / 2; h++) {
        printf("loop1, h: %d\n", h);
        // loop for iterating till the end of the initial string.
        // 'i' is the start of the actually investigated "word"
        for (int i = 0; i < len - h + 1; i++) {
            printf("loop2, i: %d\n", i);
            // loop for filling up the 'compare' array with the actually investigated "word"
            // in order to compare it with other parts of the string in the next loop
            for (int j = 0; j < h; j++) {
                compare[j] = string[i + j];
                printf("loop3, j: %d\n", j);
            }
            // loop for iterating backwards while comparing the parts of the string with the 'compare'
            // 'k' means the start of the actually compared "word"
            for (int k = len; k > i + h; k--) {
                printf("loop4, k: %d\n", k);
                // counting the identical characters
                for (int l = 0; l < h; l++) {
                    printf("loop5, l: %d\n", l);
                    if (compare[l] == string [k - l])
                        count++;
                    else
                        break;
                }
                if (count == h) {
                    strcat(target, "\"");
                    for (int m = 0; m < h; m++) {
                        printf("loop6, m: %d\n", m);
                        strcat(target, string[i + m]);
                    }
                    strcat(target, "\", ");

                }
                count = 0;
            }
        }
    }
    for (int n = 1; n < 256; n++) {
        printf("loop7, n: %d\n", n);
        if (target[n] == '\0') {
            target[n - 1] = '\0';
            target[n - 0] = ']';
        }
    }
    puts(target);

    return 1;
}
