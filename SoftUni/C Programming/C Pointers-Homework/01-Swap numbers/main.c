/* 
 Implement a function which takes as input two numbers and swaps their values. 
 The declaration of the function should be something like:
 void swap(int *first, int *second)
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second);

int main()
{
    int a = 5, b = 7;
    
    printf("Before exchange a = %d b = %d\n", a, b);
    
    swap(&a, &b);
    
    printf("after exchange a = %d b = %d", a, b);

    return (EXIT_SUCCESS);
}

void swap(int *first, int *second)
{
    int oldValue;
    
    oldValue = *first;
    *first = *second;
    *second = oldValue;
}