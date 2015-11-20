/* 
 Write a program that takes as input a four - digit number in format abcd (e.g. 
 2011) and performs the following:
 * Calculates the sum of the digits (in our example 2+0+1+1= 4
 * Prints on the console the number in reversed order: dcba (in our example 1102).
 * Puts the last digit in the first position: dabc(in our example 1201).
 * Exchanges the second and the third digits: acbd(in our example 2101).
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);


int main()
{
    int number, sum, reversed, lastFirst, secondThird;
    int a, b, c, d;
    
    printf("Enter nuber: ");
    checkInput(&number);
    
    a = (number / 1000) % 10;
    b = (number / 100) % 10;
    c = (number / 10) % 10;
    d = number % 10;
    
    sum = a + b + c + d;
    reversed = (d*1000) + (c*100) + (b*10) + a;
    lastFirst = (d*1000) + (a*100) + (b*10) + c;
    secondThird = (a*1000) + (c*100) + (b*10) + d;

    printf("Sum is: %d\n", sum);
    printf("The number in reversed order: %d\n", reversed);
    printf("Last digit in the first position: %d\n", lastFirst);
    printf("Exchanges the second and the third digits: %d\n", secondThird);
  
    
    return (EXIT_SUCCESS);
}

void checkInput(int *number)
{
    if ((scanf("%d", number)) != 1 )
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}