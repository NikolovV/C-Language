/* 
 Implement a function which extracts a substring from a given string 
 by specifying the position from which to extract and the length to extract. 
 The declaration could be as follows: 
 * int substr(char * src, int position, int length);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substr(char * src, int position, int length);

int main()
{
    char *string = substr("Breaking Bad", 0, 2);
    printf("%s\n", string);
    free(string);

    string = substr("Maniac", 3, 3);
    printf("%s\n", string);
    free(string);

    string = substr("Maniac", 3, 5);
    printf("%s\n", string);
    free(string);

    string = substr("Master Yoda", 13, 5);
    printf("%s\n", string);
    free(string);

    return (EXIT_SUCCESS);
}

char *substr(char * src, int position, int length)
{
    size_t srcLen = strlen(src);
    if (srcLen < length || src == NULL)
    {
        return NULL;
    }
    if (srcLen < position)
    {
        char *subStr = malloc(1);
        if (!subStr)
        {
            return NULL;
        }
        subStr[0] = '\0';
        
        return subStr;
    }

    char *subStr = malloc(srcLen + 1);
    if (!subStr)
    {
        return NULL;
    }

    int i, k = position;
    for (i = 0; i < length; i++, k++)
    {
        subStr[i] = src[k];
    }
    subStr[i] = '\0';

    return subStr;
}