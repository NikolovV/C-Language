#include <stdio.h>
#include <string.h>

int main(void)
{
    char first[10], last[10];

    // right aling
    scanf("%9s %9s", first, last);
    printf("%s %s\n", first, last);
    printf("%*d %*d\n",
           strlen(first),strlen(first), strlen(last),strlen(last));

    // left aling

    printf("%s %s\n", first, last);
    printf("%-*d %-*d",
           strlen(first),strlen(first), strlen(last),strlen(last));


    return 0;
}
