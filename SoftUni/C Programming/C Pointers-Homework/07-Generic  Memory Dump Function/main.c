/* 
  Write a function that takes a pointer of any type, size of bytes n and row 
  length len. The function should print a total of n bytes, starting from the 
  address of the pointer. The output should be formatted into several rows, 
  each holding len bytes. At the start of each row, print the address of the 
  initial byte.
  Note: The addresses may vary.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mem_dump(void *str, size_t size, int len);

int main()
{
    char *text = "I love to break free";
    mem_dump(text, strlen(text) + 1, 5);

    printf("\n\n");
    
    int array[] = {7, 3, 2, 10, -5};
    size_t size = sizeof (array) / sizeof (int);
    mem_dump(array, size * sizeof (int), 4);


    return (EXIT_SUCCESS);
}

void mem_dump(void *str, size_t size, int len)
{
    unsigned char *strPtr = str;
    int i;
    for (i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("%p    ", &(*(strPtr+i)));
        }
        else if (i % len == 0)
        {
            printf("\n%p    ", &(*(strPtr+i)));
        }

        printf("%02x ", *strPtr);
        strPtr++;
    }
}