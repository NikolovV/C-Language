
#include "Slicing_File.h"

void set_file_part_name(char *str, size_t curentPart, const char *directory)
{
    size_t lenDestPath = strlen(directory);

    if (directory[lenDestPath - 1] != '/')
    {
        sprintf(str, "%s/Part-%d.jpg", directory, curentPart + 1);
    }
    else
    {
        sprintf(str, "%sPart-%d.jpg", directory, curentPart + 1);
    }
}

void set_names(char *str[], size_t size, const char *directory)
{
    size_t fileNameLenght = 15;
    size_t i;
    for (i = 0; i < size; i++)
    {
        size_t lenDestPath = strlen(directory);
        str[i] = calloc(lenDestPath + fileNameLenght, sizeof (char));
        if (!str[i])
        {
            error("Not enough memory!");
        }
        set_file_part_name(str[i], i, directory);
    }
}

void free_array(char *str[], size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        free(str[i]);
    }
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

void slice(const char *sourceFile, const char *destinationDirectory, size_t parts)
{
    FILE *source = fopen(sourceFile, "r");
    if (!sourceFile)
    {
        error("Can't open file");
    }

    fseek(source, 0, SEEK_END);
    long long sourceFileSize = ftell(source);
    fseek(source, 0, SEEK_SET);

    long long partSize = sourceFileSize / parts;

    char buffer[READ_BUFFER];
    size_t i;
    for (i = 0; i < parts; i++)
    {
        char partName[NAME_BUFFER];
        set_file_part_name(partName, i, destinationDirectory);

        FILE *currentDestFile = fopen(partName, "w");
        if (!currentDestFile)
        {
            error("Could not create a part");
        }

        size_t writtenBytes = 0;
        while (writtenBytes <= partSize && !feof(source))
        {
            size_t readBytes = fread(buffer, 1, READ_BUFFER, source);
            fwrite(buffer, 1, readBytes, currentDestFile);
            writtenBytes += readBytes;
        }

        fclose(currentDestFile);
    }
    fclose(source);
}

void assemble(char **partsName, const char *destinationDirectory)
{
    char buffer[READ_BUFFER];

    char resultFileName[NAME_BUFFER];
    size_t len = strlen(destinationDirectory);
    if (destinationDirectory[len - 1] != '/')
    {
        sprintf(resultFileName, "%s/Asebled.jpg", destinationDirectory);
    }
    else
    {
        sprintf(resultFileName, "%sAsebled.jpg", destinationDirectory);
    }

    FILE *result = fopen(resultFileName, "w");
    if (!result)
    {
        error("Can't create file");
    }

    int i;
    for (i = 0; i < parts_global; i++)
    {
        FILE *curentFile = fopen(partsName[i], "r");
        if (!curentFile)
        {
            error(partsName[i]);
        }

        while (!feof(curentFile))
        {
            size_t readBytes = fread(buffer, 1, READ_BUFFER, curentFile);
            fwrite(buffer, 1, readBytes, result);
        }
        fclose(curentFile);
    }
    fclose(result);
}
