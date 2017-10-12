#include <stdio.h>

void delete_pos(int to_be_deleted);

int arr[50];
int size_arr = 0;
int to_be_deleted = 0;

int main()
{
    // TODO: write a program wich asks for a number, that will be the real size of the array (50 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
	// print out the array
    // Then ask for a number, that will be the position, where you want the element to be deleted
    // handle the problem when trying to delete from invalid positions (e.g. negative number)
    // print out the the array after the deleting

    do {
        printf("Pls insert the limit of the array (1..50):\n");
        scanf("%d", &size_arr);
    } while(size_arr > 51 || size_arr < 0);

    printf("\nLet us populate the array:\n");

    for (int i = 0; i < size_arr; i++){
        printf("Pls insert the %d. value of the array (1..50):\n", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nYour array:\n");

        for (int i = 0; i < size_arr; i++){
        printf("%d\n", arr[i]);
    }

    printf("\nGive me a position where you want a value to be deleted:\n");
    scanf("%d", &to_be_deleted);

    delete_pos(to_be_deleted);

    printf("\nYour array:\n");

    for (int i = 0; i < size_arr; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}

void delete_pos(int to_be_deleted){
    for (int i = to_be_deleted; i < size_arr - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[size_arr - 1] = 0;
    size_arr--;
}
