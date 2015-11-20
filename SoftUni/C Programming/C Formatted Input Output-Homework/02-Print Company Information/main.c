/* 
 Write a program that reads the information about a company and its manager 
 and prints it back on the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LENGHT 50

void  removeNewLine(char str[]);


int main()
{
    char companyName[STR_LENGHT],
         companyAddress[STR_LENGHT],
         companyPhoneNumber[STR_LENGHT],
         companyFaxNumber[STR_LENGHT],
         companyWebSite[STR_LENGHT],
         managerFirstName[STR_LENGHT],
         managerLastName[STR_LENGHT],
         managerAge[STR_LENGHT],
         managerPhoneNumber[STR_LENGHT];
    
    printf("Enter the following information:\n");
    
    printf("Company name: ");
    fgets(companyName, STR_LENGHT, stdin);
    
    printf("Company address: ");
    fgets(companyAddress, STR_LENGHT, stdin);
    
    printf("Phone number: ");
    fgets(companyPhoneNumber, STR_LENGHT, stdin);
    
    printf("Fax number: ");
    fgets(companyFaxNumber, STR_LENGHT, stdin);
    removeNewLine(companyFaxNumber);

    printf("Web site: ");
    fgets(companyWebSite, STR_LENGHT, stdin);
    
    printf("Manager first name: ");
    fgets(managerFirstName, STR_LENGHT, stdin);
    removeNewLine(managerFirstName);

    printf("Manager last name: ");
    fgets(managerLastName, STR_LENGHT, stdin);
    removeNewLine(managerLastName);

    printf("Manager age: ");
    fgets(managerAge, STR_LENGHT, stdin);
    
    printf("Manager phone: ");
    fgets(managerPhoneNumber, STR_LENGHT, stdin);
    
    printf("\nHere is the infromation:\n\n");
    
    printf("Company name: %s", companyName);
    printf("Company address: %s", companyAddress);
    printf("Phone number: %s", companyPhoneNumber);
    printf("Fax number: %s\n", companyFaxNumber);
    printf("Web site: %s", companyWebSite);
    printf("Manager first name: %s", managerFirstName);
    printf("Manager last name: %s", managerLastName);
    printf("Manager age: %s", managerAge);
    printf("Manager phone: %s", managerPhoneNumber);

    
    return (EXIT_SUCCESS);
}

void  removeNewLine(char str[])
{
    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n')
    {
       str[ln] = '\0';
    }
}