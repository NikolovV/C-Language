#include <stdio.h>
#include <stdlib.h>

char * line_reading(void);

int main()
{
    char *line;
    line = line_reading();
    printf("%s", line);

    free(line);
    
    return 0;
}

char * line_reading(void)
{
    char * line = malloc(16), * linep = line;
    size_t lenmax = 16, len = lenmax;
    int c;

    if (line == NULL)
        return NULL;

    for (;;)
    {
        c = fgetc(stdin);
        if (c == EOF)
            break;

        if (--len == 0)
        {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if (linen == NULL)
            {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if ((*line++ = c) == '\n')
            break;
    }
    *line = '\0';  
    
    return linep;
}