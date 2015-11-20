/* 
 Write a program that reads 3real numbers from the console and prints their sum.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num_1;
    float num_2;
    float num_3;

    printf("Enter three real number: ");

    if ((scanf("%f %f %f", &num_1, &num_2, &num_3)) != 3)
    {
        fprintf(stderr, "Wrong value!");
        exit(1);
    }
    else
    {
        double sum = num_1 + num_2 + num_3;
        printf("Sum of the number is %.2f", sum);
    }

    return (EXIT_SUCCESS);
}