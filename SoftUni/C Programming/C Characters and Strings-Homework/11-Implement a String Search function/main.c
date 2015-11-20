/* 
 Implement a function which checks whether a string appears as a substring in 
 another string. It should return 1 if the string occurs and 0 if it does not.
 Its declaration could be:
 int strsearch(char * src, char * substr);
 */

#include <stdio.h>
#include <stdlib.h>

int strsearch(char *src, char *substr);

int main()
{
    printf("%d\n", strsearch("SoftUni", "Soft"));

    printf("%d\n", strsearch("Hard Rock", "Rock"));

    printf("%d\n", strsearch("Ananas", "nasa"));

    printf("%d\n", strsearch("Coolness", "cool"));

    return (EXIT_SUCCESS);
}

int strsearch(char *src, char *substr)
{
    if (*substr == '\0')
    {
        return 0;
    }
    if (*src == '\0')
    {
        return 0;
    }

    char *start = src;
    char *p;

    while (*start != '\0')
    {
        p = start;
        char *q = substr;
        while (*p != '\0' && *q != '\0' && *p == *q)
        {
            p++;
            q++;
        }
        if (*q == '\0')
        {
            return 1;
        }
        start++;
    }

    return 0;
}