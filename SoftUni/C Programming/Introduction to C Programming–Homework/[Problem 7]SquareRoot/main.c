/* 
 Create a console application that calculates and prints the square root
 of the number 12345. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
    double number = 12345;
    double square = sqrt(number);
    
    printf("The square root of %lf is %lf", number, square);    
   
    return (EXIT_SUCCESS);
}

