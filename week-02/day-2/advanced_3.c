#include <stdio.h>
#define true 1
#define false 0

int main()
{
    int arr[20];
    int freq[20];
    int limit = 0;
    int unique = true;


    // TODO: write a program wich asks for a number, that will be the real size of the array (20 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
    // Finally print all unique elements in array

    do{
        printf("Pls insert the limit of the array(1...20):\n");
        scanf("%d", &limit);
    }while (limit < 1 || limit > 20);

    for (int i = 0; i < limit; i++){
        printf("insert the %d. value of the array:\n", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The unique values of your array:\n");

    for (int i = 0; i < limit; i++){
        freq[i] = arr[i];
        for (int j = 0; j < i; j++){
            if (arr[i] == freq[j]){
                unique = false;
                break;
            }
        }
        if (unique)
        printf("%d\n", arr[i]);
        unique = true;
    }


    return 0;
}
