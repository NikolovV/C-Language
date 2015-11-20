/* 
 Write a program that enters 3 real numbers and prints them sorted 
 in descending order. Use nested if statements.
 Don’t use arrays and the built-in sorting functionality. 
 */

#include <stdio.h>
#include <stdlib.h>

void descending(double, double, double);
double grater(double, double);
double smaler(double, double);

int main()
{
    double first, second, third;
    
    printf("Enter 3 numbers: ");
    if ((scanf("%lf %lf %lf", &first, &second, &third)) != 3)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
    
    descending(first, second, third);
     
    return (EXIT_SUCCESS);
}

void descending(double a, double b, double c)
{
    if (a > b && a > c)
    {
        printf("%.1lf %.1lf %.1lf", a, grater(b, c), smaler(b, c));
    }
    else if (b > a && b > c)
    {
        printf("%.1lf %.1lf %.1lf", b, grater(a, c), smaler(a, c));
    }
    else
    {
        printf("%.1lf %.1lf %.1lf", c, grater(a, b), smaler(a, b));
    }
}

double grater(double x, double y)
{
    return (x > y) ? x : y;
}
double smaler(double x, double y)
{
    return (x < y) ? x : y;
}