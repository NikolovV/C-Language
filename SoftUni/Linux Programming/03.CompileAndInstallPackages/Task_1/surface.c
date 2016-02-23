#include "perimeter_and_surface.h"

void surface_calculate(int angels, double side)
{
    if (angels <= 2)
    {
        fprintf(stderr, "Could not be an equilateral figure!");
        exit(0);
    }
    else if (angels == 3)
    {
        double s = (sqrt(3) / 4) * side * side;
        printf("Surface is: %g\n", s);
    }
    else if (angels == 4)
    {
        double s = side * side;
        printf("Surface is: %g\n", s);
    }
    else if (angels >= 5)
    {
        double a = side / (2 * tan(PI / angels * 1.0));
        double s = (angels * side * a) / 2.0;
        printf("Surface is: %g\n", s);
    }
}