/* 
  Write a function that takes a string as input and replaces all 
  occurrences of a digit (0-9) with a slash '/'. The function should NOT 
  modify the original string. It should return the resulting string as 
  result. The function should also notify the calling function how many 
  digits were replaced. Find a way to do this using pointer parameters.
  Tip: Be careful where you allocate the resulting string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 100

void error(const char *msg);
char *replace_digit(char *destination, const char *str, size_t size, 
                    char replaceMark, int *swaped);

int main()
{
    char line[BUFFER];

    fgets(line, BUFFER, stdin);
    int lineLenght = remove_new_line(line);

    int changedDigit = 0;
    char *resultStr = calloc(lineLenght, sizeof (char));
    if (resultStr)
    {
        error("Can't allocate memory.");
    }

    resultStr = replace_digit(resultStr, line, lineLenght, '/', &changedDigit);
    
    printf("%s\n", resultStr);
    printf("%d has changed.", changedDigit);

    free(resultStr);

    return (EXIT_SUCCESS);
}

char *replace_digit(char *destination, const char *str, size_t size, 
                    char replaceMark, int *swaped)
{
    int i;
    for (i = 0; i < size; i++)
    {
        *(destination + i) = *(str + i);
        
        if ((*(destination + i) >= '0') && (*(destination + i) <= '9'))
        {
            *(destination + i) = replaceMark;
            (*swaped)++;
        }
    }

    return destination;
}

int remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght;
}

void error(const char *msg)
{
    perror(msg);
    exit(1);
}