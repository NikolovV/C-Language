/* 
 Write a program that reads a number n and prints on the console the first 
 n members of the Fibonacci sequence (at a single line, separated by spaces) 
 */

#include <stdio.h>
#include <stdlib.h>

void checkInput(int *);

int main()

{
    int n, first = 0, second = 1, next, ctr;
 
   printf("Enter the number of terms: ");
   checkInput(&n);
   
   for ( ctr = 0 ; ctr < n ; ctr++)
   {
      if ( ctr <= 1 )
         next = ctr;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      printf("%d ", next);
   }

    return (EXIT_SUCCESS);
}

void checkInput(int *N)
{
    if ((scanf("%d", N)) != 1)
    {
        fprintf(stderr, "Wrong input values!");
        exit(EXIT_FAILURE);
    }
}