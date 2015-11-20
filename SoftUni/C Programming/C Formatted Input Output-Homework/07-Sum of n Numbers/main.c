/* 
 Write a program that enters a number n and after that enters more n
numbers and calculates and prints their sum.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(double *);

int main()
{
    double n, sum = 0;
    
    printf("Enter number: ");
    checkInput(&n);
    
    int i;
    for (i = 0; i < n; i++)
    {
        double number; 
        
        checkInput(&number);
        sum += number;
    }
    
    printf("%.1lf", sum);

    return (EXIT_SUCCESS);
}

void checkInput(double *N)
{
    if ((scanf("%lf", N)) != 1)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}