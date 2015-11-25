/* 
 Create a console application that calculates and prints the square root
 of the number 12345.
 7.1 Modify your program to read the number from the console. 
 Use the scanf()function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
    double number;
    double square;
    
    printf("Enter number: ");
    scanf("%lf", &number);
    square = sqrt(number);
    printf("The square root of %lf is %lf", number, square);    
   
    return (EXIT_SUCCESS);
}