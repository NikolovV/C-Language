/* 
 Write a function that reverses the digits of a given floating-point number.
 The function should receive a double number and a pointer to an integer
 variable. 
 In case of format error, it should set error to 1and in case of success to 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 20

double reverse_number(char *, int *);
char *make_char(char *, int);
void clear_memory(char *);
char *reverse_input(char *);

int main()
{
    int error;
    char *input = make_char(input, BUFFER);
    char *reverteInput = make_char(reverteInput, BUFFER);

    printf("Enter number: ");
    fgets(input, BUFFER, stdin);

    reverteInput = reverse_input(input);

    double reversed = reverse_number(reverteInput, &error);

    if (error != 1)
    {
        printf("%.3f", reversed);
    }
    else
    {
        printf("Invalid format");
    }

    clear_memory(input);
    clear_memory(reverteInput);

    return (EXIT_SUCCESS);
}

char *reverse_input(char *str)
{
    int lenght = strlen(str);
    char *buffer = make_char(buffer, lenght);

    int i, k = lenght - 2;
    for (i = 0; i < lenght; i++, k--)
    {
        buffer[i] = str[k];
    }

    return buffer;
}

double reverse_number(char *str, int *error)
{
    *error = 0;
    char *remainder;
    double reverseNumber;

    reverseNumber = strtod(str, &remainder);
    if (*remainder != '\0')
    {
        *error = 1;

        return 0;
    }

    return reverseNumber;
}

char *make_char(char *str, int buff)
{
    str = calloc(buff, sizeof (char));
    return str;
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