#include <stdio.h>
#include <stdlib.h>
#include<float.h>

int main()
{
	double d = 1.0/3.0;
	float f = 1.0/3.0;

	printf("%.4f\n", d);
	printf("%.12f\n", d);
	printf("%.16f\n", d);

	printf("%.4f\n", f);
	printf("%.12f\n", f);
	printf("%.16f\n", f);

	printf("%d %d\n", FLT_DIG, DBL_DIG);
    return 0;
}
