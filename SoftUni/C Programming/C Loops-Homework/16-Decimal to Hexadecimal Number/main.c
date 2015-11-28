/* 
 Using loops write a program that converts an integer number to its 
 hexadecimal representation. The input is entered as long. 
 The output should be a variable of type string.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 20

void checkIntInput(long long *);
int decimalToHexadecimal(long long, char *);

int main()
{
    int lineStart;
    char hexadecimal[BUFFER];
    long long decimal;

    printf("Enter decimal number: ");
    checkIntInput(&decimal);

    if (decimal == 0L)
    {
        printf("Decimal %lld is hexadecimal 0", decimal);
    }
    else
    {
        lineStart = decimalToHexadecimal(decimal, hexadecimal);
		printf("Decimal %lld is hexadecimal %s",
           decimal, (hexadecimal + lineStart));
    }

    return (EXIT_SUCCESS);
}

void checkIntInput(long long *a)
{
    if ((scanf("%lld", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

int decimalToHexadecimal(long long number, char *str)
{
    int i = BUFFER - 1;
    char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    long reminder;

    for (; number > 0; i--)
    {
        reminder = number % 16;

        switch (reminder)
        {
        case 10:
            str[i] = 'A';
            break;
        case 11:
            str[i] = 'B';
            break;
        case 12:
            str[i] = 'C';
            break;
        case 13:
            str[i] = 'D';
            break;
        case 14:
            str[i] = 'E';
            break;
        case 15:
            str[i] = 'F';
            break;
        default:
            str[i] = nums[reminder];
            break;
        }
        number /= 16;
    }
    return (i + 1);
}