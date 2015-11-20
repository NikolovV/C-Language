/* 
 Write a program that safely compares floating-point numbers(double) 
 with precision eps=0.000001 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compare(double, double);

int main(int argc, char** argv)
{
    double a, b;
    
    printf("Enter a and b to be compared: ");
    scanf("%lf %lf", &a, &b);
    
    compare(a, b);

    return (EXIT_SUCCESS);
}

void compare(double A, double B)
{
    double eps = 0.000001;
    
    if ((fabs(A-B))<=eps)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}