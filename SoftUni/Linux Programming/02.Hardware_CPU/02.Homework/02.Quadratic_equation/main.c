#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER 50

int main()
{
    float a, b, c, determinant, r1, r2;

    char input[BUFFER];
    fgets(input, BUFFER, stdin);
    char *token = strtok(input, " ");
    int isMinus = 0;
    
    while (token)
    {
        size_t len = strlen(token);
        switch (token[len - 1])
        {
        case('a'):
        {
            a = atof(token);
            if (isMinus)
            {
                a *= -1;
                isMinus = 0;
            }
            break;
        }
        case('b'):
        {
            b = atof(token);
            if (isMinus)
            {
                b *= -1;
                isMinus = 0;
            }
            break;
        }
        case('-'):
        {
            isMinus = 1;
            break;
        }
        case('+'):
        {
            break;
        }
        default:
            c = atof(token);
            if (isMinus)
            {
                c *= -1;
                isMinus = 0;
            }
            break;
        }

        token = strtok(NULL, " ");
    }
    
    determinant = b * b - 4 * a*c;
    
    if (determinant > 0)
    {
        r1 = (-b + sqrt(determinant)) / (2 * a);
        r2 = (-b - sqrt(determinant)) / (2 * a);
        printf("root 1 = %.g; root 2 = %.g\n", r1, r2);
    }
    else if (determinant == 0)
    {
        r1 = r2 = -b / (2 * a);
        printf("root 1 = %.g; root 2 = %.g\n", r1, r2);
    }
    
    return 0;
}

