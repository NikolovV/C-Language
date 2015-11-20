/* 
 Write a program that takes as input two lists of names and removes from 
 the first list all names given in the second list. 
 The input and output lists are given as words, separated by a space, 
 each list at a separate line. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 100

char *line_reading(size_t lenght);
char *substract_names(char *str_a, char *str_b);
int main()
{
    printf("Enter first list name:\n");
    char *firstNameList = line_reading(BUFFER);
    
    printf("Enter list name to substract:\n");
    char *secondNameList = line_reading(BUFFER);
   
    substract_names(firstNameList, secondNameList);
    
    printf("%s", firstNameList);
    
    free(firstNameList);
    free(secondNameList);
    
    return (EXIT_SUCCESS);
}
char *substract_names(char *str_a, char *str_b)
{
    size_t firstLen = strlen(str_a);
    size_t secondLen = strlen(str_b);
    
    char *token = strtok(str_b, " ");
    while (token)
    {
        size_t length = strlen(token);
        char *substr = strstr(str_a, token);
        while (substr)
        {
            size_t index = substr - str_a;
            memmove(&str_a[index], &str_a[index + length + 1], 
                    firstLen - index);
            substr = strstr(str_a, token);
        }
        
        token = strtok(NULL, " ");
    }
        
    return str_a;
}

char *line_reading(size_t lenght)
{
    char *lineRead = malloc(8 * sizeof (char));
    char *linePtr = lineRead;
    size_t lenMax = 8, len = lenMax - 1;
    int c = 0;

    if (!lineRead)
    {
        return NULL;
    }

    while (c != EOF)
    {
        c = fgetc(stdin);
        if (c == '\n')
        {
            break;
        }
        else if (len > lenght)
        {
            break;
        }

        if (--len == 0)
        {
            len = lenMax;
            char* reallocated_line = (char*) realloc(lineRead, lenMax *= 2);

            if (!reallocated_line)
            {
                free(lineRead);
                return NULL;
            }

            linePtr = reallocated_line + (linePtr - lineRead);
            lineRead = reallocated_line;
        }

        *linePtr++ = c;
    }

    *linePtr = '\0';

    return lineRead;
}