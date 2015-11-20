/* 
 Write an expression that checks if given point (x,  y)is inside a circle K({0, 0}, 2).
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(double *, double *);
void isInCircle(double , double , const short );

int main()
{
    double pointX, pointY;
    const short R = 2;

    printf("Enter point coordinates: ");
    checkInput(&pointX, &pointY);

    isInCircle(pointX, pointY, R);

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

void isInCircle(double a, double b, const short c)
{
    double isInside = (a * a) + (b * b) <= c * c;
    
    printf("Is inside: %s", isInside ? "Yes" : "No");
}