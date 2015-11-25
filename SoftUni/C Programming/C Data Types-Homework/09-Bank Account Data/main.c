/* 
 A bank account has a holder name(first name, middle name and last name), available 
 amount of money(balance), bank name, IBAN and 3 credit card numbers
 associated with the account.
 */

#include <stdio.h>
#include <stdlib.h>

#define STR_LENGHT 22
#define IBAN_LENGHT 28
#define CARD_LENGHT 20

typedef struct bancAccount
{
    char bankName[STR_LENGHT];
    char firstName[STR_LENGHT];
    char middleName[STR_LENGHT];
    char lastName[STR_LENGHT];
    double balance;
    char IBAN[IBAN_LENGHT];
    char creditCard_1[CARD_LENGHT];
    char creditCard_2[CARD_LENGHT];
    char creditCard_3[CARD_LENGHT];
} bancAccount;

int main(int argc, char** argv)
{
    bancAccount customer_1 = {  "Corporate Trade Bank",
                                "Ivan",
                                "Petkov",
                                "Popov",
                                123456.12345,
                                "BG80 BNBG 1234 5678 9123 45",
                                "1234 1234 1234 1234",
                                "1234 1234 1234 5678",
                                "1234 1234 5678 1234"
                            };
    
    printf("Inforamtion about customer...\n");
    printf("=====================================\n");
    printf("Bank name: %s\n", customer_1.bankName);
    printf("First name: %s\n", customer_1.firstName);
    printf("Midle name: %s\n", customer_1.middleName);
    printf("Last name: %s\n", customer_1.lastName);
    printf("Balance: %f\n", customer_1.balance);
    printf("IBAN: %s\n", customer_1.IBAN);
    printf("creditCard_1: %s\n", customer_1.creditCard_1);
    printf("creditCard_2: %s\n", customer_1.creditCard_2);
    printf("creditCard_3: %s\n", customer_1.creditCard_3);

    return (EXIT_SUCCESS);
}

