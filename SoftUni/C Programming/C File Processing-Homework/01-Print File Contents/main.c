/* 
 Write a program that reads a text file and prints its contents on the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define READ_BUFFER  64

void error(const char *msg);
void print_file_content(const char *filename);
void closeFile(FILE *filePtr);

int main()
{
    const char *pathToFile = "sample_text.txt";

    print_file_content(pathToFile);

    return (EXIT_SUCCESS);
}

void print_file_content(const char *filename)
{
    FILE *filePtr = fopen(filename, "r");
    if (!filePtr) error("Can't open file!");

    char bufer[READ_BUFFER + 1];
    while (!feof(filePtr))
    {
        size_t readedBytes = fread(bufer, 1, READ_BUFFER, filePtr);
        bufer[readedBytes] = '\0';
        fprintf(stdout, "%s", bufer);
    }
    closeFile(filePtr);
}

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void closeFile(FILE *filePtr)
{
    if (fclose(filePtr) == EOF)
    {
        error("Error closing file!");
    }
}