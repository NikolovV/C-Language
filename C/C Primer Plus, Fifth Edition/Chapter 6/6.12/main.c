#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARR_LENGHT 8
#define TWO 2.0

int main()
{
	int arr[ARR_LENGHT]={1,1,1,1,1,1,1,1};
	int arrPowerOfTwo[ARR_LENGHT];
	int k;

	for (k=0; k<=ARR_LENGHT; k++)
	{
		arrPowerOfTwo[k]=((double)arr[k])*pow(TWO, k);
	}
	k=0;
	do
	{
		printf("%d -> %d\n", k, arrPowerOfTwo[k]);
	} while (k++<ARR_LENGHT);

    return 0;
}
