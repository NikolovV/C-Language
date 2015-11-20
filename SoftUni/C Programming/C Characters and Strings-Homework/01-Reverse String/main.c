/* 
 Write a program that reads a string from the console, reverses it 
 and prints the result back at the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 20

size_t remove_new_line(char *str);
void reverce_str(char *dest, const char sourse[], size_t len);

int main()
{
    char bufer[BUFFER];
    
    fgets(bufer, BUFFER, stdin);
    size_t lengh = remove_new_line(bufer);
    
    char reverst[lengh - 1];
    reverce_str(reverst, bufer, lengh);
    
    printf("%s", reverst);

    return (EXIT_SUCCESS);
}

void reverce_str(char *dest, const char sourse[], size_t len)
{
    int i, j = len - 2;
    for (i = 0; i < len - 1; i++, j--)
    {
        dest[j] = sourse[i];
    }
    
    dest[len-1]='\0';
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght;
}