#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[]={"ABCEFGH"};
	int k;
	/* Set k to the end of the array, excluding termination zero.
	Use k>=0 to print the first(arr[0]). */
	for (k=strlen(arr)-1;k>=0;k--)
	{
		printf("%c", arr[k]);
	}

    return 0;
}
