#include <stdio.h>

/*
 * Create a structure to represent a list of numbers. The structure should know how many number it has stored.
 * Store the numbers in an array.
 * Create functions to:
 *    * Add a new number at the end.
 *    * Get a number at a given index.
 *    * Replace a number at a given index if it exists.
 *
 * If the array is too small, create a new one, copy everything into it, add the new element and delete the old array.
 *
 * Test in the main function whether everything works.
 */

 typedef struct {
    int n;
    int size;
    int *num_array;
 } num_list;

 int main()
 {


 }

 num_list* initialize_list(int size)
 {
     static int sizer = 0;

     num_list *ptr_num_list;



     ptr_num_list = (num_list *) malloc ((2 + sizer) * sizeof(int));

     return ptr_num_list;

 }
