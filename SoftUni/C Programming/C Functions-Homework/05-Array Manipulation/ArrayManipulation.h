#ifndef ARRAYMANIPULATION_H
#define	ARRAYMANIPULATION_H

#define BUFFER 20
#include <stdbool.h>

#define LENGHT_ARRAY(array) (sizeof(array)/sizeof((array)[0]))

int get_min(const int* str, int lenght);
int get_max(const int* str, int lenght);
void arr_clear(int* str, int lenght);
double get_avg(const int* str, int lenght);
int get_sum(const int* str, int lenght);
bool arr_contains(int* str, int n, int specificElement);
int* arr_merge(int* str_1, int* str_2, int lenghtArr_1, int lenghtArr_2);

int get_lenght(const int str[]);

#endif	/* ARRAYMANIPULATION_H */

