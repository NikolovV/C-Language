/* 
 Declare the following functions in a header file(.h). 
 Implement them in a separate .c file.Include the .h file in your main program
 and demonstrate the written functions.
 * arr_min()-returns the smallest element in the array
 * arr_max()-returns the largest element in the array
 * arr_clear()-sets all array elements to 0
 * arr_average()-returns the average of all elements 
 * arr_sum()-returns the sum of all array elements
 * arr_contains()-returns whether the array contains the specified element
 * arr_merge()-receives two arrays, merges them into one and returns  
 * a pointer to the resulting array.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayManipulation.h"
#include <string.h>

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5};
    int arr_2[] = {6, 7, 8};
    int lenght_1 = LENGHT_ARRAY(arr_1);
    int lenght_2 = LENGHT_ARRAY(arr_2);

    int min = get_min(arr_1, lenght_1);
    printf("min = %d\n", min);
    int min_2 = get_min(arr_2, lenght_2);
    printf("min_2 = %d\n", min_2);

    int max = get_max(arr_1, lenght_1);
    printf("max = %d\n", max);
    int max_2 = get_max(arr_2, lenght_2);
    printf("max_2 = %d\n", max_2);

    double average = get_avg(arr_1, lenght_1);
    printf("average = %f\n", average);
    double average_2 = get_avg(arr_2, lenght_2);
    printf("average_2 = %f\n", average_2);

    int sum = get_sum(arr_1, lenght_1);
    printf("sum = %d\n", sum);
    int sum_2 = get_sum(arr_2, lenght_2);
    printf("sum_2 = %d\n", sum_2);

    bool isContain = arr_contains(arr_1, lenght_1, 5);
    printf("isContain 5 = %d\n", isContain);
    bool isContain_2 = arr_contains(arr_2, lenght_2, 5);
    printf("isContain_2 5 = %d\n", isContain_2);
    
    int *arrMerge;
    arrMerge = arr_merge(arr_1, arr_2, lenght_1, lenght_2);
    int i;
    printf("Merged: ");
    for (i = 0; i < (lenght_1 + lenght_2); i++)
    {
        printf("%d ", arrMerge[i]);
    }
    printf("\n");
    
    free(arrMerge);
    
    printf("Clearing... \n");
    arr_clear(arr_1, lenght_1);
    for (i = 0; i < lenght_1; i++)
    {
        printf("%d ", arr_1[i]);
    }
    printf("\n");
        
    arr_clear(arr_2, lenght_2);
    for (i = 0; i < lenght_2; i++)
    {
        printf("%d ", arr_2[i]);
    }
    
    
    return (EXIT_SUCCESS);
}