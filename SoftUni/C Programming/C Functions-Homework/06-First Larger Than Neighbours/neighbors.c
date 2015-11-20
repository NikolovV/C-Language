#include <stdio.h>
#include <stdlib.h>

int get_larger_neighbors_index(const int *str, size_t size)
{
    int index = -1;

    int i;
    for (i = 1; i < size ; i++)
    {
        if (str[i] > str[i + 1] && str[i] > str[i - 1])
        {
            index = i;
            break;
        }
    }

    return index;
}