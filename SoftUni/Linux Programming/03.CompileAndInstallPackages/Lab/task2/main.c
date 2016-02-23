#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define MAX_NUMBER ULLONG_MAX

int main()
{
    unsigned long long i, j, largestFound;
    bool flag;

    clock_t begin, end;
    double time_spent;
    double executingTime;
    if ((scanf("%lf%*c", &executingTime)) != 1)
    {
        fprintf(stderr, "Incorect input!");
        exit(1);
    }
    
    begin = clock();
    for (i = 2; i < MAX_NUMBER; i++)
    {
        flag = 0;
        for (j = 2; j <= sqrt(i); j++)
        {
            if ((i % j) == 0)
            {
                flag = 1;
                break;
            }
            
            time_spent = (double) ((end = clock()) - begin) / CLOCKS_PER_SEC;
            if (time_spent >= executingTime)
            {
                break;
            }
        }

        if (flag == 0)
        {
            largestFound = i;
        }
        
        time_spent = (double) ((end = clock()) - begin) / CLOCKS_PER_SEC;
        if (time_spent >= executingTime)
        {
            break;
        }
    }

    printf("Largest found prime number for %g seconds is %llu\n",
           executingTime, largestFound);

    return 0;
}
