#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 64
#define COMMAND_SIZE 65
#define COMMAND_DELIMITER "-"

typedef struct StringBuilder
{
    char *buffer;
    size_t length;
    size_t size;
} StringBuilder;

size_t remove_new_line(char *str);
void resize(StringBuilder *strBuilder, size_t size);
void error(const char *msg);

void prepare_builder(StringBuilder *strBuilder);
void start_build(StringBuilder *strBuilder, char *src);
void concat(StringBuilder *strBuilder, char *src);
void insert(StringBuilder *strBuilder, const char *src, size_t position);
void replace(StringBuilder *strBuilder, const char *oldValue, const char *newValue);

int main()
{
    StringBuilder sb;
    prepare_builder(&sb);

    char buffer[COMMAND_SIZE] = {0};

    start_build(&sb, buffer);

    printf("%s\n", sb.buffer);

    free(sb.buffer);

    return (EXIT_SUCCESS);
}

void prepare_builder(StringBuilder *strBuilder)
{
    strBuilder->buffer = (char*) calloc(BUFFER_SIZE, sizeof (char));
    strBuilder->length = 0;
    strBuilder->size = BUFFER_SIZE;
}

void start_build(StringBuilder *strBuilder, char *src)
{
    while (1)
    {
        fgets(src, COMMAND_SIZE, stdin);
        remove_new_line(src);

        if (strcmp(src, "over") == 0)
        {
            break;
        }

        char *command = strtok(src, COMMAND_DELIMITER);
        char *string = strtok(NULL, COMMAND_DELIMITER);

        if (strcmp(command, "concat") == 0)
        {
            concat(strBuilder, string);
        }
        else if (strcmp(command, "insert") == 0)
        {
            size_t position = atol(strtok(NULL, COMMAND_DELIMITER));
            insert(strBuilder, string, position);
        }
        else
        {
            char *replaceCmd = strtok(NULL, COMMAND_DELIMITER);
            replace(strBuilder, string, replaceCmd);
        }
    }
}

void concat(StringBuilder *strBuilder, char *src)
{
    size_t sourceLenght = strlen(src);
    size_t concatSize = strBuilder->length + sourceLenght;

    if (concatSize > strBuilder->size - 1)
    {
        resize(strBuilder, strBuilder->size * 2);
    }
    strcat(strBuilder->buffer, src);
    strBuilder->length += sourceLenght;
    strBuilder->buffer[strBuilder->length] = '\0';
}

void insert(StringBuilder *strBuilder, const char *src, size_t position)
{
    size_t sourceLenght = strlen(src);
    size_t insertLength = strBuilder->length + sourceLenght;
    if (insertLength >= strBuilder->size - 1)
    {
        resize(strBuilder, strBuilder->size * 2);
    }

    char *insertPtr = strBuilder->buffer + position;
    char *movePtr = strBuilder->buffer + position + sourceLenght;

    memmove(movePtr, insertPtr, strBuilder->length - position);
    memcpy(insertPtr, src, sourceLenght);

    strBuilder->length += sourceLenght;
    strBuilder->buffer[strBuilder->length] = '\0';
}

void replace(StringBuilder *strBuilder, const char *oldValue, const char *newValue)
{
    size_t oldLength = strlen(oldValue);
    size_t newLength = strlen(newValue);

    char *match,
            *startPtr = strBuilder->buffer;
    while (match = strstr(startPtr, oldValue))
    {
        if (newLength - oldLength + strBuilder->length >= strBuilder->size - 1)
        {
            resize(strBuilder, strBuilder->size * 2);
        }

        size_t charactersToMove = strBuilder->length -
                (match - strBuilder->buffer) - oldLength;

        char *destMovePtr = match + newLength;
        char *srcMovePtr = match + oldLength;
        memmove(destMovePtr, srcMovePtr, charactersToMove);
        memcpy(match, newValue, newLength);

        strBuilder->length += newLength - oldLength;
        startPtr = destMovePtr;
        strBuilder->buffer[strBuilder->length] = '\0';
    }
}

void resize(StringBuilder *strBuilder, size_t size)
{
    char *resized = (char*) realloc(strBuilder->buffer, size);
    if (!resized)
    {
        error("Not enough memory!");
    }

    strBuilder->buffer = resized;
    strBuilder->size = size;
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght;
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