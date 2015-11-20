/* 
 Write a program that reads from the console a positive integer 
 number n (1 ≤n≤ 20) and prints a matrix
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *);

int main()
{
    int n;

    printf("Enter numbers: ");
    checkIntInput(&n);

    int rows, cols;
    for (rows = 0; rows < n; rows++)
    {
        for (cols = rows + 1; cols <= (rows + n); cols++)
        {
            printf("%d ", cols);
        }
        printf("\n");
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