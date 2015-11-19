#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 6;
    int p=0;
    char ch = 'F';

    for (;p < N; p++)
    {
        for (ch = 'F'; ch >= 'F' - p; ch--)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
