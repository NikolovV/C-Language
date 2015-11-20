/* 
 Write an if -statement that takes two integer variables a and b and exchanges 
 their values if the first one is greater than the second one.
 As a result print the values a and b, separated by a space.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(double *, double *);
void swapIfGreater(double *, double *);


int main()
{
    double firstNum, secondNum, a = 5.5, b = 2.0;
    
    printf("Enter a and b: ");
    checkInput(&firstNum, &secondNum);
    printf("Before change: a = %.1lf and b = %.1lf\n", firstNum, secondNum);
    
    swapIfGreater(&firstNum, &secondNum);
    
    return (EXIT_SUCCESS);
}

void checkInput(double *a, double *b)
{
    if ((scanf("%lf%lf", a, b)) != 2)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

void swapIfGreater(double *a, double *b)
{
    if (*a > *b)
    {
        double temp = *a;
        *a = *b;
        *b = temp;
        printf("Agter change: a = %.1lf and b = %.1lf\n", *a, *b);
    }
    else
    {
        printf("Nothing has change! - a = %.1lf and b = %.1lf\n", *a, *b);
    }
}