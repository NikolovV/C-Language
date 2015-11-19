#include <stdio.h>
#include <stdlib.h>
#define ARR_LENGHT 8

int main()
{
	double first[ARR_LENGHT]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8}, second[ARR_LENGHT];
	int k;

	second[0]=first[0];
	for (k=1; k<ARR_LENGHT; k++)
	{
		second[k]=first[k]+first[k-1];
	}
	k=0;
	while (k<ARR_LENGHT)
	{
		printf("first[%d] - %3.2f -> secod[%d] - %5.2f\n",
				k, first[k], k, second[k]);
		++k;
	}

    return 0;
}
