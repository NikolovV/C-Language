
#ifndef PALINDROMES_H
#define	PALINDROMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER 200

char *line_reading(size_t lenght);
int is_palindrom(char* str);
char **extract_palindrom(char *line, int palindromWords);
int word_count(const char *str, int *palindromWords);
void free_array(char *str[], size_t size);
void bubble_sort(char *str[], int length);
void print_array(char *str[], size_t size);

#endif	/* PALINDROMES_H */

