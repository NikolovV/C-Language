
#ifndef SLICING_FILE_H
#define	SLICING_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define READ_BUFFER 4096
#define NAME_BUFFER 100

void free_array(char *str[], size_t size);
void error(const char *msg);
void set_file_part_name(char *str, size_t curentPart, const char *directory);
void set_names(char *str[], size_t size, const char *directory);
void slice(const char *sourceFile, const char *destinationDirectory, size_t parts);
void assemble(char **partsName, const char *destinationDirectory);

size_t parts_global;

#endif	/* SLICING_FILE_H */

