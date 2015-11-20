/* 
 Write an expression that calculates trapezoid's area by given sides a and b and height h.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(double *, double *, double *);

int main()
{
    double a, b, h;
    
    printf("Enter sides a and b and height h: ");
    checkInput(&a, &b, &h);
    
    printf("Area is: %.2lf", ((double)(a + b)/2)*h);

    return (EXIT_SUCCESS);
}

void checkInput(double *a, double *b, double *h)
{
    if ((scanf("%lf%lf%lf", a, b, h)) != 3)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}