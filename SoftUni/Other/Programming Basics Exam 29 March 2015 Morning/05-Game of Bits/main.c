#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <strings.h>

#define BUFFER 12
#define BIT_SIZE 32

void set_bit(uint32_t *number, uint16_t position, bool bit_value);
bool nth_position(uint32_t num, int position);
size_t remove_new_line(char *str);
uint32_t begin_game(uint32_t number);
uint32_t extrakt_odd_bits(uint32_t number);
uint32_t extrakt_even_bits(uint32_t number);
int count_onece_bits(uint32_t number);

int main()
{
    uint32_t inputNumber;
    scanf("%u%*c", &inputNumber);

    uint32_t resultNumber;
    resultNumber = begin_game(inputNumber);
    int onceCount = count_onece_bits(resultNumber);

    printf("%u -> %d", resultNumber, onceCount);

    return (0);
}

int count_onece_bits(uint32_t number)
{
    int onceCounter = 0;
    int i;
    for (i = 0; i < BIT_SIZE; i++)
    {
        if (nth_position(number, i) == 1)
        {
            onceCounter++;
        }
    }

    return onceCounter;
}

uint32_t extrakt_odd_bits(uint32_t number)
{
    int i, oddBitPos = 0;
    uint32_t oddBitExtrakted = 0;
    for (i = 0; i < BIT_SIZE; i++)
    {
        if (i % 2 == 0)
        {
            bool currentBit = nth_position(number, i);
            if (currentBit)
            {
                set_bit(&oddBitExtrakted, oddBitPos, currentBit);
            }
            oddBitPos++;
        }
    }
    return oddBitExtrakted;
}

uint32_t extrakt_even_bits(uint32_t number)
{
    int i, evenBitPos = 0;
    uint32_t evenBitExtrakted = 0;
    for (i = 0; i < BIT_SIZE; i++)
    {
        if (!(i % 2 == 0))
        {
            bool currentBit = nth_position(number, i);
            if (currentBit)
            {
                set_bit(&evenBitExtrakted, evenBitPos, currentBit);
            }
            evenBitPos++;
        }
    }
    return evenBitExtrakted;
}

uint32_t begin_game(uint32_t number)
{
    uint32_t newNumber = 0;

    char commands[BUFFER];
    fgets(commands, BUFFER, stdin);
    remove_new_line(commands);
    
    if (strcmp(commands, "Game Over!") == 0)
    {
        return number;
    }

    while (strcmp(commands, "Game Over!") != 0)
    {
        if (strcmp(commands, "Odd") == 0)
        {
            newNumber = extrakt_odd_bits(number);
        }
        else
        {
           newNumber = extrakt_even_bits(number);
        }

        number = newNumber;
        fgets(commands, BUFFER, stdin);
        remove_new_line(commands);
    }

    return newNumber;
}

bool nth_position(uint32_t num, int position)
{
    return ((num >> position) & 1U);
}

void set_bit(uint32_t *number, uint16_t position, bool bit_value)
{
    if (bit_value == 1)
    {
        *number |= (bit_value << position);
    }
    else
    {
        *number &= (~(1U << position));
    }
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght - 1;
}