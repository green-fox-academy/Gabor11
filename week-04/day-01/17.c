#include <stdio.h>
#define MAX_CHARS 255 // Maximum characters allowed

char most_frequent_char (char *str, int *num_of_occ);
char *remove_char(char* input, char char_to_remove);
int is_processed(int input[256][2], char char_to_check);

int main()
{
    //TODO: write a function which finds the maximum occurrence of a character in a given string.
    //return with the most frequent character
    //the number of occurrence should be an output parameter
    int num_of_occ = 0;

    char str[] = "e is the most frequent element.";
    most_frequent_char (str, &num_of_occ);

    return 0;
}

char most_frequent_char (char *str, int *num_of_occ)
{
    int len = strlen(str);
    int temp[256][2] = {'\0'};
    char *tmp;

    for (int i, j = 0; i < len; i++) {
        if (is_processed(temp, str[i])) {
            continue;
        } else {
            tmp = remove_char(str, str[i]);
            temp[j][0] = str[i];
            temp[j][1] = len - strlen(tmp);
            j++;
        }
    }
    for (int i = 0; i < 50; i++) {
        printf("%c\t%d\n", temp[i][0], temp[i][1]);
    }


}

char *remove_char(char* input, char char_to_remove)
{
    int i, j;
    i = j = 0;
    char *output = input;
    for (i, j ; i < strlen(input) ; i++, j++)
    {
        if (input[i] != char_to_remove)
            output[j] = input[i];
        else
            j--;
    }
    output[j] = '\0';
    return output;
}

int is_processed(int input[256][2], char char_to_check)
{
    for (int i = 0; i < _2d_int_arr_len(input); i++) {
        if (input[i][0] == char_to_check)
            return 1;
    }
    return 0;
}

int _2d_int_arr_len(int array[256][2])
{
    int i = 0;
    while (array[i][0] != NULL) {
        i++;
    }
    return i;
}
