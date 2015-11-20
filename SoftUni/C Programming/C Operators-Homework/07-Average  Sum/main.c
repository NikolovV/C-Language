/* 
 Write a program that finds the average of the sum of 3 numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void checkInput(double *, double *, double *);

int main()
{
    double num_1, num_2, num_3;
    double averageSum;
    
    printf("Enter 3 numbers: ");
    checkInput(&num_1, &num_2, &num_3);
    
    averageSum = (num_1 + num_2 + num_3)/3;
    
    printf("Average is %.5lf", averageSum);    

    return (EXIT_SUCCESS);
}

void checkInput(double *A, double *B, double *C)
{
    if ((scanf("%lf %lf %lf", A, B, C)) != 3)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}