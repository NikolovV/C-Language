/* 
 Write a program that extractsfrom a given text all palindromes,  
 e.g. ABBA, lamal, exe and prints them on the console on a single line,
 separated by comma and space. Use spaces, commas, dots, question marks and 
 exclamation marks as word delimiters. Print only unique palindromes, 
 sorted lexicographically. String comparison should be case-sensitive 
 as shown in the example below.
 */

#include "Palindromes.h"

int main()
{
    printf("Enter text:\n");
    char *line = line_reading(BUFFER);

    int paliandromesWords = 0;
    int wordCount = word_count(line, &paliandromesWords);

    char **paliandromes = extract_palindrom(line, paliandromesWords);

    if (paliandromes)
    {
        bubble_sort(paliandromes, paliandromesWords);
        print_array(paliandromes, paliandromesWords);
        free_array(paliandromes, paliandromesWords);
    }

    free(line);

    return (EXIT_SUCCESS);
}