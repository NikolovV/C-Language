/* 
 Write a function that takes determines the position of the rightmost occurrence
 of a character ch in a string str. If no such character exists, 
 the function should return -1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 100

char *make_char(char *, int);
void clear_memory(char *);
void enter_data(char *);
int right_most_occurrence(const char *, char);

int main()
{
    char *firstString = make_char(firstString, BUFFER);
    char character;
    if (firstString == NULL)
    {
        printf("Not enough memory!");
        exit(EXIT_FAILURE);
    }

    enter_data(firstString);
    printf("Enter char:");
    character = getchar();
    getchar();
    
    int index = right_most_occurrence(firstString, character);
    if (index == -1)
    {
        printf("No such character.");
    }
    else
    {
        printf("%d", index);
    }

    clear_memory(firstString);

    return (EXIT_SUCCESS);
}

int right_most_occurrence(const char *str, char ch)
{
    int i, index = -1;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            index = i;
        }
    }
    
    return index;
}

char *make_char(char *str, int buff)
{
    str = calloc(buff, sizeof (char));
    return (str);
}

void enter_data(char *str)
{
    printf("Enter string: ");
    fgets(str, BUFFER, stdin);
}

void clear_memory(char *str)
{
    free(str);
}