#include "task_2.h"

unsigned long sqrt_integers(unsigned long number)
{
    register unsigned long op, res, one;

    op = number;
    res = 0;

    one = 1 << 30;
    while (one > op) one >>= 2;

    while (one != 0)
    {
        if (op >= res + one)
        {
            op -= res + one;
            res += one << 1;
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
} 
