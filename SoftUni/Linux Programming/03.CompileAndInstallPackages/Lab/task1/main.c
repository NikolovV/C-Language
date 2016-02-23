#include "perimeter_and_surface.h"

int main()
{
    int angle;
    double side;
    
    scanf("%lf %d", &side, &angle);
    
    perimeter_calculate(angle, side);
    surface_calculate(angle, side);

    return (EXIT_SUCCESS);
}