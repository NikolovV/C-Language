#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t nth_position(uint64_t num, uint16_t position);

int main()
{
    uint64_t number;
    
    int countOfSieves;
    #ifdef _WIN32
        scanf("%llu %d", &number, &countOfSieves);
    #else
        scanf("%lu %d", &number, &countOfSieves);
    #endif

    int i;
    for (i = 0; i < countOfSieves; i++)
    {
        uint64_t currentSieve;
        #ifdef _WIN32
                scanf("%llu", &currentSieve);
        #else
                scanf("%lu", &currentSieve);
        #endif

        number ^= currentSieve;
        number &= ~currentSieve;
    }

    int onesCounter = 0;
    for (i = 0; i < sizeof (uint64_t) * 8; i++)
    {
        if (nth_position(number, i) == 1)
        {
            onesCounter++;
        }
    }

    printf("%d", onesCounter);

    return (EXIT_SUCCESS);
}

uint64_t nth_position(uint64_t num, uint16_t position)
{
    return ((num >> position) & (uint64_t) 1);
}