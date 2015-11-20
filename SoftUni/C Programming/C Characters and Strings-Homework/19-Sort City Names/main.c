/* 
 You are given a list of cities. You have to process them and sort them 
 in ascending order. On the first input line, you are given the count 
 of the cities. Use an algorithm other than bubble sort.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER 20

char *line_reading(size_t lenght);
void check_intInput(int *a);
void insert_selection_sort(char *sr[], size_t size);
void print_array(char *str[], size_t size);
void free_array(char *str[], size_t size);

int main()
{
    printf("Enter number of city: ");
    int n;

    check_intInput(&n);

    char *line = NULL;
    char **cities = calloc(n, sizeof (char *));
    if (!cities)
    {
        fprintf(stderr, "%s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    size_t lineLenght = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        line = line_reading(BUFFER);
        lineLenght = strlen(line);
        cities[i] = calloc(lineLenght + 1, sizeof (char));
        if (!cities)
        {
            fprintf(stderr, "%s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        strcpy(cities[i], line);
        free(line);
    }

        insert_selection_sort(cities, n);
        print_array(cities, n);

    free_array(cities, n);

    return (EXIT_SUCCESS);
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

void insert_selection_sort(char *str[], size_t size)
{
    char *temp;
    int i, j, k, compare = 0;
    for (i = 1; i <= size - 1; ++i)
    {
        for (j = 0; j < i; ++j)
            
            if (strcasecmp(str[j], str[i]) >= 0)
            {
                temp = str[i];
                k = i;
                while (k != j)
                {
                    str[k] = str[k - 1];
                    --k;
                }
                str[j] = temp;
            }
    }
}

void print_array(char *str[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s\n", str[i]);
    }
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