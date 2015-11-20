/* 
 Your task is to write a program that calculates n! /(k!* (n-k)!)for given 
 n and k (1<k<n< 100).Try to use only two loops.
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *, int *);

int main()
{
    int n, k; // 52 5
    int diffrenceNK;
    unsigned long long factorialK = 1, factorDiference = 1, result = 1;

    printf("Enter n and k: ");
    checkIntInput(&n, &k);

    diffrenceNK = n - k; // 47
    if (k > 1 && k < n && k < 100)
    {
        if (diffrenceNK > k)
        {
            int i;
            for (i = 1; i <= k; i++)
            {
                factorialK *= i;
            }

            for (i = n - k + 1; i <= n; i++)
            {
                result *= i;
            }

            result /= factorialK;
        }
        else
        {
            int i;
            for (i = k + 1; i <= n; i++)
            {
                result *= i;
            }

            for (i = 1; i <= diffrenceNK; i++)
            {
                factorDiference *= i;
            }

            result /= factorDiference;
        }
        printf("%lld", result);
    }
    else
    {
        printf("The numbers should be (1 < k < n < 100)!");
        exit(EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

void checkIntInput(int *a, int *b)
{
    if ((scanf("%d %d", a, b)) != 2)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}