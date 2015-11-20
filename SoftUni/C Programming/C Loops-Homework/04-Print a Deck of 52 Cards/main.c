/* 
 Write a program that generates and prints all possible cards from 
 a standard deck of 52 cards(without the jokers). The cards should be printed 
 using the classical notation (like 5S (), AH (), 9C ()and KD ()).
 The card faces should start from 2to A.Print each card face in its 
 four possible suits: clubs, diamonds, hearts and spades. 
 Use 2nested for-loops and a switch-case statement.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int face;
    for (face = 0; face <= 12; face++)
    {
        int suit;
        for (suit = 0; suit <= 3; suit++)
        {
            switch (face)
            {
            case 0:
                printf("2");
                break;
            case 1:
                printf("3");
                break;
            case 2:
                printf("4");
                break;
            case 3:
                printf("5");
                break;
            case 4:
                printf("6");
                break;
            case 5:
                printf("7");
                break;
            case 6:
                printf("8");
                break;
            case 7:
                printf("9");
                break;
            case 8:
                printf("10");
                break;
            case 9:
                printf("J");
                break;
            case 10:
                printf("Q");
                break;
            case 11:
                printf("K");
                break;
            case 12:
                printf("A");
            default:
                break;
            }
            
            switch (suit)
            {
            case 0:
                printf("C ");
                break;
            case 1:
                printf("D ");
                break;
            case 2:
                printf("H ");
                break;
            case 3:
                printf("S ");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}
