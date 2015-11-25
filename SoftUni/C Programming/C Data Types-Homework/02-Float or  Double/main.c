/* 
 Which of the following values can be assigned to a variable of type float
and which to a variable of type double: 34.567839023, 12.345, 8923.1234857, 
3456.091? Write a program to assign the numbers in variables and print
them to ensure no precision is lost.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    float first = 12.345;
    float second = 3456.091;
    double third = 34.567839023;
    double fourth = 8923.1234857;

    printf("%f\n", first);
    printf("%f\n", second);
    printf("%.9f\n", third);
    printf("%.7f\n", fourth);
    
    return (EXIT_SUCCESS);
}

