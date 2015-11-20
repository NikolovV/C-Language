/* 
 Write a program to find the longest area of equal elements in array of strings.
 You first should read an integer n and n strings (each at a separate line), 
 then find and print the longest sequence of equal elements (first its length, 
 then its elements). If multiple sequences have the same maximal length, 
 print the leftmost of them. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER 20

char *line_reading(size_t lenght);
void check_intInput(int *a);
void longest_area_in_array(char *str[], size_t size);
void free_array(char *str[], size_t size);

int main()
{
    int n;
    printf("Enter n: ");
    check_intInput(&n);

    char **arrLine = calloc(n, sizeof (char *));
    if (!arrLine)
    {
        fprintf(stderr, "%s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < n; i++)
    {
        char *line = line_reading(BUFFER);

        int lineLenght = strlen(line);
        arrLine[i] = calloc(lineLenght + 1, sizeof (char));
        if (!arrLine)
        {
            fprintf(stderr, "%s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        strcpy(arrLine[i], line);

        free(line);
    }

    longest_area_in_array(arrLine, n);

    free_array(arrLine, n);

    return (EXIT_SUCCESS);
}

void longest_area_in_array(char *str[], size_t size)
{
    int longestAreaLength = 1;
    int currentAreaLength = 1;
    char *longestStr = str[0];
    char *currentStr = longestStr;

    int i;
    for (i = 1; i < size; i++)
    {
        if (i != size - 1 && strcmp(str[i], currentStr) == 0)
        {
            currentAreaLength++;
        }
        else
        {
            if (strcmp(str[i], currentStr) == 0)
            {
                currentAreaLength++;
            }

            if (currentAreaLength > longestAreaLength)
            {
                longestAreaLength = currentAreaLength;
                longestStr = currentStr;
            }

            currentStr = str[i];
            currentAreaLength = 1;
        }
    }

    printf("\n%d\n", longestAreaLength);
    for (i = 0; i < longestAreaLength; i++)
    {
        printf("%s\n", longestStr);
    }
}

void free_array(char *str[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        free(str[i]);
    }

    free(str);
}

void check_intInput(int *a)
{
    if ((scanf("%d%*c", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
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

