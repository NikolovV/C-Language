/* 
 Write a program that, depending on the user’s choice, inputs an int, double
 or string variable.
 If the variable is int or double, the program increases it by one . 
 If the varia ble is a string, the program appends "*" at the end. 
 Print the result at the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 20

void removeNewLine(char *);

int main()
{
    printf("Please choose a type: \n");
    printf("1 --> int\n"
           "2 --> double\n"
           "3 --> string\n");

    int type;
    if (scanf("%d", &type) != 1)
    {
        printf("Not a int!");
        exit(EXIT_FAILURE);
    }
    else
    {
        switch (type)
        {
        case 1:
        {
            int intVal;
            printf("Enter number: ");
            if ((scanf("%d", &intVal)) != 1)
            {
                printf("Not a int!");
                exit(EXIT_FAILURE);
            }
            else
            {
                intVal++;
                printf("%d", intVal);
            }
            break;
        }
        case 2:
        {
            double dbVal;
            printf("Enter number: ");
            if ((scanf("%lf", &dbVal)) != 1)
            {
                printf("Not a double!");
                exit(EXIT_FAILURE);
            }
            else
            {
                dbVal++;
                printf("%.1lf", dbVal);
            }
            break;
        }
        case 3:
        {
            char strVal[BUFFER];
            printf("Enter string: ");
            
            getchar();
            fgets(strVal, BUFFER, stdin);
            removeNewLine(strVal);
          
            printf("%s*", strVal);
            break;
        }
        default:
            printf("The choise may be in range [1..3]!");
        }
    }
    return (EXIT_SUCCESS);
}

void removeNewLine(char *str)
{
    int inputLenght = strlen(str);
    str[inputLenght-1] = '\0';
}