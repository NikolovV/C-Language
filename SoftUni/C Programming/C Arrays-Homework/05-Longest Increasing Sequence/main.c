/* 
 Write a program to find all increasing sequences inside an array of integers. 
 The numbers should be entered one at a line. On the first  input  line  
 you will be  given the count  of the numbers. Print the sequences  
 in the order of their appearance  in  the  input  array,  
 each  at  a  single  line.  Separate  the  sequence  elements  by  a  space. 
 Find  also  the longest increasing sequence and print it at the last line. 
 If several sequences have the same longest length, print the left-most of them. 
 */

#include <stdio.h>
#include <stdlib.h>

void check_intInput(int *a);
void fill_array(int str[], int size);
void increasing_sequences(int str[], int size);

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
    
    increasing_sequences(buffer, n);

    return (EXIT_SUCCESS);
}

void increasing_sequences(int str[], int size)
{
    int i, j;
    int startIndex = 0, endIndex = 0;
    int bestEnd = 1, bestCount = 0;
    printf("\n");
    
    for (i = 1; i <= size; i++)
    {
        int count = 0;
        if (str[i] > str[i - 1])
        {
            endIndex++;
        }
        else
        {
            for (j = startIndex; j <= endIndex; j++)
            {
                printf("%d ", str[j]);
            }
            
            printf("\n");
            endIndex++;
            count = endIndex - startIndex;
            startIndex = endIndex;            
        }
        
        if (i == size)
        {
            for (j = startIndex; j < endIndex; j++)
            {
                printf("%d ", str[j]);
            }
            
            count = endIndex - startIndex;
        }
        
        if (bestCount < count)
        {
            bestCount = count;
            bestEnd = endIndex;
        }
    }
    
    printf("\nLongest: ");
    for (i = bestEnd - bestCount; i < bestEnd; i++)
    {
        printf("%d ", str[i]);
    }
    
    printf("\n");    
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