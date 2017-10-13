#include <stdio.h>
#include <string.h>
#include <stdint.h>

int8_t palindrom_search(char* string, char* tar);
int8_t compare(char* string, int8_t i, int8_t h, int8_t j);
int8_t ins_to_tar(char* tar, char* string, int8_t i, int8_t h);

int main()
{
    char string[256] = {'/0'}; // string variable for user input
    char target[256] = {'['}; // here will be the output data collected
    char buff[256] = {'/0'};

    //inserting data
    printf("Pls insert a line of text: \n");
    gets(string);

    //printf("%d",compare(string, 0, 3, 0));
    // ins_to_tar(target, "habakukk", 0, 8);

    printf("%d palindromes found.\n",palindrom_search(string, target));
    printf("%s\n", target);

    return 0;
}

int8_t palindrom_search(char* string, char* tar)
{
    int8_t len = strlen(string);
    int8_t count = 0;
    int8_t hit_count = 0;

    for (int8_t h = 3; h <= len; h++) {
        for (int8_t i = 0; i < len; i++) {
            for (int8_t j = 0; j < h / 2; j++) {
                if (compare(string, i, h, j))
                    count++;
            }
            if (count == h / 2) {
                ins_to_tar(tar, string, i, h);
                hit_count++;
            }
            count = 0;
        }
    }
    tar[strlen(tar)-1] = '\0';
    tar[strlen(tar)-1] = ']';

    return hit_count;
}



int8_t compare(char* string, int8_t i, int8_t h, int8_t j)
{
    return string[i + j] == string[i + h - 1 - j];
}

int8_t ins_to_tar(char* tar, char* string, int8_t i, int8_t h)
{
    strcat(tar, "\"");
    strncat(tar, &string[i], h);
    strcat(tar, "\", ");
}
