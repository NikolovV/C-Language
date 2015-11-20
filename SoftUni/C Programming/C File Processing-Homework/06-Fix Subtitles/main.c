/* 
 Write a program that takes as arguments input subtitles file and offset in
 milliseconds. The program should edit the subtitles' timing by the given offset. 
 The subtitles will contains will be in the format specified below.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

typedef struct
{
    int hours;
    int minutes;
    int seconds;
    int milliseconds;
} Times;

void error(const char *msg);
ssize_t read_line(char **bufferPtr, size_t *bufSize, FILE *stream);
long set_to_subtitle_timnig(char **buf, size_t *bufSize, FILE *stream);
void add_delay(Times *curentSet, char *time, int offset);

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        error("Usage: ./program [sourceFile] [subtitleOffset]\n");
    }

    char *subtitleFileName = argv[1];
    size_t subtitleOfcet = atoi(argv[2]);
    
    if (subtitleOfcet == 0)
    {
        error("There is nothing to change!");
    }

    FILE *subtitleFile = fopen(subtitleFileName, "r+");
    if (!subtitleFile)
    {
        error(subtitleFileName);
    }

    size_t readBytes = 0;
    char *buffer = NULL;
    size_t bufferSize = 0;

    while (!feof(subtitleFile) || !ferror(subtitleFile))
    {
        long fileIndex = set_to_subtitle_timnig(&buffer, &bufferSize, subtitleFile);
        if (fileIndex == EOF)
        {
            break;
        }

        readBytes = read_line(&buffer, &bufferSize, subtitleFile);

        char temp[readBytes];
        strcpy(temp, buffer);

        char *firstTime = strtok(temp, " --> ");
        char *secondTime = strtok(NULL, " --> ");

        Times first, second;

        add_delay(&first, firstTime, subtitleOfcet);
        add_delay(&second, secondTime, subtitleOfcet);

        sprintf(temp, "%02d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d\n",
                first.hours, first.minutes,
                first.seconds, first.milliseconds,
                second.hours, second.minutes,
                second.seconds, second.milliseconds);

        strncpy(buffer, temp, readBytes);

        fseek(subtitleFile, fileIndex, SEEK_SET);
        fwrite(buffer, 1, readBytes, subtitleFile);
    }

    fclose(subtitleFile);
    free(buffer);


    return (EXIT_SUCCESS);
}

void add_delay(Times *curentSet, char *time, int offset)
{
    int hours = offset / 10000000;
    int minutes = ((offset / 100000) % 100) % 60;
    int seconds = ((offset / 1000) % 1000) % 60;
    int milliseconds = offset % 1000;

    char *current = strtok(time, " :,");

    curentSet->hours = atoi(current) + hours;
    curentSet->minutes = atoi(strtok(NULL, " :,")) + minutes;
    curentSet->seconds = atoi(strtok(NULL, " :,")) + seconds;
    curentSet->milliseconds = atoi(strtok(NULL, " :,")) + milliseconds;

    curentSet->hours += curentSet->minutes / 60;
    curentSet->minutes %= 60;
    curentSet->minutes += curentSet->seconds / 60;
    curentSet->seconds %= 60;
    curentSet->seconds += curentSet->milliseconds / 1000;
    curentSet->milliseconds %= 1000;
}

long set_to_subtitle_timnig(char **buf, size_t *bufSize, FILE *stream)
{
    long fileIndex = 0;
    long lineNumber = 0;
    char *remainder = NULL;
    ssize_t redByte;

    while (!feof(stream))
    {
        redByte = read_line(buf, bufSize, stream);
        lineNumber = strtol(*buf, &remainder, 10);
        if (remainder == *buf)
        {
            continue;
        }
        if (lineNumber > 0);
        {
            if (remainder[0] == ':' || remainder[0] != '\0')
            {
                break;
            }
        }
    }

    if (feof(stream))
    {
        return EOF;
    }
    
    fseek(stream, -(redByte+1), SEEK_CUR);
    fileIndex = ftell(stream);

    return fileIndex;
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

ssize_t read_line(char **bufferPtr, size_t *bufSize, FILE *stream)
{
    char *buffer = *bufferPtr;
    size_t size = *bufSize;

    if (buffer == NULL)
    {
        buffer = malloc(64);
        size = 64;
        if (!buffer) return 0;
    }

    size_t i = 0;
    char c = fgetc(stream);
    while (!feof(stream))
    {
        if (i == size - 1)
        {
            char *resized = realloc(buffer, 2 * size);
            if (!resized)
            {
                return 0;
            }

            buffer = resized;
            size *= 2;
        }

        if (c == '\n')
        {
            buffer[i] = '\0';
            *bufferPtr = buffer;
            *bufSize = size;

            return i;
        }

        buffer[i] = c;
        i++;

        c = fgetc(stream);
    }

    buffer[i] = '\0';
    *bufferPtr = buffer;
    *bufSize = size;

    return -1;
}