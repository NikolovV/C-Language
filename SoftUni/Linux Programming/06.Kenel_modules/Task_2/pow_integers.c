#include "task_2.h"

int pow_integers(int number, int base)
{
    int i;
	int num = 1;
    for (i = 0; i < base; i++)
    {
        num *= number;
    }
    return num;
}
