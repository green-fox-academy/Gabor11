#include <stdio.h>
#include <string.h>

int main()
{
    char palindrome[256];
    printf("Pls give me a line of text:\n");
    scanf("%s", &palindrome);
    printf("%s", palindrome);
    printf("%s\n", strrev(palindrome));
    return 0;
}
