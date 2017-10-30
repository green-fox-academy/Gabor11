#include <stdio.h>

/*
 * Create a function that takes an array of array of characters and returns an array of integers each representing the
 * lenght of the given character array in the first array.
 * Say your input is this: {"Good", "Morning", "Vietnam"}
 * Your output should be this: {4, 7, 7}.
 * HINT: strings are terminated with a special character: '\0'.
 * So, "Good" as an array of characters would look like this: {'G', 'o', 'o', 'd', '\0'}.
 *
 * In the main function create code that demonstrates that Your function works approrpiately.
 */
int *word_len_count(char** words, int size);

int main()
{
    char *words[7] = {"google", "perfect", "size", "everything", "almost", "thinking", "meaningful"};

    int *result = word_len_count(words, 7);

    for (int i = 0; i < 7; i++) {
        printf("%d\n", result[i]);
    }

}

int *word_len_count(char** words, int size)
{
    //array has to be static so that the function is able to return with its pointer!!
    static int result[200] = {'\0'};
    int *ptr = result;

    for (int i = 0; i < size; i++) {
        *ptr = strlen(words[i]);
        ++ptr;
    }

    return result;
}
