/* 
 Write a program that enters from the console a positive integer n and prints 
 all the numbers from 1 to n, on a single line, separated by a space.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number;
    
    printf("Enter number: ");
    if ((scanf("%du", &number)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
    else
    {
        int ctr = 1;
        while (ctr <= number)
        {
            printf("%d ", ctr);
            ctr++;
        }
    }

    return (EXIT_SUCCESS);
}

