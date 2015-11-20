/* 
 Write a program that prints the n-th digit of a number (from right to left). 
 If no such digit exists, print a dash "-".
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *, int *);

int main()
{
    int number, n, nTHDigit = 0;

    printf("Enter number and digit: ");
    checkInput(&number, &n);

    int i = n - 1;
    nTHDigit = number;
    while (i > 0)
    {
        nTHDigit /= 10.0;
        --i;
    }
    nTHDigit %= 10;

    if (nTHDigit)
    {
        printf("%d", nTHDigit);
    }
    else
    {
        printf("-");
    }

    return (EXIT_SUCCESS);
}

void checkInput(int *a, int *b)
{
    if ((scanf("%d%d", a, b)) != 2)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}