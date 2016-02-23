#include "task_2.h"

unsigned int triangle_surface(int perimeter, int a, int b, int c)
{
    int halfPerimeter = perimeter;
    halfPerimeter >>= 1;
    int area = sqrt_integers((halfPerimeter*(halfPerimeter - a)*(halfPerimeter - b)*(halfPerimeter - c)));
    return area;
}
