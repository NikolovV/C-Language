/* 
 Write a program that copies the contents of a binary file (e.g. image, video,
 etc.) to another file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define READ_BUFFER 256

void error(const char *msg);

int main()
{
    char *srcFileName = "Nature-HD-Wallpapers.jpg";
    char *destFileName = "Copy_of_Nature-HD-Wallpapers.jpg";
    
    FILE *srcFile = fopen(srcFileName, "r");
    if (!srcFile)
    {
        error(srcFileName);
    }
    FILE *dest = fopen(destFileName, "w");
    if (!dest)
    {
        error(destFileName);
    }
    
    char buffer[READ_BUFFER];
    size_t byteRead;
    
    while (!feof(srcFile) )
    {
        byteRead = fread(buffer, 1, READ_BUFFER, srcFile);
        fwrite(buffer, 1, byteRead, dest);
    }
    printf("Done...");

    fclose(srcFile);
    fclose(dest);

    return (EXIT_SUCCESS);
}

void error(const char *msg)
{
    if (errno)
    {
        perror(msg);
    }
    else
    {
        fprintf(stderr, "ERROR: %s", msg);
    }

    exit(1);
}