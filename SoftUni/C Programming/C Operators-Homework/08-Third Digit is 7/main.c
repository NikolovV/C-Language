/* 
 Write an expression that checks for given integer if its third digit from right
-to - left is 7. Print true or false.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);

int main()
{
    int digit, thirdDigit;

    printf("Enter digit: ");
    checkInput(&digit);
    
    thirdDigit = digit / 100;

    if ((thirdDigit % 10) == 7)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return (EXIT_SUCCESS);
}

void checkInput(int *A)
{
    if ((scanf("%d", A)) != 1 )
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}