/* 
 Write a program that, for a given two integer numbers n and x, calculates 
 the sum S = 1 + 1!/x + 2!/x 2 + ... + n!/x n .Use only one loop. Print 
 the result with 5 digits after the decimal point.
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *, int *);

int main()
{
    int n, x;
    double sum = 1, numerator = 1, denumerator = 1;

    printf("Enter n and x: ");
    checkIntInput(&n, &x);
    if (x == 0)
    {
        printf("x must be > from 0!");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 1; i <= n; i++)
    {
        numerator *= i;
        denumerator *= x;
        sum += numerator / denumerator;
    }
    
    printf("result: %.5lf", sum);

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