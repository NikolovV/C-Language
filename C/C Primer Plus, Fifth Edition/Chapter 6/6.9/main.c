#include <stdio.h>
#include <stdlib.h>

void SquaresSum(int a, int b)
{
    int l=0, sum=0;

    for (l = a; l<=b; l++)
    {
        sum+=l*l;
    }
    printf("The sums of the squares from %d to %d is %d\n", a*a, b*b, sum);

}

int main()
{
    int lowerLimit, uperLimit;
    int k=0;

    do
    {
        printf("Enter lower and upper integer limits (q - to quit): ");
        k=(scanf("%d %d", &lowerLimit, &uperLimit));
        if (k)
        {
            SquaresSum(lowerLimit, uperLimit);
        }
        fflush(stdin);
    }
    while (k);

    return 0;
}
