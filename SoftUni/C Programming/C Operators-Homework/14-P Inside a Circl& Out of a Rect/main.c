/* 
 Write an expression that checks for given point (x, y) if it is within the circle 
K({1,1}, 1.5)and out of the rectangle R(top=1, left=-1, width=6, height=2).
Print yes or no.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void checkInput(double *, double *);
bool isInisdeCircle(double, double, double);
bool isInsedeRectangle(double, double);

int main()
{
    bool isInCircle, isInRectangle, isInCircleOutRectangle;
    double R = 1.5;
    double pointX, pointY;
    
    printf("Point coordinate: ");
    checkInput(&pointX, &pointY);

    isInCircle = isInisdeCircle(pointX, pointY, R);
    isInRectangle = isInsedeRectangle(pointX, pointY);
    
    isInCircleOutRectangle = isInCircle && !isInRectangle;
    if (isInCircleOutRectangle)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return (EXIT_SUCCESS);
}

void checkInput(double *x, double *y)
{
    if ((scanf("%lf%lf", x, y)) != 2)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}

bool isInisdeCircle(double x, double y, double c)
{
    bool isInside = ((1 - x) * (1 - x)) + ((1 - y) * (1 - y)) <= c * c;

    return (isInside ? true : false);
}

bool isInsedeRectangle(double x, double y)
{
    bool isInside = (x >= -1 && x <= 5) && (y >= -1 && y <= 1);

    return (isInside ? true : false);
}