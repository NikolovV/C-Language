#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t begin, end;
    double time_spent;

    begin = clock();
    int i = 0;
    while (i++ < 10000000)
    {}
    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("On stack %.3lf seconds\n", time_spent);
    
    begin = clock();
    int *ptr = malloc(1 * sizeof (int));
    while ((*ptr) < 10000000)
    {
        (*ptr) += 1;
    }
    free(ptr);
    
    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("On heap %.3lf seconds\n", time_spent);

    return 0;
}
