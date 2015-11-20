/* 
 Write a program that calculates n! / k!for given n and k(1<k<n< 100).
 Use only one loop. 
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *, int *);

int main()
{
    int n, k;
    int factorialN = 1;
    int factorialK = 1;

    printf("Enter n and k: ");
    checkIntInput(&n, &k);
    
    if (k > 1 && k < n && k < 100)
    {
        int i;
        for (i = 1; i <= n; i++)
        {
            factorialN *= i;
            if (i <= k)
            {
                factorialK *= i;
            }
        }
        
        printf("%d", factorialN / factorialK);
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