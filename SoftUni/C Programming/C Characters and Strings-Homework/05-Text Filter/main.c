/* 
 Write  a  program that  takes  a text and  a string  of  banned words.  
 All  words  included  in  the  ban  list  should  be replaced with asterisks
"*", equal to the word's length. The entries in the ban list will be 
 separated by a comma and space", ".
 The ban list should be entered on the first input line and the text on the
 second input line. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER  200

char *line_reading(size_t lenght);
void text_filter(char *source, char *banList);

int main()
{
    
    printf("Enter ban words\n");
    char *bannedWords = line_reading(BUFFER);
    
    printf("Enter text\n");
    char *text = line_reading(BUFFER);

    text_filter(text, bannedWords);

    printf("%s", text);

    free(bannedWords);
    free(text);

    return (EXIT_SUCCESS);
}

void text_filter(char *source, char *banList)
{

    char *token = strtok(banList, ", ");
    while (token)
    {
        size_t token_length = strlen(token);
        char *substr = strstr(source, token);

        while (substr)
        {
            int index = substr - source;
            memset(&source[index], '*', token_length);
            substr = strstr(&(*(substr + 1)), token);
        }

        token = strtok(NULL, ", ");
    }
}

char *line_reading(size_t lenght)
{
    char *lineRead = malloc(8 * sizeof (char));
    char *linePtr = lineRead;
    size_t lenMax = 8, len = lenMax - 1;
    int c = 0;

    if (!lineRead)
    {
        return NULL;
    }

    while (c != EOF)
    {
        c = fgetc(stdin);
        if (c == '\n')
        {
            break;
        }
        else if (len > lenght)
        {
            break;
        }

        if (--len == 0)
        {
            len = lenMax;
            char* reallocated_line = (char*) realloc(lineRead, lenMax *= 2);

            if (!reallocated_line)
            {
                free(lineRead);
                return NULL;
            }

            linePtr = reallocated_line + (linePtr - lineRead);
            lineRead = reallocated_line;
        }

        *linePtr++ = c;
    }

    *linePtr = '\0';

    return lineRead;
}