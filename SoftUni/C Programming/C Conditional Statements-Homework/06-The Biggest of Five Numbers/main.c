/* 
 Write a program that finds the biggest of five numbers by using only five 
 if statements.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double first, second, third, fourth, fift;

    printf("Enter 5 numbers: ");
    if ((scanf("%lf %lf %lf %lf %lf", &first, &second, &third, &fourth, &fift)) != 5)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }

    if (first > second && first > third && first > fourth && first > fift)
    {
        printf("Biggest: %.1lf", first);
    }
    else if (second > first && second > third && second > fourth && second > fift)
    {
        printf("Biggest: %.1lf", second);
    }
    else if (third > first && third > second && third > fourth && third > fift)
    {
        printf("Biggest: %.1lf", third);
    }
    else if (fourth > first && fourth > second && fourth > third && fourth > fift)
    {
        printf("Biggest: %.1lf", fourth);
    }
    else
    {
        printf("Biggest: %.1lf", fift);
    }


    return (EXIT_SUCCESS);
}