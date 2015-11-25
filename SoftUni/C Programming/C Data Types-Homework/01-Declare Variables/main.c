/*
 Declare five variables choosing for each of them the most appropriate of the types 
char, short, unsigned short, int, unsigned int, long, unsigned long
to represent the following values: 52130, 8942492113, -115, 4825932, 97, -10000, 
-35982859328592389.Choose a large enough type for each number to ensure it will 
fit in it. 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    unsigned short first = 52130;
    long long second = 8942492113;
    char third = -115;
    int fourth = 4825932;
    char fifth = 97;
    int sixth = -10000;
    unsigned long long seventh = -35982859328592389; 

    return (EXIT_SUCCESS);
}

