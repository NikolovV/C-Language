#include "City.h"

void check_intInput(int *x, int *y, int *z)
{	
    if ((scanf("%d %d %d", x, y, z)) != 3)
    {
        fprintf(stderr, "Not digit!");
        exit(1);
    }
}
