/* 
 Write a program to find how many times a given string appears in a given text
 as substring. The text is given at the first input line. 
 The search string is given at the second input line. 
 The output is an integer number. Please ignore the character casing. 
 Overlapping between occurrences is allowed. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 200
#define SEARCH 10

char *line_reading(size_t lenght);
int substr_appears(const char *str, char *sub_str);

int main()
{
    printf("Enter string\n");
    char *line = line_reading(BUFFER);
     
    printf("Enter search sub-string\n");
    char *search = line_reading(SEARCH);
    
    int appears = substr_appears(line, search);
    printf("%d", appears);
    
    free(line);
    free(search);

    return (EXIT_SUCCESS);
}

int substr_appears(const char *str, char *sub_str)
{
    int appearsCount = 0;
    size_t len = strlen(sub_str);
    
    char *copy = strdup(str);
    
    int i = 0;
    while (copy[i] != '\0')
    {        
        if (strncasecmp((copy+i), sub_str, len) == 0)
        {
            appearsCount++;
        }
        copy[i++];
    }
    
    free(copy);

    return appearsCount;
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