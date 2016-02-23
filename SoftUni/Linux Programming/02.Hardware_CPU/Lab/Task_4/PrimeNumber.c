#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t begin, end;
    double time_spent;

    begin = clock();
    int number = 10000, flag, count = 0;

    int i, j;
    for (i = 3; i <= number; i = i + 2)
    {
        flag = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if ((i % j) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            count++;
        }
    }
    
    printf("Number of primes upto %d is %d\n", number, count);
    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("%.3lf seconds\n", time_spent);
    
    return 0;
}
