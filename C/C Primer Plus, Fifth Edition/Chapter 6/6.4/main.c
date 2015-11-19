#include<stdio.h>
int main()
{
    char ch = 'A';
    int rows = 5, space = 0, lineNumber, colLeft, colRight;

	// Pass through the rows.
    for (lineNumber=0; lineNumber<=rows; lineNumber++)
    {
    	// Fill the space.
    	for (space = rows - lineNumber; space; space--)
    	{
			printf(" ");
    	}
		// Print the left side.
    	for (colLeft=ch; colLeft<='A'+lineNumber; colLeft++)
    	{
    		printf("%c", ch);
    		ch++;
    	}
    	ch -= 2;
    	//Print the left side.
    	for (colRight=ch; colRight>='A'+0;colRight--)
    	{
			printf("%c", ch);
			ch--;
    	}
    	ch='A';
    	printf("\n");
    }
    return 0;
}
