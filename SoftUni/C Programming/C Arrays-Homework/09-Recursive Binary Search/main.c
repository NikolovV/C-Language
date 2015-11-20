/* 
 Implement binary search using recursion. You are not allowed to use loops.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
int recursive_binary_search(const int str[], int search, int imin, int imax);

int main()
{
    int n;

    printf("Enter n: ");
    check_intInput(&n);
    
    if (n <= 0)
    {
        printf("n > 0 !");
        exit(EXIT_FAILURE);
    }

    int buffer[n];
    printf("Enter %d numbers : ", n);
    fill_array(buffer, n);

    int result, searchNum;
    printf("Enter number to search: ");
    check_intInput(&searchNum);

    result = recursive_binary_search(buffer, searchNum, 0, n);

    printf("%d", result);

    return (EXIT_SUCCESS);
}

int recursive_binary_search(const int str[], int search, int imin, int imax)
{
    int imid;

    if (imax < imin)
        return -1;
    else
    {
        int imid = (imin + imax) / 2;

        if (str[imid] > search)
        {
            return recursive_binary_search(str, search, imin, --imid);
        }
        else if (str[imid] < search)
        {
            return recursive_binary_search(str, search, imid + 1, imax);
        }
        else
        {
            return imid;
        }
    }
}

void check_intInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

void fill_array(int str[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((scanf("%d", &str[i])) != 1)
        {
            printf("Not digit!");
            exit(EXIT_FAILURE);
        }
    }
}