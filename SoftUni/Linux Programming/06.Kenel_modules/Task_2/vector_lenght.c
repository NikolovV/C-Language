#include "task_2.h"

unsigned int vector_lenght(int X1, int Y1, int X2, int Y2)
{
    unsigned int vector_len = sqrt_integers((pow_integers((X2-X1), 2) + pow_integers((Y2-Y1), 2)));
    return vector_len;
}
