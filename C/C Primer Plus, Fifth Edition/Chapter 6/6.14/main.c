#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_LENGHT 255

int main()
{
	char arr[ARR_LENGHT];
	int k;

	scanf("%254[^\n]", arr); // This will read into the string: comment
	                         // everything from the next 99 characters up until
	                         // it gets a newline
	k=strlen(arr);
	k--;					 // Remove \n sign.
	for (;k>=0;k--)
	{
		printf("%c", arr[k]);
	}

    return 0;
}
