/* 
 Write a program that reads n lines in XML format and parses their contents. 
 A line is considered valid if it follows the format <{tag}>{data}</{tag}>. 
 In case of invalid line format, print "Invalid format".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 50

char *line_reading(size_t lenght);
char *extract_xml(char *str);

int main(int argc, char** argv)
{
    printf("Enter xml data: ");
    char *line = line_reading(BUFFER);

    char *copy = strdup(line);
    char *result = extract_xml(copy);

    if (result)
    {
        printf("%s\n", result);
        free(result);
    }

    free(copy);
    free(line);

    return (EXIT_SUCCESS);
}

char *extract_xml(char *str)
{
    int index = 0;
    char *firstTag = NULL, *data = NULL, *secondTag = NULL;
    char *token = strtok(str, "<>");
    if (!token)
    {
        return NULL;
    }

    while (token)
    {
        int tokenLenght = strlen(token);
        if (index == 0)
        {
            firstTag = calloc(tokenLenght + 1, sizeof (char));
            firstTag = strncpy(firstTag, token, tokenLenght + 1);
        }
        if (index == 1)
        {
            data = calloc(tokenLenght + 1, sizeof (char));
            data = strncpy(data, token, tokenLenght + 1);
        }
        if (index == 2)
        {
            if (token[0] != '/')
            {
                fprintf(stderr, "Invalid format!");
                free(firstTag);
                free(data);
                return NULL;
            }
            else
            {
                secondTag = calloc(tokenLenght + 1, sizeof (char));
                secondTag = strncpy(secondTag, token, tokenLenght + 1);
            }

            secondTag += 1;
            char *areEqual = strstr(firstTag, secondTag);
            if (!areEqual)
            {
                fprintf(stderr, "Invalid format!");
                free(firstTag);
                secondTag -= 1;
                free(secondTag);
                free(data);
                return NULL;
            }
            secondTag -= 1;
        }

        index++;
        token = strtok(NULL, "<>");
    }

    if (index < 3)
    {
        fprintf(stderr, "Invalid format!");
        free(firstTag);
        free(secondTag);
        free(data);
        return NULL;
    }

    char *result = malloc((strlen(firstTag) + strlen(data) + 3));
    if (!result)
    {
        return NULL;
    }
    *firstTag = toupper(firstTag[0]);
    sprintf(result, "%s: %s", firstTag, data);

    free(firstTag);
    free(data);
    free(secondTag);

    return result;
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