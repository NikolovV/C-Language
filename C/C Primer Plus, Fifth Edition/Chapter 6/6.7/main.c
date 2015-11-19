#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k=0;
    float num1, num2;
    double diference;

    do
    {
        printf("Enter two floating-point numbers (q - to quit): ");
        k = (scanf("%f %f", &num1, &num2));
		if (k)
		{
            diference = (double)(num1-num2)/(num1*num2);
            printf("diference = %lf\n", diference);
		}
        fflush(stdin);
    }
    while (k);

	return 0;
}
