/* 
 Write a program that finds the biggest of three numbers.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double first, second, third;

    printf("Enter 3 numbers: ");
    if ((scanf("%lf %lf %lf", &first, &second, &third)) != 3)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }

    if (first > second && first > third)
    {
        printf("Biggest: %.1lf", first);
    }
    else if (second > first && second > third)
    {
        printf("Biggest: %.1lf", second);
    }
    else
    {
        printf("Biggest: %.1lf", third);
    }

    return (EXIT_SUCCESS);
}