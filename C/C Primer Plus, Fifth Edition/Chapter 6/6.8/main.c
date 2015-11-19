#include <stdio.h>
#include <stdlib.h>

double Difference(float a, float b)
{
    return (double)(a-b)/(a*b);
}

int main()
{
    int k=0;
    float num1, num2;

    do
    {
        printf("Enter two floating-point numbers (q - to quit): ");
        k = (scanf("%f %f", &num1, &num2));
        double diference;
		if (k)
		{
            diference = Difference(num1, num2);
            printf("diference = %lf\n", diference);
		}
        fflush(stdin);
    }
    while (k);

    return 0;
}
