/* 
 Write a program that reads two positive integer numbers and prints how many numbers 
 p exist between them such that the reminder of the division by 5 is 0.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *, int *);
void devideByFive(int, int);

int main()
{
    unsigned int lowNumber, highNumber;

    printf("Enter two positive integer numbers: ");
    checkInput(&lowNumber, &highNumber);

    devideByFive(lowNumber, highNumber);

    return (EXIT_SUCCESS);
}

void checkInput(int *A, int *B)
{
    if ((scanf("%u %u", A, B)) != 2)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

void devideByFive(int A, int B)
{
    unsigned int i, remainder, p = 0;

    for (i = A; i <= B; i++)
    {
        if ((remainder = i % 5) == 0)
        {
            printf("%u", i);
            ++p;
            if (i <= B - 5)
            {
                printf(", ");
            }
        }
    }
    printf("\nThere is only %u numbers.", p);
}