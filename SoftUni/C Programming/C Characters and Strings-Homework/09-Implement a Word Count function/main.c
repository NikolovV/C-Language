/* 
 Implement a function which counts the words in a given input. The function 
 accepts as parameter the input from which to count the words and 
 the delimiter separating the words. The declaration could be as follows:
 int wc(char * input, char delimiter);
 */

#include <stdio.h>
#include <stdlib.h>

int word_count(char *input, char delimiter);

int main()
{
    printf("%d\n", word_count("Hard Rock, Hallelujah!", ' '));
    
    printf("%d\n", word_count("Hard Rock, Hallelujah!", ','));
    
    printf("%d\n", word_count("Uncle Sam wants you Man", ' '));
    
    printf("%d\n", word_count("Beat the beat!", '!'));
    
    return (EXIT_SUCCESS);
}

int word_count(char *input, char delimiter)
{
    size_t count = 1;
    while (*input != '\0')
    {
        if (*input == delimiter)
        {
            count++;
        }
        
        *input++;
    }
    
    return count;
}