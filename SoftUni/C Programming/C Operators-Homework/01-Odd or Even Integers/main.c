/* 
 Write an expression that checks if given integer is 
 odd or even.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);
void isODD(int);

int main()
{
    int number;
    
    printf("Enter number: ");
    checkInput(&number);
    
    isODD(number);
    
    return (EXIT_SUCCESS);
}

void checkInput(int *N)
{
    if ((scanf("%d", N)) != 1)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

void isODD(int num)
{
    (num%2==0)?printf("Even"):printf("Odd");
}