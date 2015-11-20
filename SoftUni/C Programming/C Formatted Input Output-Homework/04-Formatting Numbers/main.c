/* 
 Write a program that reads 3 numbers: an integer a  (0 ≤ a≤ 500), a floating
- point b and a floating - point c and prints them in 4 virtual columns 
 on the console. 
 */

#include <stdio.h>
#include <stdlib.h>

#define COLUMN "|%-10X|%010d|%10.1lf|%-10.3lf|"

void checkInput(int *, double *, double *);
int to_binary(int num);

int main()
{
    int a;
    double b, c;
    
    checkInput(&a, &b, &c);
    
    printf(COLUMN, a, to_binary(a), b, c);
    
    return (EXIT_SUCCESS);
}

void checkInput(int *a, double *b, double *c)
{
    printf("Enter 3 numbers: an integer a (0 ≤ a≤ 500), a floating-point b"
           " and a floating - point c:\n");
    
    if ((scanf("%d%lf%lf", a, b, c))!= 3)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

int to_binary(int num)
{
    int remind, i = 1, binary = 0;
    while (num != 0)
    {
        remind = num % 2;
        num /= 2;
        binary += remind*i;
        i *= 10;
    }
    return binary;
}