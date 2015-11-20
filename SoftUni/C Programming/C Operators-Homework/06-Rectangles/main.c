/* 
 Write an expression that calculates rectangle’s perimeter and area
 by given width and height.
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(double *, double *);

int main()
{
    double width, height;
    double area, perimeter;
    
    printf("Enter width and height: ");
    checkInput(&width, &height);
    
    area = width * height;
    perimeter = (2 * width) + (2 * height);
    
    printf("The perimeter = %.1lf and area = %.1lf", perimeter, area);

    return (EXIT_SUCCESS);
}

void checkInput(double *A, double *B)
{
    if ((scanf("%lf %lf", A, B)) != 2)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}