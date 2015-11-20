/* 
 Write a recursive string reverse function. The function should accept 
 a source string and destination string as arguments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER 50

char *make_char(char *str, int buff);
void reverse_string(char str[], char *destination, int lenght, int n, int m);
int remove_new_line(char *str);

int main()
{
    char source[BUFFER];
    char *destination = make_char(destination, BUFFER);
    if (destination == NULL)
    {
        printf("Not enough memory!");
        exit(EXIT_FAILURE);
    }

    printf("Enter a string to reverse: ");
    fgets(source, BUFFER, stdin);
    int lenght = remove_new_line(source);


    reverse_string(source, destination, lenght, 0, lenght - 2);
    printf("Reversed: %s", destination);

    free(destination);

    return (EXIT_SUCCESS);
}

void reverse_string(char str[], char *destination, int lenght, int n, int m)
{
    if (n == lenght - 1)
    {
        destination[n] = '\0';
        return;
    }
    destination[m] = str[n];
    reverse_string(str, destination, lenght, ++n, --m);
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

char *make_char(char *str, int buff)
{
    str = calloc(buff, sizeof (char));
    return str;
}