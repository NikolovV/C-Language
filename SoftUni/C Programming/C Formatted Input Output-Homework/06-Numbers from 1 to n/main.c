/* 
 Write a program that reads an integer number n from the console and prints all 
 the numbers in the interval [1..n], each on a single line.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);

int main()
{
    int n;
    
    checkInput(&n);
    
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }

    return (EXIT_SUCCESS);
}

void checkInput(int *N)
{
    printf("Enter number: ");

    if ((scanf("%d", N)) != 1)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}