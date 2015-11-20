/* 
 Declare an array of integers and print it on the console. 
 Do NOT use the indexer operator [].
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *name = "Declare an array of integers and print it on the console.";
    size_t lenght = strlen(name);
    
    int i;
    for (i = 0; i < lenght; i++)
    {
        printf("%c\n", *(name + i));
    }

    return (EXIT_SUCCESS);
}

