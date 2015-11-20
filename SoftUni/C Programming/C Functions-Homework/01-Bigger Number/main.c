/* 
 Write a program that reads 2 integers from the console 
 and prints the largest of them using the function get_max().
 Declare a function prototype before defining the function.
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *, int *);
int get_max(int , int);

int main()
{
    int x, y;

    printf("Enter 2 numbers: ");
    checkIntInput(&x, &y);

    int largest;
    largest = get_max(x, y);
    
    printf("Largest: %d", largest);

    return (EXIT_SUCCESS);
}

void checkIntInput(int *a, int *b)
{
    if ((scanf("%d %d", a, b)) != 2)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

int get_max(int a, int b)
{
    int bigger = (a > b) ? a : b;
    return bigger;
}