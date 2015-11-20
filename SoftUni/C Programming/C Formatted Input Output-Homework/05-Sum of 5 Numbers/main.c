/* 
 Write  a  program that enters 5 numbers (given  in  a  single  line,  
 separated  by  a  space), calculates  and  prints  their sum.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1, num2, num3, num4, num5, sum;
    
    printf("Enter 5 numbers in  a  single  line: ");
    
    if ((scanf("%lf%lf%lf%lf%lf", &num1, &num2, &num3, &num4, &num5) != 5.0))
    {
        fprintf(stderr, "Wrong or missing argument!");
        exit(1);
    }
    else
    {
        sum = num1 + num2 + num3 + num4 + num5;
    }
    
    printf("Sum of the number is %.2lf", sum);
    
    return (EXIT_SUCCESS);
}