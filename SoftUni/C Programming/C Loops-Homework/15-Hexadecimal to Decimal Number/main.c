/* 
 Using loops write a program that converts a hexadecimal integer number 
 to its decimal form. The input is enter d as string. 
 The output should be a variable of type long.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFER 15

int removeNewLine(char *);
long long hexToDecimal(char *);

int main()
{    
    char hexadecimal[BUFER];
    int lineLenght;
    long long decimal;

    printf("Enter hexadecimal integer number: ");
    fgets(hexadecimal, BUFER, stdin);
    lineLenght = removeNewLine(hexadecimal);
    
    decimal = hexToDecimal(hexadecimal);

    printf("Decimal = %lld", decimal);

    return (EXIT_SUCCESS);
}

int removeNewLine(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }

    return lenght;
}

long long hexToDecimal(char *str)
{
    int current;
    long long pow = 1;
    long long numToDecimal = 0;
    int lenght = strlen(str);
    
    int i;
    for (i = lenght-1; i >= 0; i--)
    {       
        switch (str[i])
        {
        case 'A':
            current = 10;
            break;
        case 'B':
            current = 11;
            break;
        case 'C':
            current = 12;
            break;
        case 'D':
            current = 13;
            break;
        case 'E':
            current = 14;
            break;
        case 'F':
            current = 15;
            break;
        default:
            current = str[i] - 48;
            break;
        }
        
        numToDecimal += current * pow;
        pow *= 16;
    }

    return numToDecimal;
}