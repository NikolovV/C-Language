#include "perimeter_and_surface.h"

void perimeter_calculate(int angels, double side)
{
    if (angels <= 2)
    {
        fprintf(stderr, "Could not be an equilateral figure!");
        exit(0);
    }
    else if (angels == 3)
    {
        printf("Perimeter is: %g\n", 3.0 * side);
    }
    else if (angels == 4)
    {
        printf("Perimeter is: %g\n", 4.0 * side);
    }
    else if (angels >= 5)
    {
        printf("Perimeter is: %g\n", (double)angels * side);
    }
}