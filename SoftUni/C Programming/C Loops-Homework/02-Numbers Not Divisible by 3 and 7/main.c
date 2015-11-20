/* 
 Write a program that enters from the console a positive integer n and 
 prints all the numbers from 1 to n not divisible by 3 and 7, on a single line,
 separated by a space.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int number;
    
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
            if (((ctr % 3) != 0) && ((ctr % 7) != 0))
            {
                printf("%d ", ctr);
            }
            ctr++;
        }
    }

    return (EXIT_SUCCESS);
}

