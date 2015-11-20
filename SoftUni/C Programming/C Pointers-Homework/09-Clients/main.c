/* 
 Declare a struct called Client with the following members: name, age and 
  account balance. More on structures:
  http://www.tutorialspoint.com/cprogramming/c_structures.htm
  Write a function that sorts an array of clients using a specific comparator. 
  The comparator should be another function that determines how the clients 
  are sorted. Write comparators for sorting the clients by name, age and
  account balance.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER 20
#define HEDER ("|       name       | age |     balance     |\n")

typedef struct
{
    char name[BUFFER];
    unsigned short age;
    long double accountBalance;

} Client;

void sort_clients(Client *clients, int clientCount,
                  int (*comparator)(Client *a, Client *b));
int name_compare(Client *a, Client *b);
int age_compare(Client *a, Client *b);
int account_compare(Client *a, Client *b);
void print_client(Client *a, size_t size);
int compare_doubles(double a, double b);
void swap_client(Client *a, Client *b);

int main()
{
    Client client[] = {
        {"Ana", 50, 2353.81},           
        {"Marilyn Manson", 46, 2354.78},
        {"Ton Roosendaal", 55, 4418.00},
        {"Guts", 32, 230.30},
        {"Vash", 131, 1200000.00},
        {"Finn", 16, 3404.40},
        {"Jake", 34, 6595.63},
    };
    
    int numberOfClients = sizeof (client) / sizeof (client[0]);
    
    printf("Unsorted: \n");
    print_client(client, numberOfClients);
    
    printf("Sort by name\n");
    sort_clients(client, numberOfClients, &name_compare);
    print_client(client, numberOfClients);
    
    printf("Sort by age\n");
    sort_clients(client, numberOfClients, &age_compare);
    print_client(client, numberOfClients);
    
    printf("Sort by balance\n");
    sort_clients(client, numberOfClients, &account_compare);
    print_client(client, numberOfClients);
    
    return (EXIT_SUCCESS);
}

void sort_clients(Client *clients, int clientCount,
                  int (*comparator)(Client *a, Client *b))
{
    int hasSwaped = 1;
    while (hasSwaped)
    {
        hasSwaped = 0;
        int i;
        for (i = 0; i < clientCount - 1; i++)
        {
            if (comparator(&clients[i], &clients[i + 1]))
            {
                swap_client(&clients[i], &clients[i + 1]);
                hasSwaped = 1;
            }
        }
    }
}

int name_compare(Client *a, Client *b)
{
    int result = strcmp(a->name, b->name);
    if (result >= 0)
    {
        return 1;
    }

    return 0;
}

int age_compare(Client *a, Client *b)
{
    return a->age > b->age;
}

int account_compare(Client *a, Client *b)
{
    int bigger = compare_doubles(a->accountBalance, b->accountBalance);
    return bigger;
}

void print_client(Client *a, size_t size)
{
    printf("+------------------+-----+-----------------+\n");
    printf(HEDER);
    printf("+------------------+-----+-----------------+\n");

    int i;
    for (i = 0; i < size; i++)
    {
        printf("| %16s | %3d | %15.2Lf |\n",
               (a + i)->name, (a + i)->age, (a + i)->accountBalance);
    }

    printf("+------------------+-----+-----------------+\n");
}

int compare_doubles(double a, double b)
{
    double eps = 0.0001;

    double diff = (a - b);
    if (a > b)
    {
        return 1;
    }
    else if (diff >= eps)
    {
        return 1;
    }
    
    return 0;
}

void swap_client(Client *a, Client *b)
{
    Client temp = *a;
    *a = *b;
    *b = temp;
}