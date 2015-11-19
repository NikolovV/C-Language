#include <stdio.h>
#include <stdlib.h>

void cubic(float n)
{
	float cub = n*n*n;
	printf("cub of %.0f = %.0f", n, cub);
}
int main()
{
	float a;

	scanf("%f", &a);
	cubic(a);

    return 0;
}
