#include <stdio.h>
#include <stdlib.h>
// x + 10
int main()
{
    int n, ctr=0;

    scanf("%d", &n);
    while (ctr<=10)
    {
        printf("%d\n", n++);
        ctr++;
    }
    return 0;
}
