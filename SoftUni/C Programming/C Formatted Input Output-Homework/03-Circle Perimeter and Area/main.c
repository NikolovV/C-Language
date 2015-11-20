/* 
 Write a program that reads the radius r of a circle and prints its perimeter and area
 formatted with 2 digits after the decimal point.
 */

#include <stdio.h>
#include <stdlib.h>

void circleCalculate(float);

int main()
{
   float radius;

    printf("Enter radius: ");

    if ((scanf("%f", &radius) == 1.0))
    {
        circleCalculate(radius);
    }
    else
    {
        fprintf(stderr, "Wrong value!");
        exit(1);
    }

    return (EXIT_SUCCESS);
}

void circleCalculate(float r)
{
    float perimeter, area;
    const float PI = 3.14159;

    perimeter = 2 * PI * r;
    area = PI * (r * r);

    printf("The circle with radius %.2f has an perimeter %.2f and area %.2f\n",
           r, perimeter, area);

}