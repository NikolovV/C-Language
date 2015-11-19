#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8}, l;

    // Finding the number of element if they are not set in definition. Size of all array / size of 1 element.
    l = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", l);
    while (l--)
    {
        printf("arr[%d] -> %d\n", l, arr[l]);
    }

    return 0;
}
