/* 
 Write a program that calculates the greatest common divisor
 (GCD) of given two integers a and b. Use the Euclidean algorithm
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *, int *);
int gcd_algorithm(int, int);

int main()
{
    int a, b, gcd;

    printf("Enter two numbers:");
    checkIntInput(&a, &b);

    gcd = gcd_algorithm(a, b);

    if (gcd)
    {
        printf("\nThe GCD of %d and %d is %d\n", a, b, gcd);
    }
    else
    {
        printf("\nInvalid input!!!\n");
    }
    
    return (EXIT_SUCCESS);
}

void checkIntInput(int *x, int *y)
{
    if ((scanf("%d %d", x, y)) != 2)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

int gcd_algorithm(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else if (x >= y && y > 0)
    {
        return gcd_algorithm(y, (x % y));
    }
}