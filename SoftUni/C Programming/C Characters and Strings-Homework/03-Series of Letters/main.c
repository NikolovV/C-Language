/* 
 Write  a  program that  reads  a  string  from  the  console  and  
 replaces  all  series  of consecutive  identical  letters  with  a single one.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  BUFFER 50

char *line_reading(size_t lenght);
char *remove_repeating_chars(const char *str);

int main()
{
    printf("Enter string\n");
    char *line = line_reading(BUFFER);
    
    char *lineCopy = remove_repeating_chars(line);
    
    printf("%s", lineCopy);

    free(line);
    free(lineCopy);

    return (EXIT_SUCCESS);
}

char *remove_repeating_chars(const char *str)
{
    int len = strlen(str);
    char *copy = malloc(len * sizeof (char));

    copy[0] = str[0];
    int i, index = 1;
    for (i = 1; i < len - 1; i++)
    {
        if (copy[index - 1] != str[i])
        {
            copy[index] = str[i];
            index++;
        }
    }

    copy[index] = '\0';

    return copy;
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