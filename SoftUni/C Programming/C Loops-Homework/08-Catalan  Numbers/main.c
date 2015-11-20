/* 
 Write a program to calculate the nth Catalan number by given n(1 < n < 100).
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *);

int main()
{
    int n;
    unsigned long long faktorialN = 1, twoFactorial = 1, nPlusOneFactorial = 1;
    unsigned long long catalan = 1;

    printf("Enter numbers: ");
    checkIntInput(&n);

    if (n >= 0)
    {
        int i, k;

        for (i = n, k = 2 * n; i >= 1; i--, k--)
        {
            faktorialN *= i;
            nPlusOneFactorial = (n + 1) * i;
            twoFactorial *= k;
        }

        catalan = twoFactorial / (nPlusOneFactorial * faktorialN);

        printf("catalanta = %llu", catalan);
    }
    else
    {
        printf("n must be in range (1 < n < 100)");
    }

    return (EXIT_SUCCESS);
}

void checkIntInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}