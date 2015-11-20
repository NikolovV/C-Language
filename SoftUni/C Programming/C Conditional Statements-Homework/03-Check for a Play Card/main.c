/* 
 Classical play cards use the following signs to designate the card face:
 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K and A. Write a program that enters 
 a string and prints “yes” if it is a valid card sign or “no” otherwise.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 16

int main()
{
    char card[BUFFER];
    int inputBuff;

    printf("Enter card: ");
    fgets(card, BUFFER, stdin);

    if (card[0] == '1' && card[1] == '0')
    {
        printf("yes");
    }
    else if (card[1] != '\n')
    {
        printf("no");
    }
    else if ((card[0] >= '2') && (card[0] <= '9'))
    {
        printf("yes");
    }
    else
    {
        switch (card[0])
        {
        case 'J':
        case 'Q':
        case 'K':
        case 'A':
            printf("Yes");
            break;
        default:
            printf("No");
        }
    }

    return (EXIT_SUCCESS);
}