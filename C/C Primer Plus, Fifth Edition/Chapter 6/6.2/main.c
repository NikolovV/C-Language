#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int N = 10;
    int p = 0;
    char CH = '$';

    while (p++ < N)
    {
        int k = p;
        while (k--)
        {
            printf("%c", CH);
        }
        printf("\n");
    }
    return 0;
}
