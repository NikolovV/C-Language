/* 
 Write a program that converts a number in the range [0...999] to words, 
 corresponding to the English pronunciation. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void check_intInput(uint *a);
void number_as_word(uint num);

int main()
{
    uint number;
    check_intInput(&number);

    if (number == 0)
    {
        printf("Zero");
        exit(EXIT_SUCCESS);
    }
    else if (number < 0 || number > 999)
    {
        printf("Incorrect input.");
        exit(EXIT_FAILURE);
    }

    number_as_word(number);

    return (EXIT_SUCCESS);
}

void check_intInput(uint *a)
{
    if ((scanf("%d", a)) != 1)
    {
        printf("Not digit!");
        exit(EXIT_FAILURE);
    }
}

void number_as_word(uint num)
{
    char *ones[] = {"one", "two", "three", "four", "five", "six", "seven",
        "eight", "nine"};
    char *onesToUpper[] = {"One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine"};
    char *tenToNineteen[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy",
        "eighty", "ninety"};
    char *hundreds[] = {"One hundred", "Two hundred", "Three hundred",
        "Four hundred", "Five hundred", "Six hundred", "Seven hundred",
        "Eight hundred", "Nine hundred"};

    int hundredsDigit = num / 100;
    int tensDigit = (num / 10) % 10;
    int onesDigit = num % 10;

    if (hundredsDigit)
    {
        printf("%s ", hundreds[hundredsDigit - 1]);
        if (tensDigit != 0 || onesDigit != 0)
        {
            printf("and ");
        }
    }
    
    if (tensDigit)
    {
        if (hundredsDigit > 0 && tensDigit == 1 && onesDigit > 0)
        {
            char c = tolower(tenToNineteen[onesDigit][0]);
            printf("%c%s ", c, (tenToNineteen[onesDigit] + 1));
            return;
        }
        else if (tensDigit == 1 && onesDigit == 0)
        {
            printf("%s", tenToNineteen[0]);
            return;
        }
        else if (tensDigit == 1 && onesDigit > 0)
        {
            printf("%s ", tenToNineteen[onesDigit]);
            return;
        }
        else if (tensDigit > 1 && hundredsDigit == 0)
        {
            char c = toupper(tens[tensDigit - 2][0]);
            printf("%c%s ", c, (tens[tensDigit - 2] + 1));
        }
        else if (tensDigit > 1)
        {
            printf("%s ", tens[tensDigit - 2]);
        }
    }

    if (onesDigit && (hundredsDigit == 0 && tensDigit == 0))
    {
        printf("%s", onesToUpper[onesDigit - 1]);
    }
    else if (onesDigit)
    {
        printf("%s", ones[onesDigit - 1]);
    }
}