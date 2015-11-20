/* 
 Binary search works only on sorted collections. It picks the mid element
 of the collection and checks if it's equal to the searched element.
 * If it's equal, returns the mid index.
 * If it's smaller, cuts the right half of the collection and 
 repeats the same step.
 * If it's larger, cuts the left half of the collection and 
 repeats the same step.
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
int iterative_binary_search(const int str[], int size, int search);

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
    
    result = iterative_binary_search(buffer, n, searchNum);
    
    printf("%d", result);
    
    return (EXIT_SUCCESS);
}

int iterative_binary_search(const int str[], int size, int search)
{
    int imin = 0, imax = size, imid;
    while (imin <= imax)
    {
      int imid = (imin + imax)/2;
      if(str[imid] == search)
        return imid; 
      else if (str[imid] < search)
        imin = imid + 1;
      else         
        imax = imid - 1;
    }
  return -1;
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