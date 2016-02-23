#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define BUF_SIZE 50
#define MAXOP 10

int main()
{    
    char buffer[BUF_SIZE];
    fgets(buffer, BUF_SIZE, stdin);

    char sign[MAXOP];
    float digit[MAXOP];
    
    char *token = strtok(buffer, " ");
    int i = 0, j = 0;
    while (token)
    {
        if (i < 0 || i > MAXOP - 1 || j < 0 || j > MAXOP - 1)
        {
            break;
        }

        switch (*token)
        {
        case '*':
        {
            token = strtok(NULL, " ");
            digit[i] = atof(token);
            i--;
            digit[i] = digit[i] * digit[i + 1];
            i++;
            break;
        }
        case '/':
        {
            token = strtok(NULL, " ");
            digit[i] = atof(token);
            i--;
            digit[i] = digit[i] / digit[i + 1];
            i++;
            break;
        }
        case '+':
        {
            sign[j]=*token;
            j++;
            break;
        }
        case '-':
        {
            sign[j]=*token;
            j++;
            break;
        }

        default:
        {
            digit[i] = atof(token);
            i++;
            break;
        }
        }

        token = strtok(NULL, " ");
    }
    int k = 0;
    i = 0;
    while (k < j)
    {
        switch (sign[k])
        {
        case '+':
        {
            digit[0] += digit[i + 1];
            i++;
            break;
        }
        case '-':
        {
            digit[0] -= digit[i + 1];
            i++;
            break;
        }
        }

        k++;
    }
    
    printf("%g\n", digit[0]);

    return 0;
}
