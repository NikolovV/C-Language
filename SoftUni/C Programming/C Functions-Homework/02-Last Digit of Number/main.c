/* 
 Write a function that returns the last digit of a given integer 
 as an English word. Test the function with different input values. 
 Ensure you name the function properly.
 */

#include <stdio.h>
#include <stdlib.h>

void checkIntInput(int *);
char *last_digit_to_word(int);

int main()
{
    int number;

    printf("Enter number: ");
    checkIntInput(&number);

    char *lastDigitAsWord = last_digit_to_word(number);
    
    printf("%s", lastDigitAsWord);

    return (EXIT_SUCCESS);
}

void checkIntInput(int *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

char *last_digit_to_word(int num)
{
    char *words[] = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    int lastDigit;
    lastDigit = num % 10;
    
    return (words[lastDigit]);
}